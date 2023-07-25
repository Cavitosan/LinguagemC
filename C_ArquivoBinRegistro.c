/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "dados.bin"
#define MAX_NAME_LENGTH 50

typedef struct{
    int id;
    char name[MAX_NAME_LENGTH];
} Registro;

void adicionarRegistro()
{
    Registro novoRegistro;
    
    printf("Digite o ID do registro: ");
    scanf("%d", &novoRegistro.id);
    printf("Digite o nome do registro: ");
    scanf(" %[^\n]", novoRegistro.name); //ignorando espaçoes em branco antes da string
    
    FILE* file = fopen(FILENAME, "ab");
    
    /*
    *Este comando está usando a função fopen, que é usada para abrir um 
    *arquivo em C. Nesse caso, o comando está tentando abrir um arquivo 
    *chamado dados.bin em modo binário ("b") para escrever ("a").
    */
    
    if(file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fwrite(&novoRegistro, sizeof(Registro), 1, file);
    fclose(file);
    printf("Registro adicionado com sucesso.\n");
}


void buscarRegistro(int id)
{
    Registro registro;
    
    FILE* file = fopen(FILENAME, "rb");
    if(file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    while(fread(&registro, sizeof(Registro), 1, file) == 1)
    {
        if(registro.id = id)
        {
            printf("Registro encontrado:\n");
            printf("ID: %d\n", registro.id);
            printf("Nome: %s\n", registro.name);
            fclose(file);
            return;
        }
    }
    
    printf("Registro com ID %d não encontrado.\n", id);
    fclose(file);
}


void editarRegistro(int id)
{
    Registro registro;
    
    FILE* file = fopen(FILENAME, "r+b");
    if(file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    while(fread(&registro, sizeof(Registro), 1, file) == 1)
    {
        if(registro.id == id)
        {
            printf("Digite o novo nome do registro: ");
            scanf(" %[^\n]", registro.name);
            
            fseek(file, -sizeof(Registro), SEEK_CUR);
            fwrite(&registro, sizeof(Registro), 1, file);
            fclose(file);
            printf("Registro editado com sucesso.\n");
            return;
        }
    }
    
    printf("Registro com ID %d nao encontrado.\n", id);
    fclose(file);
}

void excluirRegistro(int id)
{
    FILE* tempFile = fopen("temp.bin", "wb");
    if(tempFile == NULL)
    {
        printf("Erro ao abrir o arquivo temporário.\n");
        return;
    }
    
    Registro registro;
    
    FILE* file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        fclose(tempFile);
        return;
    }
    
    while(fread(&registro, sizeof(Registro), 1, file) == 1)
    {
        if(registro.id != id)
        {
            fwrite(&registro, sizeof(Registro), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    if(remove(FILENAME) == 0)
    {
        if(rename("temp.bin", FILENAME) == 0)
        {
            printf("Registro excluido com sucesso.\n");
        }
        else
        {
            printf("Erro ao renomear o arquivo temporário.\n");
        }
    
    }
    else
    {
        printf("Erro ao excluir o registro.\n");
    }
    
}


int main()
{
    
    int opcao, id;
    
    while(1)
    {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar registro\n");
        printf("2 - Buscar registro por ID\n");
        printf("3 - Editar registro por ID\n");
        printf("4 - Excluir registro por ID\n");
        printf("5 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                adicionarRegistro();
                break;
            case 2:
                printf("Digite o ID do registro que deseja buscar: ");
                scanf("%d", &id);
                buscarRegistro(id);
                break;
            case 3:
                printf("Digite o ID do registro que deseja editar: ");
                scanf("%d", &id);
                editarRegistro(id);
                break;
            case 4:
                printf("Digite o ID do registro que deseja excluir: ");
                scanf("%d", &id);
                excluirRegistro(id);
            case 5:
                printf("C out...\n");
                exit(0);
            default:
                printf("Opçao invalida.\n");
        }
        
    }
    
    return 0;
}
