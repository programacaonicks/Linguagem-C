#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\nAtaque de %s (%s, %d tropas) para %s (%s, %d tropas)\n",
           atacante->nome, atacante->cor, atacante->tropas,
           defensor->nome, defensor->cor, defensor->tropas);

    printf("Dado atacante: %d\n", dadoAtacante);
    printf("Dado defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("O atacante venceu!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
    } else {
        printf("O defensor venceu!\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }

    printf("\n--- Territórios após o ataque ---\n");
    printf("%s - Cor: %s, Tropas: %d\n", atacante->nome, atacante->cor, atacante->tropas);
    printf("%s - Cor: %s, Tropas: %d\n", defensor->nome, defensor->cor, defensor->tropas);
}

// Função que atribui uma missão aleatória ao jogador
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
}

int verificarMissao(char* missao, struct Territorio* mapa, int tamanho) {
    if (strstr(missao, "Conquistar") != NULL) {
        int count = 0;
        char corReferencia[10];
        strcpy(corReferencia, mapa[0].cor);

        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corReferencia) == 0)
                count++;
        }

        if (count >= 3)
            return 1; 
    }
    return 0;
}

int main() {
    struct Territorio* territorios;
    int numTerritorios, i;
    int atacanteIdx, defensorIdx;
    char* missaoJogador;

    srand(time(NULL));

    printf("Digite o número de territórios: ");
    scanf("%d", &numTerritorios);
    getchar(); // limpar o '\n' deixado pelo scanf

    territorios = (struct Territorio*) calloc(numTerritorios, sizeof(struct Territorio));
    if (territorios == NULL) {
        printf("Erro ao alocar memória para os territórios.\n");
        return 1;
    }

    printf("\n--- Sistema de Cadastro de Territórios ---\n");

    for (i = 0; i < numTerritorios; i++) {
        printf("\nCadastro do território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        scanf("%29s", territorios[i].nome);

        printf("Digite a cor do exército: ");
        scanf("%9s", territorios[i].cor);

        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    char* missoes[4] = {
        "Conquistar 3 territórios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Ter 5 territórios da mesma cor",
        "Conquistar pelo menos 10 tropas inimigas"
    };

    missaoJogador = (char*) malloc(100 * sizeof(char));
    if (missaoJogador == NULL) {
        printf("Erro ao alocar memória para a missão.\n");
        free(territorios);
        return 1;
    }

    atribuirMissao(missaoJogador, missoes, 4);
    printf("\nMissão do jogador: %s\n", missaoJogador);

    printf("\n--- Territórios Cadastrados ---\n");
    for (i = 0; i < numTerritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
    }

    printf("\nEscolha o território atacante (0 a %d): ", numTerritorios - 1);
    scanf("%d", &atacanteIdx);
    printf("Escolha o território defensor (0 a %d): ", numTerritorios - 1);
    scanf("%d", &defensorIdx);

    if (atacanteIdx < 0 || atacanteIdx >= numTerritorios ||
        defensorIdx < 0 || defensorIdx >= numTerritorios) {
        printf("Índices inválidos.\n");
    } else if (strcmp(territorios[atacanteIdx].cor, territorios[defensorIdx].cor) == 0) {
        printf("Não é possível atacar um território da mesma cor!\n");
    } else {
        atacar(&territorios[atacanteIdx], &territorios[defensorIdx]);
    }

    if (verificarMissao(missaoJogador, territorios, numTerritorios)) {
        printf("\nParabéns! Você cumpriu sua missão!\n");
    } else {
        printf("\nMissão ainda não cumprida.\n");
    }

    free(missaoJogador);
    free(territorios);

    return 0;
}