#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades Especiais

int main() {

    // ==========================================
    // TABULEIRO PRINCIPAL 10x10
    // ==========================================

    int tabuleiro[10][10];

    // ==========================================
    // MATRIZES DAS HABILIDADES 5x5
    // ==========================================

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // ==========================================
    // Variáveis de controle
    // ==========================================

    int linha;
    int coluna;

    // ==========================================
    // Inicializa tabuleiro com água (0)
    // ==========================================

    for (linha = 0; linha < 10; linha++) {

        for (coluna = 0; coluna < 10; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }

    // ==========================================
    // POSICIONAMENTO DOS NAVIOS
    // Valor 3 representa navio
    // ==========================================

    // Navio horizontal

    for (coluna = 1; coluna <= 3; coluna++) {

        tabuleiro[2][coluna] = 3;
    }

    // Navio vertical

    for (linha = 5; linha <= 7; linha++) {

        tabuleiro[linha][7] = 3;
    }

    // ==========================================
    // CONSTRUÇÃO DA HABILIDADE CONE
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            cone[linha][coluna] = 0;

            // Formato de cone

            if (coluna >= 2 - linha && coluna <= 2 + linha) {

                cone[linha][coluna] = 1;
            }
        }
    }

    // ==========================================
    // CONSTRUÇÃO DA HABILIDADE CRUZ
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            cruz[linha][coluna] = 0;

            // Linha central e coluna central

            if (linha == 2 || coluna == 2) {

                cruz[linha][coluna] = 1;
            }
        }
    }

    // ==========================================
    // CONSTRUÇÃO DA HABILIDADE OCTAEDRO
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            octaedro[linha][coluna] = 0;

            // Formato losango

            if ((linha == 0 && coluna == 2) ||
                (linha == 1 && coluna >= 1 && coluna <= 3) ||
                (linha == 2 && coluna >= 0 && coluna <= 4) ||
                (linha == 3 && coluna >= 1 && coluna <= 3) ||
                (linha == 4 && coluna == 2)) {

                octaedro[linha][coluna] = 1;
            }
        }
    }

    // ==========================================
    // PONTOS DE ORIGEM DAS HABILIDADES
    // ==========================================

    int origemConeLinha = 1;
    int origemConeColuna = 6;

    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 5;

    // ==========================================
    // SOBREPOSIÇÃO DO CONE
    // Valor 5 representa área afetada
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            int tabLinha = origemConeLinha + linha - 2;
            int tabColuna = origemConeColuna + coluna - 2;

            // Verifica limites do tabuleiro

            if (tabLinha >= 0 && tabLinha < 10 &&
                tabColuna >= 0 && tabColuna < 10) {

                if (cone[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == 0) {

                    tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // ==========================================
    // SOBREPOSIÇÃO DA CRUZ
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            int tabLinha = origemCruzLinha + linha - 2;
            int tabColuna = origemCruzColuna + coluna - 2;

            if (tabLinha >= 0 && tabLinha < 10 &&
                tabColuna >= 0 && tabColuna < 10) {

                if (cruz[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == 0) {

                    tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // ==========================================
    // SOBREPOSIÇÃO DO OCTAEDRO
    // ==========================================

    for (linha = 0; linha < 5; linha++) {

        for (coluna = 0; coluna < 5; coluna++) {

            int tabLinha = origemOctaedroLinha + linha - 2;
            int tabColuna = origemOctaedroColuna + coluna - 2;

            if (tabLinha >= 0 && tabLinha < 10 &&
                tabColuna >= 0 && tabColuna < 10) {

                if (octaedro[linha][coluna] == 1 &&
                    tabuleiro[tabLinha][tabColuna] == 0) {

                    tabuleiro[tabLinha][tabColuna] = 5;
                }
            }
        }
    }

    // ==========================================
    // EXIBIÇÃO DO TABULEIRO
    // ==========================================

    printf("=== TABULEIRO BATALHA NAVAL ===\n\n");

    for (linha = 0; linha < 10; linha++) {

        for (coluna = 0; coluna < 10; coluna++) {

            // Água
            if (tabuleiro[linha][coluna] == 0) {

                printf("0 ");
            }

            // Navio
            else if (tabuleiro[linha][coluna] == 3) {

                printf("3 ");
            }

            // Área afetada
            else if (tabuleiro[linha][coluna] == 5) {

                printf("5 ");
            }
        }

        printf("\n");
    }

    return 0;
}