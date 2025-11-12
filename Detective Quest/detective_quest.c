#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_HASH 10

typedef struct Sala {
    char nome[50];
    char pista[100];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

typedef struct PistaNode {
    char pista[100];
    struct PistaNode *esquerda;
    struct PistaNode *direita;
} PistaNode;

typedef struct HashNode {
    char pista[100];
    char suspeito[50];
    struct HashNode *prox;
} HashNode;

int hashFunc(char *pista) {
    return (pista[0] % TAM_HASH);
}

Sala* criarSala(char *nome, char *pista) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    strcpy(nova->pista, pista);
    nova->esquerda = nova->direita = NULL;
    return nova;
}

PistaNode* inserirPista(PistaNode *raiz, char *pista) {
    if (raiz == NULL) {
        PistaNode *novo = (PistaNode*) malloc(sizeof(PistaNode));
        strcpy(novo->pista, pista);
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (strcmp(pista, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, pista);
    else if (strcmp(pista, raiz->pista) > 0)
        raiz->direita = inserirPista(raiz->direita, pista);
    return raiz;
}

void exibirPistas(PistaNode *raiz) {
    if (raiz != NULL) {
        exibirPistas(raiz->esquerda);
        printf("- %s\n", raiz->pista);
        exibirPistas(raiz->direita);
    }
}

void inserirNaHash(HashNode *tabela[], char *pista, char *suspeito) {
    int indice = hashFunc(pista);
    HashNode *novo = (HashNode*) malloc(sizeof(HashNode));
    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);
    novo->prox = tabela[indice];
    tabela[indice] = novo;
}

char* encontrarSuspeito(HashNode *tabela[], char *pista) {
    int indice = hashFunc(pista);
    HashNode *atual = tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0)
            return atual->suspeito;
        atual = atual->prox;
    }
    return "Desconhecido";
}

void explorarSalas(Sala *salaAtual, PistaNode **raizPistas, HashNode *tabela[]) {
    char escolha;
    while (salaAtual != NULL) {
        printf("\nVocê está na sala: %s\n", salaAtual->nome);
        if (strlen(salaAtual->pista) > 0) {
            printf("🔍 Pista encontrada: \"%s\"\n", salaAtual->pista);
            *raizPistas = inserirPista(*raizPistas, salaAtual->pista);
            char *sus = encontrarSuspeito(tabela, salaAtual->pista);
            printf("Esta pista pode estar ligada a: %s\n", sus);
        } else {
            printf("Nenhuma pista aqui.\n");
        }
        printf("\nEscolha seu caminho:\n");
        if (salaAtual->esquerda) printf(" (e) Ir para %s à esquerda\n", salaAtual->esquerda->nome);
        if (salaAtual->direita) printf(" (d) Ir para %s à direita\n", salaAtual->direita->nome);
        printf(" (s) Sair e fazer a acusação\n");
        printf("Digite sua escolha: ");
        scanf(" %c", &escolha);
        if (escolha == 'e' && salaAtual->esquerda)
            salaAtual = salaAtual->esquerda;
        else if (escolha == 'd' && salaAtual->direita)
            salaAtual = salaAtual->direita;
        else if (escolha == 's') {
            printf("\nEncerrando exploração...\n");
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }
}

void verificarSuspeitoFinal(PistaNode *raiz, HashNode *tabela[], char *acusado, int *contador) {
    if (raiz != NULL) {
        verificarSuspeitoFinal(raiz->esquerda, tabela, acusado, contador);
        char *sus = encontrarSuspeito(tabela, raiz->pista);
        if (strcmp(sus, acusado) == 0)
            (*contador)++;
        verificarSuspeitoFinal(raiz->direita, tabela, acusado, contador);
    }
}

int main() {
    Sala *hall = criarSala("Hall de Entrada", "Pegadas de lama no tapete");
    Sala *salaEstar = criarSala("Sala de Estar", "Copo quebrado no chão");
    Sala *cozinha = criarSala("Cozinha", "Faca suja na pia");
    Sala *biblioteca = criarSala("Biblioteca", "Livro de venenos aberto");
    Sala *jardim = criarSala("Jardim", "Luvas enterradas na terra");
    Sala *escritorio = criarSala("Escritório", "Carta ameaçadora na mesa");

    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    cozinha->direita = escritorio;

    HashNode *tabela[TAM_HASH] = {NULL};
    inserirNaHash(tabela, "Pegadas de lama no tapete", "Sr. Green");
    inserirNaHash(tabela, "Copo quebrado no chão", "Sra. White");
    inserirNaHash(tabela, "Faca suja na pia", "Sr. Green");
    inserirNaHash(tabela, "Livro de venenos aberto", "Coronel Mustard");
    inserirNaHash(tabela, "Luvas enterradas na terra", "Sra. White");
    inserirNaHash(tabela, "Carta ameaçadora na mesa", "Coronel Mustard");

    PistaNode *raizPistas = NULL;

    printf("🕵️‍♀️ Detective Quest - Julgamento Final 🕵️‍♀️\n");
    printf("Explore a mansão, colete pistas e descubra o culpado!\n");

    explorarSalas(hall, &raizPistas, tabela);

    printf("\n===== PISTAS COLETADAS =====\n");
    exibirPistas(raizPistas);

    char acusado[50];
    printf("\nQuem você acusa? ");
    scanf(" %[^\n]", acusado);

    int contador = 0;
    verificarSuspeitoFinal(raizPistas, tabela, acusado, &contador);

    printf("\n===== RESULTADO =====\n");
    if (contador >= 2)
        printf("✅ Acusação confirmada! %s é o culpado(a), com %d pistas!\n", acusado, contador);
    else
        printf("❌ Acusação inválida. %s tem apenas %d pista(s) associada(s).\n", acusado, contador);

    return 0;
}
