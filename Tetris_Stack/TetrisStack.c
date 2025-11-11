#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5
#define MAX_PILHA 3

typedef struct {
    char tipo;
    int id;
} Peca;

typedef struct {
    Peca fila[MAX_FILA];
    int inicio;
    int fim;
    int qtd;
} Fila;

typedef struct {
    Peca pilha[MAX_PILHA];
    int topo;
} Pilha;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int filaCheia(Fila *f) {
    return f->qtd == MAX_FILA;
}

int filaVazia(Fila *f) {
    return f->qtd == 0;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void enfileirar(Fila *f, Peca p) {
    if (filaCheia(f)) return;
    f->fila[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->qtd++;
}

Peca desenfileirar(Fila *f) {
    Peca p = {'-', -1};
    if (filaVazia(f)) return p;
    p = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->qtd--;
    return p;
}

void empilhar(Pilha *p, Peca x) {
    if (pilhaCheia(p)) return;
    p->pilha[++p->topo] = x;
}

Peca desempilhar(Pilha *p) {
    Peca x = {'-', -1};
    if (pilhaVazia(p)) return x;
    return p->pilha[p->topo--];
}

Peca gerarPeca(int id) {
    Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L'};
    nova.tipo = tipos[rand() % 4];
    nova.id = id;
    return nova;
}

void exibirEstado(Fila *f, Pilha *p) {
    printf("\n==============================\n");
    printf("Fila de peças:\n");
    if (filaVazia(f)) printf("(vazia)\n");
    else {
        int i = f->inicio;
        for (int c = 0; c < f->qtd; c++) {
            printf("[%c %d] ", f->fila[i].tipo, f->fila[i].id);
            i = (i + 1) % MAX_FILA;
        }
        printf("\n");
    }

    printf("Pilha de reserva (Topo -> Base):\n");
    if (pilhaVazia(p)) printf("(vazia)\n");
    else {
        for (int i = p->topo; i >= 0; i--) {
            printf("[%c %d] ", p->pilha[i].tipo, p->pilha[i].id);
        }
        printf("\n");
    }
    printf("==============================\n");
}

void trocarTopoFilaComPilha(Fila *f, Pilha *p) {
    if (filaVazia(f) || pilhaVazia(p)) {
        printf("Não há peças suficientes para troca.\n");
        return;
    }
    Peca temp = f->fila[f->inicio];
    f->fila[f->inicio] = p->pilha[p->topo];
    p->pilha[p->topo] = temp;
    printf("Troca entre o topo da pilha e a frente da fila realizada.\n");
}

void trocaMultipla(Fila *f, Pilha *p) {
    if (f->qtd < 3 || p->topo < 2) {
        printf("Não há peças suficientes para a troca múltipla.\n");
        return;
    }
    int idxFila = f->inicio;
    for (int i = 0; i < 3; i++) {
        Peca temp = f->fila[(idxFila + i) % MAX_FILA];
        f->fila[(idxFila + i) % MAX_FILA] = p->pilha[p->topo - i];
        p->pilha[p->topo - i] = temp;
    }
    printf("Troca múltipla entre as 3 primeiras peças da fila e da pilha realizada.\n");
}

int main() {
    Fila fila;
    Pilha pilha;
    inicializarFila(&fila);
    inicializarPilha(&pilha);
    srand(time(NULL));

    int id = 0;
    for (int i = 0; i < MAX_FILA; i++) {
        enfileirar(&fila, gerarPeca(id++));
    }

    int opcao;
    do {
        exibirEstado(&fila, &pilha);
        printf("\nOpções:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
        printf("5 - Trocar as 3 primeiras da fila com as 3 da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (!filaVazia(&fila)) {
                    Peca jogada = desenfileirar(&fila);
                    printf("Peça jogada: [%c %d]\n", jogada.tipo, jogada.id);
                    enfileirar(&fila, gerarPeca(id++));
                } else printf("Fila vazia!\n");
                break;
            }
            case 2: {
                if (pilhaCheia(&pilha)) printf("Pilha cheia!\n");
                else if (!filaVazia(&fila)) {
                    Peca reservada = desenfileirar(&fila);
                    empilhar(&pilha, reservada);
                    printf("Peça reservada: [%c %d]\n", reservada.tipo, reservada.id);
                    enfileirar(&fila, gerarPeca(id++));
                }
                break;
            }
            case 3: {
                if (!pilhaVazia(&pilha)) {
                    Peca usada = desempilhar(&pilha);
                    printf("Peça usada: [%c %d]\n", usada.tipo, usada.id);
                } else printf("Pilha vazia!\n");
                break;
            }
            case 4:
                trocarTopoFilaComPilha(&fila, &pilha);
                break;
            case 5:
                trocaMultipla(&fila, &pilha);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
