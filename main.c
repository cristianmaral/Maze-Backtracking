#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arquivo.h"
#include "LabirintoCachorro.h"
#include "NRainhas.h"

int main()
{
    FILE *arquivoDeEntrada = NULL;
    Labirinto **labirinto;
    char nomeArquivo[100];
    int opcao, linhas, colunas;

    /* Repetir até que a opção 3 seja escolhida - finaliza o programa */
    while (1) {
        /* MENU */
        printf("+-------------------------------------+\n");
        printf("|        Programa do Labirinto        |\n");
        printf("+-------------------------------------+\n");
        printf("|                 MENU                |\n");
        printf("+-------------------------------------+\n");
        printf("| 1 -> Carregar novo arquivo de dados |\n");
        printf("| 2 -> Processar e exibir respostas   |\n");
        printf("| 3 -> Sair do programa               |\n");
        printf("+-------------------------------------+\n\n");

        printf("Entre com a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                do {
                    fflush(stdin);
                    printf("Entre com o nome do arquivo de entrada: ");
                    scanf("%[^\n]s", nomeArquivo);
                    arquivoDeEntrada = fopen(nomeArquivo, "r");
                    if (arquivoDeEntrada != NULL) {
                        printf("Arquivo %s carregado com sucesso!\n\n", nomeArquivo);
                        labirinto = leLabirintoEntrada(arquivoDeEntrada, &linhas, &colunas);
                    }
                    else {
                        printf("ERRO: Arquivo inexistente!\n");
                    }
                } while (arquivoDeEntrada == NULL);
                break;
            case 2:
                if (arquivoDeEntrada == NULL) {
                    printf("Por favor carregue antes um arquivo de dados!\n");
                    system("PAUSE");
                    printf("\n");
                }
                else {
                    printf("Calculando um possivel caminho para o cachorro...\n");
                    solucionaLabirinto(labirinto, linhas, colunas);
                }
                /* Resetando as visitas para que seja possível se o usuário desejar calcular */
                /* o caminho novamente com o mesmo arquivo de entrada */
                resetaVisitas(labirinto, linhas, colunas);
                break;
            case 3:
                printf("Fim do programa!\n");
                return 0;
            default:
                printf("Opcao invalida!\n\n");
        }
    }
}

/***** MAIN LABIRINTO - CRISTIAN  ****/
/*
int main()
{
      //{0, 0, 1, 0, 1},
      //{1, 0, 0, 1, 1},
      //{0, 1, 1, 0, 1},
     // {1, 1, 1, 1, 1},
     // {1, 1, 1, 1, 0}

    Labirinto **maze = (Labirinto **)malloc(5 * sizeof(Labirinto *));
    int i, j;

    for(i=0; i<N; i++) {
        maze[i] = (Labirinto *)calloc(5, sizeof(Labirinto));
    }

    maze[0][2].valor = 1;
    maze[0][4].valor = 1;
    maze[1][0].valor = 1;
    maze[1][1].valor = 1;
    maze[1][3].valor = 1;
    maze[1][4].valor = 1;
    maze[2][1].valor = 1;
    maze[2][2].valor = 1;
    maze[2][4].valor = 1;
    maze[3][1].valor = 1;
    maze[3][2].valor = 1;
    maze[3][3].valor = 1;
    maze[3][4].valor = 1;
    maze[3][0].valor = 1;
    maze[4][1].valor = 1;
    maze[4][2].valor = 1;
    maze[4][3].valor = 1;
    maze[4][0].valor = 1;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%d ",maze[i][j].valor);
        printf("\n");
    }
    solveMaze(maze, N, N);
    return 0;
}*/

/**** MAIN N_RAINHAS - ANDREY ***/
/*
int main() {
    int matriz[N][N];
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            matriz[i][j] = 0;

    if (achaPosicaoRainha(matriz, 0) == -1)
        printf("Solucao nao existe!");
    else
        mostraSolucao(matriz);
    return 0;
}*/
