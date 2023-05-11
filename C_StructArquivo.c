/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nome[50];
    float salario;
} Funcionario;

void salvarFuncionarios(Funcionario* funcionario, int quantidade)
{
    FILE* arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return;
    }
    
    for (int i = 0; i < quantidade; i++)
    {
        fprintf(arquivo, "%d;%s;%.2f\n", funcionario[i].id, funcionario[i].nome, funcionario[i].salario);
    }
    
    fclose(arquivo);
    printf("Dados dos funcionarios salvos com sucesso.\n");
    
}

void carregarFuncionarios()
{
    FILE* arquivo = fopen("funcionarios.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo. \n");
        return;
    }
    
    printf("Funcionarios cadastrados: \n");
    
    Funcionario funcionario;
    
    while(fscanf(arquivo, "%d;%[^;];%f\n", &funcionario.id, funcionario.nome, &funcionario.salario) != EOF)
    {
        printf("ID: %d\n", funcionario.id);
        printf("Nome: %s\n", funcionario.nome);
        printf("Salario: %.2f\n", funcionario.salario);
        printf("\n");
    }
    
    fclose(arquivo);
}


int main()
{
    
    int quantidadeFuncionarios;
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &quantidadeFuncionarios);
    
    Funcionario* funcionarios = (Funcionario*) malloc(quantidadeFuncionarios * sizeof(Funcionario));

    for (int i = 0; i < quantidadeFuncionarios; i++)
    {
        printf("Digite o ID do funcionario: ");
        scanf("%d", &funcionarios[i].id);
        
        printf("Digite o nome do funcionario: ");
        scanf(" %[^\n]", funcionarios[i].nome);
        
        printf("Digite o salario do funcionario: ");
        scanf("%f", &funcionarios[i].salario);
        
        printf("\n");
        
    }

    salvarFuncionarios(funcionarios, quantidadeFuncionarios);
    free(funcionarios);
    carregarFuncionarios();

    return 0;
}
