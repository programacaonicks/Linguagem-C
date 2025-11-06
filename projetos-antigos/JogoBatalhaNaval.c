#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10  // Tamanho do tabuleiro
#define AGUA 0       // Representa água
#define NAVIO 3      // Representa um navio
#define HABILIDADE 5 // Representa área afetada por habilidades

//inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

//exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

//posicionar navios
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') { // Vertical
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else if (orientacao == 'D') { // Diagonal principal
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'A') { // Diagonal secundária
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

//aplicar habilidades especiais
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo) {
    int i, j;
    if (tipo == 'C') { // Cruz
        for (i = -2; i <= 2; i++) {
            if (linha + i >= 0 && linha + i < TAMANHO) tabuleiro[linha + i][coluna] = HABILIDADE;
            if (coluna + i >= 0 && coluna + i < TAMANHO) tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    } else if (tipo == 'O') { // Octaedro
        for (i = -2; i <= 2; i++) {
            for (j = -2; j <= 2; j++) {
                if (abs(i) + abs(j) <= 2 && linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                    tabuleiro[linha + i][coluna + j] = HABILIDADE;
                }
            }
        }
    } else if (tipo == 'N') { // Cone
        for (i = 0; i < 3; i++) {
            for (j = -i; j <= i; j++) {
                if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO) {
                    tabuleiro[linha + i][coluna + j] = HABILIDADE;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamento de navios
    posicionarNavio(tabuleiro, 2, 3, 3, 'H'); // Navio horizontal
    posicionarNavio(tabuleiro, 5, 6, 3, 'V'); // Navio vertical
    posicionarNavio(tabuleiro, 1, 1, 3, 'D'); // Navio diagonal principal
    posicionarNavio(tabuleiro, 3, 8, 3, 'A'); // Navio diagonal secundária

    // Aplicação de habilidades
    aplicarHabilidade(tabuleiro, 4, 4, 'C'); // Cruz
    aplicarHabilidade(tabuleiro, 6, 2, 'O'); // Octaedro
    aplicarHabilidade(tabuleiro, 2, 7, 'N'); // Cone

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
