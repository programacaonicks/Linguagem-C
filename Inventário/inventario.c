#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITENS 10
#define MAX_COMPONENTES 20

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

Item mochilaVetor[MAX_ITENS];
int totalItens = 0;
No* cabeca = NULL;
int comparacoesBusca = 0;

void listarItensVetor() {
    if (totalItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    for (int i = 0; i < totalItens; i++)
        printf("%d - Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
}

void inserirItemVetor() {
    if (totalItens >= MAX_ITENS) return;
    scanf(" %[^\n]", mochilaVetor[totalItens].nome);
    scanf(" %[^\n]", mochilaVetor[totalItens].tipo);
    scanf("%d", &mochilaVetor[totalItens].quantidade);
    totalItens++;
}

void removerItemVetor() {
    char nome[30];
    scanf(" %[^\n]", nome);
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItens - 1; j++)
                mochilaVetor[j] = mochilaVetor[j + 1];
            totalItens--;
            return;
        }
    }
}

void buscarItemVetor() {
    char nome[30];
    scanf(" %[^\n]", nome);
    comparacoesBusca = 0;
    for (int i = 0; i < totalItens; i++) {
        comparacoesBusca++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Encontrado: %s | Comparações: %d\n", mochilaVetor[i].nome, comparacoesBusca);
            return;
        }
    }
    printf("Não encontrado | Comparações: %d\n", comparacoesBusca);
}

void listarItensLista() {
    No* atual = cabeca;
    while (atual) {
        printf("%s | %s | %d\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
    }
}

void inserirItemLista() {
    No* novo = (No*)malloc(sizeof(No));
    scanf(" %[^\n]", novo->dados.nome);
    scanf(" %[^\n]", novo->dados.tipo);
    scanf("%d", &novo->dados.quantidade);
    novo->proximo = cabeca;
    cabeca = novo;
}

void removerItemLista() {
    char nome[30];
    scanf(" %[^\n]", nome);
    No* atual = cabeca;
    No* anterior = NULL;
    while (atual) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) cabeca = atual->proximo;
            else anterior->proximo = atual->proximo;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void buscarItemLista() {
    char nome[30];
    scanf(" %[^\n]", nome);
    comparacoesBusca = 0;
    No* atual = cabeca;
    while (atual) {
        comparacoesBusca++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Encontrado: %s | Comparações: %d\n", atual->dados.nome, comparacoesBusca);
            return;
        }
        atual = atual->proximo;
    }
    printf("Não encontrado | Comparações: %d\n", comparacoesBusca);
}

void mostrarComponentes(Componente c[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d - %s | %s | %d\n", i+1, c[i].nome, c[i].tipo, c[i].prioridade);
}

void bubbleSortNome(Componente c[], int n, int* comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            (*comparacoes)++;
            if (strcmp(c[j].nome, c[j+1].nome) > 0) {
                Componente temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
}

void insertionSortTipo(Componente c[], int n, int* comparacoes) {
    *comparacoes = 0;
    for (int i = 1; i < n; i++) {
        Componente key = c[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparacoes)++;
            if (strcmp(c[j].tipo, key.tipo) > 0) {
                c[j+1] = c[j];
                j--;
            } else break;
        }
        c[j+1] = key;
    }
}

void selectionSortPrioridade(Componente c[], int n, int* comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            (*comparacoes)++;
            if (c[j].prioridade < c[min].prioridade) min = j;
        }
        Componente temp = c[i];
        c[i] = c[min];
        c[min] = temp;
    }
}

int buscaBinariaPorNome(Componente c[], int n, char nome[], int* comparacoes) {
    int esq = 0, dir = n - 1;
    *comparacoes = 0;
    while (esq <= dir) {
        int meio = (esq + dir)/2;
        (*comparacoes)++;
        int cmp = strcmp(c[meio].nome, nome);
        if (cmp == 0) return meio;
        else if (cmp < 0) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

int main() {
    int opcao;
    do {
        scanf("%d", &opcao);
        if (opcao == 1) {
            int escolha;
            do {
                scanf("%d", &escolha);
                switch (escolha) {
                    case 1: inserirItemVetor(); break;
                    case 2: removerItemVetor(); break;
                    case 3: listarItensVetor(); break;
                    case 4: buscarItemVetor(); break;
                }
            } while (escolha != 0);
        } else if (opcao == 2) {
            int escolha, sub;
            scanf("%d", &sub);
            do {
                scanf("%d", &escolha);
                if (sub == 1) {
                    switch (escolha) {
                        case 1: inserirItemVetor(); break;
                        case 2: removerItemVetor(); break;
                        case 3: listarItensVetor(); break;
                        case 4: buscarItemVetor(); break;
                    }
                } else if (sub == 2) {
                    switch (escolha) {
                        case 1: inserirItemLista(); break;
                        case 2: removerItemLista(); break;
                        case 3: listarItensLista(); break;
                        case 4: buscarItemLista(); break;
                    }
                }
            } while (escolha != 0);
        } else if (opcao == 3) {
            Componente torre[MAX_COMPONENTES];
            int nComponentes, cComparacoes, escolha;
            char nomeBusca[30];
            scanf("%d", &nComponentes);
            if (nComponentes > MAX_COMPONENTES) nComponentes = MAX_COMPONENTES;
            for (int i = 0; i < nComponentes; i++) {
                scanf(" %[^\n]", torre[i].nome);
                scanf(" %[^\n]", torre[i].tipo);
                scanf("%d", &torre[i].prioridade);
            }
            do {
                scanf("%d", &escolha);
                clock_t inicio, fim;
                double tempo;
                switch (escolha) {
                    case 1:
                        inicio = clock();
                        bubbleSortNome(torre, nComponentes, &cComparacoes);
                        fim = clock();
                        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                        printf("%d %.6f\n", cComparacoes, tempo);
                        mostrarComponentes(torre, nComponentes);
                        break;
                    case 2:
                        inicio = clock();
                        insertionSortTipo(torre, nComponentes, &cComparacoes);
                        fim = clock();
                        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                        printf("%d %.6f\n", cComparacoes, tempo);
                        mostrarComponentes(torre, nComponentes);
                        break;
                    case 3:
                        inicio = clock();
                        selectionSortPrioridade(torre, nComponentes, &cComparacoes);
                        fim = clock();
                        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                        printf("%d %.6f\n", cComparacoes, tempo);
                        mostrarComponentes(torre, nComponentes);
                        break;
                    case 4:
                        scanf(" %[^\n]", nomeBusca);
                        int idx = buscaBinariaPorNome(torre, nComponentes, nomeBusca, &cComparacoes);
                        if (idx != -1)
                            printf("%s %s %d %d\n", torre[idx].nome, torre[idx].tipo, torre[idx].prioridade, cComparacoes);
                        else
                            printf("%d\n", cComparacoes);
                        break;
                    case 5:
                        mostrarComponentes(torre, nComponentes);
                        break;
                }
            } while (escolha != 0);
        }
    } while (opcao != 0);

    No* temp;
    while (cabeca) {
        temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
    }

    return 0;
}