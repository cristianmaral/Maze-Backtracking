#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

#define N 5

typedef struct {
    int valor;
    int visitou;
} Labirinto;

Labirinto** alocaLabirinto (int linhas, int colunas);
void printSolution(int sol[N][N]);
int solveMazeUtil(Labirinto **labirinto, int sol[N][N], int linhas, int colunas, int i, int j);
int solveMaze(Labirinto **labirinto, int linhas, int colunas);


#endif // LABIRINTOCACHORRO_H_INCLUDED
