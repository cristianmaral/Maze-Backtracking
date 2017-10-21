#include "Arquivo.h"

Labirinto** leLabirintoEntrada (FILE *arquivoDeEntrada, int *linhas, int *colunas) {
    Labirinto **labirinto;
    char *aux;
    int i, j;

    fscanf(arquivoDeEntrada, "%d %d", linhas, colunas);
    aux = (char *)malloc(*colunas * sizeof(char));
    labirinto = alocaLabirinto(*linhas, *colunas);
    for (i=0; i<*linhas; i++) {
        fscanf(arquivoDeEntrada, "%s", aux);
        for (j=0; j<*colunas; j++) {
            labirinto[i][j].valor = aux[j] - '0';
        }
    }
    return labirinto;
}
