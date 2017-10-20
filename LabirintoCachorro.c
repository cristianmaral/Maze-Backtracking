#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

/* Fun��o para alocar dinamicamente o labirinto (matriz) */
Labirinto** alocaLabirinto (int linhas, int colunas) {
    Labirinto **labirinto;
    int i;

    labirinto = (Labirinto **)malloc(linhas * sizeof(Labirinto));
    for (i=0; i<linhas; i++) {
        labirinto[i] = (Labirinto *)calloc(colunas, sizeof(Labirinto));
    }
    return labirinto;
}

/* Fun��o para alocar dinamicamente a matriz de solu��o do labirinto */
int** alocaSolucao (int linhas, int colunas) {
    int **solucao;
    int i;

    solucao = (int **)malloc(linhas * sizeof(int));
    for (i=0; i<linhas; i++) {
        solucao[i] = (int *)calloc(colunas, sizeof(int));
    }
    return solucao;
}

/* Fun��o para resetar os flags de visitou do labirinto */
void resetaVisitas (Labirinto **labirinto, int linhas, int colunas) {
    int i, j;

    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            labirinto[i][j].visitou = 0;
        }
    }
}

/* Fun��o para indicar a posi��o inicial do cachorro */
int colunaInicial (Labirinto **labirinto, int linhas, int colunas) {
    int i;
    for (i=0; i<colunas; i++) {
        if (labirinto[linhas - 1][i].valor == 2) {
            return i;
        }
    }
    return -1;
}

/* Fun��o auxiliar para indicar se o caminho segue para a direita ou para a esquerda */
int calculaFlag (int *linhaSolucao, int jInicial) {
    if (linhaSolucao[jInicial + 1] == 1)
        return 1;
    else
        return 0;
}

/* Fun��o para printar um poss�vel caminho para atravessar o labirinto */
void printSolution(int **solucao, int linhas, int colunas, int jInicial)
{
    int i, j, aux = 0;

    for (i=linhas-1; i>0; i--) {
        /* Imprimindo o caminho da base do labirinto */
        if (i == linhas - 1) {
            /* O pr�ximo movimento � para a direita */
            if (calculaFlag(solucao[i], jInicial) == 1) {
                for (j=jInicial; j<colunas; j++) {
                    if (solucao[i][j] == 1) {
                        printf("Linha: %d Coluna: %d\n", i, j);
                        if (j < colunas - 1 && solucao[i][j+1] != 1) {
                            aux = j; /* Indica qual coluna o caminho da linha de cima continua */
                            break;
                        }
                    }
                }
            }
            /* O pr�ximo movimento � para a esquerda */
            else {
                for (j=jInicial; j>=0; j--) {
                    if (solucao[i][j] == 1) {
                        printf("Linha: %d Coluna: %d\n", i, j);
                        if (j > 0 && solucao[i][j-1] != 1) {
                            aux = j; /* Indica qual coluna o caminho da linha de cima continua */
                            break;
                        }
                    }
                }
            }
        }
        /* Imprimindo o caminho das outras linhas do labirinto */
        else {
            /* O pr�ximo movimento � para a direita */
            if (calculaFlag(solucao[i], aux) == 1) {
                for (j=aux; j<colunas; j++) {
                    if (solucao[i][j] == 1) {
                        printf("Linha: %d Coluna: %d\n", i, j);
                        if (j < colunas - 1 && solucao[i][j+1] != 1) {
                            aux = j; /* Indica qual coluna o caminho da linha de cima continua */
                            break;
                        }
                    }
                }
            }
            /* O pr�ximo movimento � para a esquerda */
            else {
                for (j=aux; j>=0; j--) {
                    if (solucao[i][j] == 1) {
                        printf("Linha: %d Coluna: %d\n", i, j);
                        if (j > 0 && solucao[i][j-1] != 1) {
                            aux = j; /* Indica qual coluna o caminho da linha de cima continua */
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("O cachorro se movimentou x vezes e chegou na coluna %d da primeira linha\n", aux);
}

/* Fun��o recursiva que utiliza do paradigma Backtrack para encontrar um poss�vel caminho */
/* para o cachorro chegar ao destino do labirinto */
int solveMazeUtil(Labirinto **labirinto, int **solucao, int linhas, int colunas, int i, int j)
{
    /* Se o cachorro conseguiu chegar no topo do labirinto, returna 1 (encontrou um caminho v�lido) */
    if(i == 0 && labirinto[i][j].valor == 1)
    {
        solucao[i][j] = 1;
        return 1;
    }

    /* Checando se a posi��o atual do labirinto � v�lida para tentar avan�ar no labirinto a partir dela */
    if(i >= 0 && i < linhas && j >= 0 && j < colunas &&
       (labirinto[i][j].valor == 1 || labirinto[i][j].valor == 2) && labirinto[i][j].visitou == 0)
    {
        solucao[i][j] = 1; //Marcando como posi��o v�lida para a matriz de solu��o
        labirinto[i][j].visitou = 1; //Flag respons�vel por controlar as visitas de cada posi��o do labirinto

        /* Tentando mover o cachorro para cima */
        if (solveMazeUtil(labirinto, solucao, linhas, colunas, i-1, j) == 1)
            return 1;

        /* Tentando mover o cachorro para a direita */
        if (solveMazeUtil(labirinto, solucao, linhas, colunas, i, j+1) == 1)
            return 1;

        /* Tentando mover o cachorro para a esquerda */
        if (solveMazeUtil(labirinto, solucao, linhas, colunas, i, j-1) == 1)
           return 1;

        /* Se nenhuma das possibilidades de movimento acima resultarem em uma posi��o v�lida, */
        /* ser� necess�rio utilizar backtrack */
        solucao[i][j] = 0; //Removendo a posi��o atual da solu��o final do problema (atribuindo 0)
        return -1; //Backtrack
    }

    /* N�o � poss�vel chegar ao topo do labirinto por nenhum caminho */
    return -1;
}

/* Fun��o para encapsular a fun��o "solveMazeUtil", cujo objetivo se baseia em informar */
/* a posi��o inicial do cachorro */
int solveMaze(Labirinto **labirinto, int linhas, int colunas)
{
    int **solucao = alocaSolucao(linhas, colunas);
    int iInicial = linhas - 1;
    int jInicial = colunaInicial(labirinto, linhas, colunas);

    if(solveMazeUtil(labirinto, solucao, linhas, colunas, iInicial, jInicial) == -1)
    {
        printf("Solution doesn't exist\n\n");
        return -1;
    }

    printSolution(solucao, linhas, colunas, jInicial);
    return 1;
}


