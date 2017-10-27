#include "Arquivo.h"
#include "LabirintoCachorro.h"
#include <stdio.h>
#include <stdlib.h>

#define ANALISE
//#undef ANALISE

int main()
{
    FILE *arquivoDeEntrada = NULL;
    Labirinto **labirinto;
    char nomeArquivo[1000]; //O nome do arquivo de entrada pode ter no máximo 999 caracteres
    int opcao, linhas, colunas;

    /* Repetir até que a opção 3 seja escolhida - finaliza o programa */

    while (1) {
        /* MENU */
        printf("+--------------------------------------+\n");
        #ifndef ANALISE
            printf("\t\t   |        Programa do Labirinto         |\n");
        #else
            printf("| Programa do Labirinto - Modo Analise |\n");
        #endif
        printf("+--------------------------------------+\n");
        printf("|                 MENU                 |\n");
        printf("+--------------------------------------+\n");
        printf("| 1 -> Carregar novo arquivo de dados  |\n");
        printf("| 2 -> Processar e exibir respostas    |\n");
        printf("| 3 -> Sair do programa                |\n");
        printf("+--------------------------------------+\n\n");

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
                        fclose(arquivoDeEntrada);
                    }
                    else {
                        printf("ERRO: Arquivo inexistente!\n");
                    }
                } while (arquivoDeEntrada == NULL);
                break;
            case 2:
                if (arquivoDeEntrada == NULL)
                    printf("\nPor favor carregue antes um arquivo de dados!\n\n");
                else {
                    printf("\nCalculando um possivel caminho para o cachorro...\n\n");
                    #ifndef ANALISE
                        solucionaLabirinto(labirinto, linhas, colunas);
                    #else
                        solucionaLabirinto2(labirinto, linhas, colunas);
                    #endif
                    printf("\n");
                    /* Resetando as visitas para que seja possível calcular um caminho se o usuário
                       desejar calcular o caminho novamente com o mesmo arquivo de entrada */
                    resetaVisitas(labirinto, linhas, colunas);
                }
                break;
            case 3:
                printf("\nFim do programa do Labirinto!\n");
                return 0;
            default:
                printf("\nOpcao invalida!\n\n");
        }
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();
        system("clear");
    }
}
