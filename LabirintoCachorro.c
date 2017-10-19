#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

Labirinto** alocaLabirinto (int linhas, int colunas) {
    Labirinto **labirinto;
    int i;

    labirinto = (Labirinto **)malloc(linhas * sizeof(Labirinto));
    for (i=0; i<linhas; i++) {
        labirinto[i] = (Labirinto *)calloc(colunas, sizeof(Labirinto));
    }
    return labirinto;
}

/* Função para printar um possível caminho para atravessar o labirinto */
void printSolution(int sol[N][N])
{
    int i, j;
    printf("\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

/* Função recursiva que utiliza do paradigma Backtrack para encontrar um possível caminho */
/* para o cachorro chegar ao destino do labirinto */
int solveMazeUtil(Labirinto **labirinto, int sol[N][N], int linhas, int colunas, int i, int j)
{
    /* Se o cachorro conseguiu chegar no topo do labirinto, returna 1 (encontrou um caminho válido) */
    if(i == 0 && labirinto[i][j].valor == 1)
    {
        sol[i][j] = 1;
        return 1;
    }

    /* Checando se a posição atual do labirinto é válida para tentar avançar no labirinto a partir dela */
    if(i >= 0 && i < linhas && j >= 0 && j < colunas && labirinto[i][j].valor == 1 && labirinto[i][j].visitou == 0)
    {
        sol[i][j] = 1; //Marcando como posição válida para a matriz de solução
        labirinto[i][j].visitou = 1; //Flag responsável por controlar as visitas de cada posição do labirinto

        /* Tentando mover o cachorro para cima */
        if (solveMazeUtil(labirinto, sol, linhas, colunas, i-1, j) == 1)
            return 1;

        /* Tentando mover o cachorro para a direita */
        if (solveMazeUtil(labirinto, sol, linhas, colunas, i, j+1) == 1)
            return 1;

        /* Tentando mover o cachorro para a esquerda */
        if (solveMazeUtil(labirinto, sol, linhas, colunas, i, j-1) == 1)
           return 1;

        /* Se nenhuma das possibilidades de movimento acima resultarem em uma posição válida, */
        /* será necessário utilizar backtrack */
        sol[i][j] = 0; //Removendo a posição atual da solução final do problema (atribuindo 0)
        return -1; //Backtrack
    }

    /* Não é possível chegar ao topo do labirinto por nenhum caminho */
    return -1;
}

/* Função para encapsular a função "solveMazeUtil", cujo objetivo se baseia em informar */
/* a posição inicial do cachorro */
int solveMaze(Labirinto **labirinto, int linhas, int colunas)
{
    int sol[N][N] = { {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if(solveMazeUtil(labirinto, sol, linhas, colunas, N-1, 0) == -1)
    {
        printf("Solution doesn't exist");
        return -1;
    }

    printSolution(sol);
    return 1;
}


