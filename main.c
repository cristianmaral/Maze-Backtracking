#include <stdio.h>
#include <stdlib.h>
#include "LabirintoCachorro.h"


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
}
