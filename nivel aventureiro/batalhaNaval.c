#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Tabuleiro Completo e Navios Diagonais

int main() {

    // ==========================================
    // Declaração do tabuleiro 10x10
    // ==========================================

    int tabuleiro[10][10];

    // ==========================================
    // Variáveis de controle
    // ==========================================

    int linha;
    int coluna;
    int i;

    // ==========================================
    // Inicializa o tabuleiro com água (0)
    // ==========================================

    for (linha = 0; linha < 10; linha++) {

        for (coluna = 0; coluna < 10; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }

    // ==========================================
    // Coordenadas dos navios
    // Tamanho fixo = 3
    // ==========================================

    // Navio Horizontal
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    // Navio Vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Navio Diagonal Principal
    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;

    // Navio Diagonal Secundária
    int linhaDiagonal2 = 2;
    int colunaDiagonal2 = 9;

    // ==========================================
    // Posiciona Navio Horizontal
    // ==========================================

    if (colunaHorizontal + 3 <= 10) {

        for (i = 0; i < 3; i++) {

            // Verifica sobreposição

            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {

                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
            }
        }
    }

    // ==========================================
    // Posiciona Navio Vertical
    // ==========================================

    if (linhaVertical + 3 <= 10) {

        for (i = 0; i < 3; i++) {

            // Verifica sobreposição

            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {

                tabuleiro[linhaVertical + i][colunaVertical] = 3;
            }
        }
    }

    // ==========================================
    // Posiciona Navio Diagonal Principal
    // (linha e coluna aumentam juntas)
    // ==========================================

    if (linhaDiagonal1 + 3 <= 10 &&
        colunaDiagonal1 + 3 <= 10) {

        for (i = 0; i < 3; i++) {

            // Verifica sobreposição

            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] == 0) {

                tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
            }
        }
    }

    // ==========================================
    // Posiciona Navio Diagonal Secundária
    // (linha aumenta e coluna diminui)
    // ==========================================

    if (linhaDiagonal2 + 3 <= 10 &&
        colunaDiagonal2 - 2 >= 0) {

        for (i = 0; i < 3; i++) {

            // Verifica sobreposição

            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] == 0) {

                tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
            }
        }
    }

    // ==========================================
    // Exibição do tabuleiro
    // ==========================================

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (linha = 0; linha < 10; linha++) {

        for (coluna = 0; coluna < 10; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }

    return 0;
}