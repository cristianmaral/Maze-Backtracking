#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

/* Estrutura de dados para o labirinto */
typedef struct {
    int cor; //Indica se é uma posição válida, parede ou a posição inicial do cachorro (1, 2, 3 respectivamente)
    int visitou; //Indica se uma posição do labirinto já foi visitada pelo cachorro (1 para sim e 0 para não)
} Labirinto;


/* Declaração das funções contidas no arquivo LabirintoCachorro.c */
Labirinto** alocaLabirinto (int linhas, int colunas);
int** alocaCaminho (int linhas, int colunas);
void resetaVisitas (Labirinto **labirinto, int linhas, int colunas);
int colunaInicial (Labirinto **labirinto, int linhas, int colunas);
int calculaFlag (int *linhaCaminho, int jInicial);
void imprimeSolucao (int **caminho, int movimentacoes, int linhas, int colunas, int jInicial);
int movimenta_cachorro (Labirinto **labirinto, int **caminho, int *movimentacoes, int linhas, int colunas, int i, int j);
int movimenta_cachorro2 (Labirinto **labirinto, int **caminho, int *movimentacoes, int *chamadasRecursivas,
                        int * maiorNivelRecursao, int nivel, int linhas, int colunas, int i, int j);
void solucionaLabirinto (Labirinto **labirinto, int linhas, int colunas);
void solucionaLabirinto2 (Labirinto **labirinto, int linhas, int colunas);


#endif // LABIRINTOCACHORRO_H_INCLUDED
