#include "Arquivo.h"

Labirinto** leLabirintoEntrada (FILE *arquivoDeEntrada, int *linhas, int *colunas) {
    Labirinto **labirinto;
    int i, j;

    fscanf(arquivoDeEntrada, "%d %d", linhas, colunas);
    labirinto = alocaLabirinto(*linhas, *colunas);
    for (i=0; i<*linhas; i++) {
        for (j=0; j<*colunas; j++) {
            fscanf(arquivoDeEntrada, "%d", &labirinto[i][j].valor);
        }
    }
    return labirinto;
}
