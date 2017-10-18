#include <stdio.h>
#include <stdlib.h>
#include "LabirintoCachorro.h"

/*
int main()
{
    int opcao;

    while (1) {
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
                break;
            case 2:
                break;
            default:
                printf("Opcao invalida!\n\n");
        }
    }
    return 0;
}*/

int main()
{
    /*{0, 0, 1, 0, 1},
      {1, 0, 0, 1, 1},
      {0, 1, 1, 0, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0}*/

    Maze maze[N][N];
    int i, j;

    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            maze[i][j].valor = 0;
            maze[i][j].visitou = 0;
        }
    }
    //maze[0][0].valor = 1;
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
    solveMaze(maze);
    return 0;
}
