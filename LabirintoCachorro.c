#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

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
int solveMazeUtil(Maze maze[N][N], int x, int y, int sol[N][N])
{
    /* Se o cachorro conseguiu chegar no topo do labirinto, returna 1 (encontrou um caminho válido) */
    if(x == 0 && maze[x][y].valor == 1)
    {
        sol[x][y] = 1;
        return 1;
    }

    /* Checando se a posição atual do labirinto é válida para tentar avançar no labirinto a partir dela */
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y].valor == 1 && maze[x][y].visitou == 0)
    {
        sol[x][y] = 1; //Marcando como posição válida para a matriz de solução
        maze[x][y].visitou = 1; //Flag responsável por controlar as visitas de cada posição do labirinto

        /* Tentando mover o cachorro para cima */
        if (solveMazeUtil(maze, x-1, y, sol) == 1)
            return 1;

        /* Tentando mover o cachorro para a direita */
        if (solveMazeUtil(maze, x, y+1, sol) == 1)
            return 1;

        /* Tentando mover o cachorro para a esquerda */
        if (solveMazeUtil(maze, x, y-1, sol) == 1)
           return 1;

        /* Se nenhuma das possibilidades de movimento acima resultarem em uma posição válida, */
        /* será necessário utilizar backtrack */
        sol[x][y] = 0; //Removendo a posição atual da solução final do problema (atribuindo 0)
        return -1; //Backtrack
    }

    /* Não é possível chegar ao topo do labirinto por nenhum caminho */
    return -1;
}

/* Função para encapsular a função "solveMazeUtil", cujo objetivo se baseia em informar */
/* a posição inicial do cachorro */
int solveMaze(Maze maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if(solveMazeUtil(maze, N-1, 0, sol) == -1)
    {
        printf("Solution doesn't exist");
        return -1;
    }

    printSolution(sol);
    return 1;
}


