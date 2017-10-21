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
void imprimeSolucao(int **solucao, int movimentacoes, int linhas, int colunas, int jInicial);
int backTrackLabirinto(Labirinto **labirinto, int **solucao, int *movimentacoes, int linhas, int colunas, int i, int j);
int backTrackLabirinto2(Labirinto **labirinto, int **solucao, int *movimentacoes, int *chamadasRecursivas,
                        int * maiorNivelRecursao, int aux, int linhas, int colunas, int i, int j);
void solucionaLabirinto(Labirinto **labirinto, int linhas, int colunas);
void solucionaLabirinto2(Labirinto **labirinto, int linhas, int colunas);


#endif // LABIRINTOCACHORRO_H_INCLUDED
