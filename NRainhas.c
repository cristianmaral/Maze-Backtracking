#include "NRainhas.h"
#include <stdio.h>
#include <stdlib.h>


void mostraSolucao(int matriz[N][N]) {
    int i, j;
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++)
            printf(" %d ", matriz[i][j]);
        printf("\n");
    }
}

int rainhaPodeEstar(int matriz[N][N], int linha, int coluna) {
    int i, j;
    for (i = 0; i < coluna; i++)
        if (matriz[linha][i])
            return -1;
    for (i=linha, j=coluna;i>=0 && j>=0;i--, j--)
        if (matriz[i][j])
            return -1;

    for (i=linha, j=coluna;j>=0 && i<N;i++, j--)
        if (matriz[i][j])
            return -1;
    return 1;
}

int achaPosicaoRainha(int matriz[N][N], int coluna) {
    int i;
    if (coluna >= N)
        return 1;
    for (i=0;i<N;i++) {
        if (rainhaPodeEstar(matriz, i, coluna) == 1) {
            matriz[i][coluna] = 1;
            if (achaPosicaoRainha(matriz, coluna + 1) == 1)
                return 1;
            matriz[i][coluna] = 0;
        }
    }
    return -1;
}
