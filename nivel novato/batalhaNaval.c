#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato - Posicionamento dos Navios

int main() {

    // ==========================================
    // Declaração do tabuleiro 10x10
    // ==========================================

    int tabuleiro[10][10];

    // ==========================================
    // Declaração dos navios
    // Cada navio possui tamanho 3
    // ==========================================

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // ==========================================
    // Variáveis de controle
    // ==========================================

    int linha;
    int coluna;

    // ==========================================
    // Inicialização do tabuleiro com água (0)
    // ==========================================

    for (linha = 0; linha < 10; linha++) {

        for (coluna = 0; coluna < 10; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }

    // ==========================================
    // Coordenadas iniciais dos navios
    // ==========================================

    // Navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    // Navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // ==========================================
    // Validação simples dos limites
    // ==========================================

    if (colunaHorizontal + 3 <= 10) {

        // Posiciona navio horizontal

        for (coluna = 0; coluna < 3; coluna++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + coluna] =
                navioHorizontal[coluna];
        }
    }

    if (linhaVertical + 3 <= 10) {

        // Posiciona navio vertical

        for (linha = 0; linha < 3; linha++) {

            // Verifica sobreposição simples

            if (tabuleiro[linhaVertical + linha][colunaVertical] == 0) {

                tabuleiro[linhaVertical + linha][colunaVertical] =
                    navioVertical[linha];
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