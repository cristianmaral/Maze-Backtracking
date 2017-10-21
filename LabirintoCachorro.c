#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

/* Função para alocar dinamicamente o labirinto (matriz) */
Labirinto** alocaLabirinto (int linhas, int colunas) {
    Labirinto **labirinto;
    int i;

    labirinto = (Labirinto **)malloc(linhas * sizeof(Labirinto));
    for (i=0; i<linhas; i++) {
        labirinto[i] = (Labirinto *)calloc(colunas, sizeof(Labirinto));
    }
    return labirinto;
}

/* Função para alocar dinamicamente a matriz de solução do labirinto */
int** alocaSolucao (int linhas, int colunas) {
    int **solucao;
    int i;

    solucao = (int **)malloc(linhas * sizeof(int));
    for (i=0; i<linhas; i++) {
        solucao[i] = (int *)calloc(colunas, sizeof(int));
    }
    return solucao;
}

/* Função para resetar os flags de visitou do labirinto */
void resetaVisitas (Labirinto **labirinto, int linhas, int colunas) {
    int i, j;

    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            labirinto[i][j].visitou = 0;
        }
    }
}

/* Função para indicar a posição inicial do cachorro */
int colunaInicial (Labirinto **labirinto, int linhas, int colunas) {
    int i;
    for (i=0; i<colunas; i++) {
        if (labirinto[linhas - 1][i].valor == 2) {
            return i;
        }
    }
    return -1;
}

/* Função auxiliar para indicar se o caminho segue para a direita ou para a esquerda */
int calculaFlag (int *linhaSolucao, int jInicial) {
    if (linhaSolucao[jInicial + 1] == 1)
        return 1; //O caminho segue para a direita
    else
        return 0; //O caminho segue para a esquerda
}

/* Função para printar um possível caminho para atravessar o labirinto */
void imprimeSolucao(int **solucao, int movimentacoes, int linhas, int colunas, int jInicial) {
    int i, j;
    /* A variável jInicial se refere à coluna onde inicia o caminho do cachorro em uma linha do labirinto */
    /* O valor dessa variável recebida como parâmetro condiz com a coluna inicial do cachorro */

    for (i=linhas-1; i>0; i--) {
        /* O próximo movimento é para a direita */
        if (calculaFlag(solucao[i], jInicial) == 1) {
            for (j=jInicial; j<colunas; j++) {
                if (solucao[i][j] == 1) {
                    printf("Linha: %d Coluna: %d\n", i, j);
                    if (j < colunas - 1 && solucao[i][j+1] != 1) {
                        jInicial = j; /* Indica qual coluna o caminho da linha de cima continua */
                        break;
                    }
                }
            }
        }
        /* O próximo movimento é para a esquerda */
        else {
            for (j=jInicial; j>=0; j--) {
                if (solucao[i][j] == 1) {
                    printf("Linha: %d Coluna: %d\n", i, j);
                    if (j > 0 && solucao[i][j-1] != 1) {
                        jInicial = j; /* Indica qual coluna o caminho da linha de cima continua */
                        break;
                    }
                }
            }
        }
    }
    printf("O cachorro se movimentou %d vezes e chegou na coluna %d da primeira linha\n", movimentacoes, jInicial);
}

/* Função recursiva que utiliza do paradigma Backtrack para encontrar um possível caminho */
/* para o cachorro chegar ao destino do labirinto */
int backTrackLabirinto(Labirinto **labirinto, int **solucao, int *movimentacoes, int linhas, int colunas, int i, int j) {
    /* Se o cachorro conseguiu chegar no topo do labirinto, returna 1 (encontrou um caminho válido) */
    if(i == 0 && labirinto[i][j].valor == 1)
    {
        solucao[i][j] = 1;
        return 1;
    }

    /* Checando se a posição atual do labirinto é válida para tentar avançar no labirinto a partir dela */
    if(i >= 0 && i < linhas && j >= 0 && j < colunas &&
       (labirinto[i][j].valor == 1 || labirinto[i][j].valor == 2) && labirinto[i][j].visitou == 0)
    {
        solucao[i][j] = 1; //Marcando como posição válida para a matriz de solução
        labirinto[i][j].visitou = 1; //Flag responsável por controlar as visitas de cada posição do labirinto
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro

        /* Tentando mover o cachorro para cima */
        if (backTrackLabirinto(labirinto, solucao, movimentacoes, linhas, colunas, i-1, j) == 1)
            return 1;

        /* Tentando mover o cachorro para a direita */
        if (backTrackLabirinto(labirinto, solucao, movimentacoes, linhas, colunas, i, j+1) == 1)
            return 1;

        /* Tentando mover o cachorro para a esquerda */
        if (backTrackLabirinto(labirinto, solucao, movimentacoes, linhas, colunas, i, j-1) == 1)
           return 1;

        /* Se nenhuma das possibilidades de movimento acima resultarem em uma posição válida, */
        /* será necessário utilizar backtrack */
        solucao[i][j] = 0; //Removendo a posição atual da solução final do problema (atribuindo 0)
        (*movimentacoes)++; //O cachorro se movimenta para uma posição anterior
        return -1; //Backtrack
    }

    /* Não é possível chegar ao topo do labirinto por nenhum caminho */
    return -1;
}

/* Função para encapsular a função "backTrackLabirinto", cujo objetivo se baseia em informar */
/* a posição inicial do cachorro */
void solucionaLabirinto(Labirinto **labirinto, int linhas, int colunas) {
    int **solucao = alocaSolucao(linhas, colunas);
    int iInicial = linhas - 1;
    int jInicial = colunaInicial(labirinto, linhas, colunas);
    int movimentacoes = 0;

    if(backTrackLabirinto(labirinto, solucao, &movimentacoes, linhas, colunas, iInicial, jInicial) == -1)
        printf("Solution doesn't exist\n\n");
    else
        imprimeSolucao(solucao, movimentacoes, linhas, colunas, jInicial);
}


