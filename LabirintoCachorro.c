#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

/* Função para alocar dinamicamente o labirinto (matriz) */
Labirinto alocaLabirinto (int linhas, int colunas) {
    Labirinto labirinto;
    int i;

    labirinto.cor = (int **)malloc(linhas * sizeof(int*));
    labirinto.visitou = (int **)malloc(linhas * sizeof(int *));
    for (i=0; i<linhas; i++) {
        labirinto.cor[i] = (int *)malloc(colunas * sizeof(int));
        labirinto.visitou[i] = (int *)calloc(colunas, sizeof(int));
    }
    return labirinto;
}

/* Função para alocar dinamicamente a matriz de solução do labirinto */
int** alocaCaminho (int linhas, int colunas) {
    int **caminho;
    int i;

    caminho = (int **)malloc(linhas * sizeof(int *));
    for (i=0; i<linhas; i++) {
        caminho[i] = (int *)calloc(colunas, sizeof(int));
    }
    return caminho;
}

/* Função para resetar os flags de visitou do labirinto */
void resetaVisitas (Labirinto *labirinto, int linhas, int colunas) {
    int i, j;

    for (i=0; i<linhas; i++) {
        for (j=0; j<colunas; j++) {
            labirinto->visitou[i][j] = 0;
        }
    }
}

/* Função para indicar a coluna inicial do cachorro */
int colunaInicial (Labirinto *labirinto, int linhas, int colunas) {
    int i;
    for (i=0; i<colunas; i++) {
        if (labirinto->cor[linhas - 1][i] == 2) {
            return i;
        }
    }
    return -1;
}

/* Função auxiliar para indicar se o caminho segue para a direita ou para a esquerda */
int calculaFlag (int *linhaCaminho, int jInicial) {
    if (linhaCaminho[jInicial + 1] == 1)
        return 1; //O caminho segue para a direita
    else
        return 0; //O caminho segue para a esquerda
}

/* Função para printar um possível caminho para atravessar o labirinto */
void imprimeSolucao (int **caminho, int movimentacoes, int linhas, int colunas, int jInicial) {
    int i, j;
    /* A variável jInicial se refere à coluna onde inicia o caminho do cachorro em uma linha do labirinto */
    /* O valor dessa variável recebida como parâmetro condiz com a coluna inicial do cachorro */
    for (i=linhas-1; i>0; i--) {
        /* O próximo movimento é para a direita */
        if (calculaFlag(caminho[i], jInicial) == 1) {
            for (j=jInicial; j<colunas; j++) {
                if (caminho[i][j] == 1) {
                    printf("Linha: %d Coluna: %d\n", i, j);
                    if (caminho[i][j+1] != 1) {
                        jInicial = j; /* Indica qual coluna o caminho da linha de cima continua */
                        break;
                    }
                }
            }
        }
        /* O próximo movimento é para a esquerda */
        else {
            for (j=jInicial; j>=0; j--) {
                if (caminho[i][j] == 1) {
                    printf("Linha: %d Coluna: %d\n", i, j);
                    if (caminho[i][j-1] != 1) {
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
int movimenta_cachorro (Labirinto *labirinto, int **caminho, int *movimentacoes, int linhas, int colunas,
                        int i, int j)
{
    caminho[i][j] = 1; //Marcando como uma possível posição válida para a matriz de solução
    labirinto->visitou[i][j] = 1;
    /* Se o cachorro conseguiu chegar ao topo do labirinto, returna 1 (encontrou um caminho válido) */
    if(i == 0)
        return 1;

    /* Tentando mover o cachorro para cima */
    if (labirinto->cor[i - 1][j] != 3 && labirinto->visitou[i - 1][j] == 0 && i - 1 >= 0) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro(labirinto, caminho, movimentacoes, linhas, colunas, i - 1, j) == 1)
            return 1;
    }

    /* Tentando mover o cachorro para a direita */
    if (labirinto->cor[i][j + 1] != 3 && labirinto->visitou[i][j + 1] == 0 && j + 1 < colunas) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro(labirinto, caminho, movimentacoes, linhas, colunas, i, j + 1) == 1)
            return 1;
    }

    /* Tentando mover o cachorro para a esquerda */
    if (labirinto->cor[i][j - 1] != 3 && labirinto->visitou[i][j - 1] == 0 && j - 1 >= 0) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro(labirinto, caminho, movimentacoes, linhas, colunas, i, j - 1) == 1)
           return 1;
    }

    /* Se nenhuma das possibilidades de movimento acima resultarem em uma posição válida,
       será necessário utilizar backtrack */

    caminho[i][j] = 0; //Removendo a posição atual da solução final do problema (atribuindo 0)
    /* Se for a posição inicial do cachorro, o contador de movimentações não deve ser incrementado, pois
       não há nenhuma posição anterior à ela */
    if (labirinto->cor[i][j] == 1)
        (*movimentacoes)++;
    return -1; //Backtrack ou sem solução
}

/* Função para encapsular a função "movimenta_cachorro", cujo objetivo se baseia em informar
   a posição inicial do cachorro */
void solucionaLabirinto (Labirinto *labirinto, int linhas, int colunas) {
    int **caminho = alocaCaminho(linhas, colunas); //Matriz de solução - um caminho possível
    int iInicial = linhas - 1; //Linha inicial do cachorro
    int jInicial = colunaInicial(labirinto, linhas, colunas); //Coluna inicial do cachorro
    int movimentacoes = 0; //Quantidade de movimentações do cachorro

    if(movimenta_cachorro(labirinto, caminho, &movimentacoes, linhas, colunas, iInicial, jInicial) == -1)
        printf("O cachorro se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", movimentacoes);
    else
        imprimeSolucao(caminho, movimentacoes, linhas, colunas, jInicial); //Imprime o caminho
}

/* Função recursiva que utiliza do paradigma Backtrack para encontrar um possível caminho
   para o cachorro chegar ao destino do labirinto - MODO ANÁLISE */
int movimenta_cachorro2 (Labirinto *labirinto, int **caminho, int *movimentacoes, int *chamadasRecursivas,
                        int *maiorNivelRecursao, int nivel, int linhas, int colunas, int i, int j) {
    (*chamadasRecursivas)++; //Variável incrementada toda vez que esta função for chamada
    nivel++;
    caminho[i][j] = 1; //Marcando como posição válida para a matriz de solução
    labirinto->visitou[i][j] = 1;

    /* Se o cachorro conseguiu chegar no topo do labirinto, returna d1 (encontrou um caminho válido) */
    if (i == 0) {
        if (nivel > *maiorNivelRecursao)
            *maiorNivelRecursao = nivel;
        return 1;
    }


    /* Tentando mover o cachorro para cima */
    if (labirinto->cor[i - 1][j] != 3 && labirinto->visitou[i - 1][j] == 0 && i - 1 >= 0) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro2(labirinto, caminho, movimentacoes, chamadasRecursivas,
                                maiorNivelRecursao, nivel, linhas, colunas, i - 1, j) == 1)
            return 1;
    }

    /* Tentando mover o cachorro para a direita */
    if (labirinto->cor[i][j + 1] != 3 && labirinto->visitou[i][j + 1] == 0 && j + 1 < colunas) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro2(labirinto, caminho, movimentacoes, chamadasRecursivas,
                                maiorNivelRecursao, nivel, linhas, colunas, i, j + 1) == 1)
            return 1;
    }

    /* Tentando mover o cachorro para a esquerda */
    if (labirinto->cor[i][j - 1] != 3 && labirinto->visitou[i][j - 1] == 0 && j - 1 >= 0) {
        (*movimentacoes)++; //Incrementando o contador de movimentações do cachorro
        if (movimenta_cachorro2(labirinto, caminho, movimentacoes, chamadasRecursivas,
                                maiorNivelRecursao, nivel, linhas, colunas, i, j - 1) == 1)
            return 1;
    }

    /* Se nenhuma das possibilidades de movimento acima resultarem em uma posição válida,
       será necessário utilizar backtrack */

    caminho[i][j] = 0; //Removendo a posição atual da solução final do problema (atribuindo 0)
    /* Se for a posição inicial do cachorro, o contador de movimentações não deve ser incrementado, pois
       não há nenhuma posição anterior à ela */
    if (labirinto->cor[i][j] == 1)
        (*movimentacoes)++;
    /* Se o nivel de recursão atual for maior do que o maior nível de recursão até o momento */
    if (nivel > *maiorNivelRecursao)
        *maiorNivelRecursao = nivel;

    return -1; //Backtrack ou sem solução
}

/* Função para encapsular a função movimenta_cachorro2 - MODO ANÁLISE */
void solucionaLabirinto2 (Labirinto *labirinto, int linhas, int colunas) {
    int **caminho = alocaCaminho(linhas, colunas); //Matriz de solução - um caminho possível
    int iInicial = linhas - 1; //Linha inicial do cachorro
    int jInicial = colunaInicial(labirinto, linhas, colunas); //Coluna inicial do cachorro
    int movimentacoes = 0; //Quantidade de movimentações do cachorro
    int chamadasRecursivas = 0; //Número de chamadas da função backTrackLabirinto2
    int nivel = 0; //Variável auxiliar responsável por conter o nível de recursão de cada chamada recursiva
    int maiorNivelRecursao = 0; //Representa o maior nível de recursividade da função backTrackLabirinto2

    if(movimenta_cachorro2(labirinto, caminho, &movimentacoes, &chamadasRecursivas, &maiorNivelRecursao, nivel,
                           linhas, colunas, iInicial, jInicial) == -1)
        printf("O cachorro se movimentou %d vezes e percebeu que o labirinto nao tem saida\n", movimentacoes);
    else
        imprimeSolucao(caminho, movimentacoes, linhas, colunas, jInicial); //Imprime o caminho
    printf("Total de chamadas recursivas: %d\n", chamadasRecursivas);
    printf("Maior nivel de recursao: %d\n", maiorNivelRecursao);
}
