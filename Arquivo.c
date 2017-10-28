#include "Arquivo.h"

/* Função responsável por ler um arquivo de entrada e atribuir suas características
   na estrutura Labirinto */
Labirinto leLabirintoEntrada (FILE *arquivoDeEntrada, int *linhas, int *colunas) {
    Labirinto labirinto;
    char *aux; //Representa uma linha de características do arquivo de entrada
    int i, j;

    fscanf(arquivoDeEntrada, "%d %d", linhas, colunas);
    aux = (char *)malloc(*colunas * sizeof(char));
    labirinto = alocaLabirinto(*linhas, *colunas);
    for (i=0; i<*linhas; i++) {
        fscanf(arquivoDeEntrada, "%s", aux); //Lendo a linha atual de características
        for (j=0; j<*colunas; j++) {
            /* Transformando cada caractere de aux em um inteiro e armazenando em sua
               devida posição do labirinto */
            labirinto.cor[i][j] = aux[j] - '0';
        }
    }
    return labirinto;
}
