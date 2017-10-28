#ifndef LABIRINTOCACHORRO_H_INCLUDED
#define LABIRINTOCACHORRO_H_INCLUDED

/* Estrutura de dados para o labirinto */
typedef struct {
    int **cor; /* Indica as cores de cada posição do labirinto */
    int **visitou; /* Indica a visita de todas as posições do labirinto
                      0 -> posição não visitada
                      1 -> posição já visitada */
} Labirinto;

/* Declaração das funções contidas no arquivo LabirintoCachorro.c */
Labirinto alocaLabirinto (int linhas, int colunas);
int** alocaCaminho (int linhas, int colunas);
void resetaVisitas (Labirinto *labirinto, int linhas, int colunas);
int colunaInicial (Labirinto *labirinto, int linhas, int colunas);
int calculaFlag (int *linhaCaminho, int jInicial);
void imprimeSolucao (int **caminho, int movimentacoes, int linhas, int colunas, int jInicial);
/* Modo análise desligado */
int movimenta_cachorro (Labirinto *labirinto, int **caminho, int *movimentacoes, int linhas,
                        int colunas, int i, int j);
void solucionaLabirinto (Labirinto *labirinto, int linhas, int colunas);
/* Modo anlise ligado */
int movimenta_cachorro2 (Labirinto *labirinto, int **caminho, int *movimentacoes, int *chamadasRecursivas,
                        int * maiorNivelRecursao, int nivel, int linhas, int colunas, int i, int j);
void solucionaLabirinto2 (Labirinto *labirinto, int linhas, int colunas);


#endif // LABIRINTOCACHORRO_H_INCLUDED
