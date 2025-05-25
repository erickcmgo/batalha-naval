#include <stdio.h>

#define TAM 10

int main() {
    char tabuleiro[TAM][TAM];
    int i, j;
    int linha, coluna;
    char habilidade;
    char opcao;

    // Inicializa tabuleiro com '.'
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    // Coloca alguns navios 'N' no tabuleiro
    tabuleiro[1][1] = 'N';
    tabuleiro[2][2] = 'N';
    tabuleiro[3][4] = 'N';
    tabuleiro[6][7] = 'N';
    tabuleiro[8][3] = 'N';

    do {
        // Mostra o tabuleiro
        printf("\n  ");
        for(j = 0; j < TAM; j++) {
            printf("%d ", j);
        }
        printf("\n");

        for(i = 0; i < TAM; i++) {
            printf("%d ", i);
            for(j = 0; j < TAM; j++) {
                printf("%c ", tabuleiro[i][j]);
            }
            printf("\n");
        }

        // Pede a posição para aplicar habilidade
        printf("\nDigite a linha e coluna para usar a habilidade (0 a 9): ");
        scanf("%d %d", &linha, &coluna);

        printf("Escolha a habilidade: c (cone), x (cruz), o (octaedro): ");
        scanf(" %c", &habilidade);

        // Aplica a habilidade escolhida

        if(habilidade == 'c') {
            // Cone para cima (3 linhas)
            int k;
            for(k = 0; k < 3; k++) {
                int l = linha - k;
                if(l < 0) break;
                int start = coluna - k;
                int end = coluna + k;
                for(j = start; j <= end; j++) {
                    if(j >= 0 && j < TAM) {
                        if(tabuleiro[l][j] == '.') {
                            tabuleiro[l][j] = '*';
                        }
                    }
                }
            }
        } else if(habilidade == 'x') {
            // Cruz (linha e coluna central + 1 posição em cada direção)
            if(linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if(tabuleiro[linha][coluna] == '.') tabuleiro[linha][coluna] = '*';

                if(linha-1 >= 0 && tabuleiro[linha-1][coluna] == '.') tabuleiro[linha-1][coluna] = '*';
                if(linha+1 < TAM && tabuleiro[linha+1][coluna] == '.') tabuleiro[linha+1][coluna] = '*';
                if(coluna-1 >= 0 && tabuleiro[linha][coluna-1] == '.') tabuleiro[linha][coluna-1] = '*';
                if(coluna+1 < TAM && tabuleiro[linha][coluna+1] == '.') tabuleiro[linha][coluna+1] = '*';
            }
        } else if(habilidade == 'o') {
            // Octaedro (raio 3)
            int di, dj;
            for(di = -3; di <= 3; di++) {
                for(dj = -3; dj <= 3; dj++) {
                    if(abs(di) + abs(dj) <= 3) {
                        int ni = linha + di;
                        int nj = coluna + dj;
                        if(ni >= 0 && ni < TAM && nj >= 0 && nj < TAM) {
                            if(tabuleiro[ni][nj] == '.') {
                                tabuleiro[ni][nj] = '*';
                            }
                        }
                    }
                }
            }
        } else {
            printf("Habilidade invalida!\n");
        }

        printf("\nQuer usar outra habilidade? (s/n): ");
        scanf(" %c", &opcao);

    } while(opcao == 's' || opcao == 'S');

    printf("\nFim do jogo.\n");
    return 0;
}
