/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

void adicionarPalavra(FILE *arquivo, const char *palavra)
{
    fprintf(arquivo, "%s\n", palavra);
}

int consultarPalavra(FILE *arquivo, const char *palavra)
{
    char buffer[MAX_WORD_LENGTH];
    
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, palavra) == 0)
        {
            return 1;
        }
    }
    
    return 0; // palavra não encontrada
}

void excluirPalavra(FILE *arquivo, const char *palavra)
{
    FILE *tempFile = fopen("temp.txt", "w");
    char buffer[MAX_WORD_LENGTH];
    
    while (fgets(buffer, sizeof(buffer), arquivo) != NULL)
    {
        
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, palavra) != 0)
        {
            fprintf(tempFile, "%s\n", buffer);
        }
        
    }
    
    fclose(arquivo);
    fclose(tempFile);
    
    remove("palavras.txt");
    rename("temp.txt", "palavras.txt");
}



int main()
{
    FILE *arquivo = fopen("palavras.txt", "a+");
    
    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    
    int opcao;
    char palavra[MAX_WORD_LENGTH];
    
    do
    {
    
        printf("1 - Adicionar Palavra\n");
        printf("2 - Consultar Palavra\n");
        printf("3 - Excluir Palavra\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
    
        switch(opcao)
        {
            
            case 1:
                printf("Digite a palavra para adicionar: ");
                scanf("%s", palavra);
                adicionarPalavra(arquivo, palavra);
                break;
            case 2:
                printf("Digite a palavra para consultar: ");
                scanf("%s", palavra);
                if (consultarPalavra(arquivo, palavra))
                {
                    printf("A palavra '%s' foi encontrada.\n", palavra);
                }
                else
                {
                    printf("A palavra '%s' não foi encontrada.\n", palavra);
                }
                break;
            case 3:
                printf("Digite a palavra para excluir: ");
                scanf("%s", palavra);
                excluirPalavra(arquivo, palavra);
                printf("A palavra '%s' foi excluída.\n", palavra);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
        
    }while(opcao != 0);

    fclose(arquivo);

    return 0;
}
