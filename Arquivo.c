#include "Arquivo.h"
#include <stdlib.h>
#include <stdio.h>

void leArquivoEntrada (int **matriz, int *linhas, int *colunas) {
    FILE *arquivoDeEntrada = fopen("Espaço Geográfico.txt", "r");
    int i, j;

    fscanf(arquivoDeEntrada, "%d %d", linhas, colunas);
    for (i=0; i<*linhas; i++) {
        for (j=0; j<*colunas; j++) {
            fscanf(arquivoDeEntrada, "%d", &matriz[i][j]);
        }
    }
}
