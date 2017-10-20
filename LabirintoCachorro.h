#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

typedef struct {
    int valor;
    int visitou;
} Labirinto;

Labirinto** alocaLabirinto (int linhas, int colunas);
int** alocaSolucao (int linhas, int colunas);
void resetaVisitas (Labirinto **labirinto, int linhas, int colunas);
int colunaInicial (Labirinto **labirinto, int linhas, int colunas);
int calculaFlag (int *linhaSolucao, int jInicial);
void printSolution(int **solucao, int linhas, int colunas, int jInicial);
int solveMazeUtil(Labirinto **labirinto, int **solucao, int linhas, int colunas, int i, int j);
int solveMaze(Labirinto **labirinto, int linhas, int colunas);


#endif // LABIRINTOCACHORRO_H_INCLUDED
