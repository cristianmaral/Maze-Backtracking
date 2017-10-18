#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

/* Fun��o para printar um poss�vel caminho para atravessar o labirinto */
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

/* Fun��o recursiva que utiliza do paradigma Backtrack para encontrar um poss�vel caminho */
/* para o cachorro chegar ao destino do labirinto */
int solveMazeUtil(Maze maze[N][N], int x, int y, int sol[N][N])
{
    /* Se o cachorro conseguiu chegar no topo do labirinto, returna 1 (encontrou um caminho v�lido) */
    if(x == 0 && maze[x][y].valor == 1)
    {
        sol[x][y] = 1;
        return 1;
    }

    /* Checando se a posi��o atual do labirinto � v�lida para tentar avan�ar no labirinto a partir dela */
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y].valor == 1 && maze[x][y].visitou == 0)
    {
        sol[x][y] = 1; //Marcando como posi��o v�lida para a matriz de solu��o
        maze[x][y].visitou = 1; //Flag respons�vel por controlar as visitas de cada posi��o do labirinto

        /* Tentando mover o cachorro para cima */
        if (solveMazeUtil(maze, x-1, y, sol) == 1)
            return 1;

        /* Tentando mover o cachorro para a direita */
        if (solveMazeUtil(maze, x, y+1, sol) == 1)
            return 1;

        /* Tentando mover o cachorro para a esquerda */
        if (solveMazeUtil(maze, x, y-1, sol) == 1)
           return 1;

        /* Se nenhuma das possibilidades de movimento acima resultarem em uma posi��o v�lida, */
        /* ser� necess�rio utilizar backtrack */
        sol[x][y] = 0; //Removendo a posi��o atual da solu��o final do problema (atribuindo 0)
        return -1; //Backtrack
    }

    /* N�o � poss�vel chegar ao topo do labirinto por nenhum caminho */
    return -1;
}

/* Fun��o para encapsular a fun��o "solveMazeUtil", cujo objetivo se baseia em informar */
/* a posi��o inicial do cachorro */
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


