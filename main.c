#include "Arquivo.h"
#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                    getchar();
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
                    solucionaLabirinto2(labirinto, linhas, colunas);
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
