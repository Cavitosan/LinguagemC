/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    
    char nome[50];
    int idade;
    float salario;
    
} Funcionario;

int main()
{
    int numFuncionarios = 3;
    
    Funcionario** funcionarios = (Funcionario**)malloc(numFuncionarios * sizeof(Funcionario*));
    
    for(int i = 0; i < numFuncionarios; i++)
    {
        funcionarios[i] = (Funcionario*)malloc(sizeof(Funcionario));
        
        printf("Informe o nome do funcionario %d: ", i + 1);
        scanf("%s", funcionarios[i]->nome);
        
        printf("Informe a idade do funcionario %d: ", i + 1);
        scanf("%d", &funcionarios[i]->idade);
        
        printf("Informe o salario do funcionario %d: ", i + 1);
        scanf("%f", &funcionarios[i]->salario);
        
    }
    
    
    printf("\nFuncionarios cadastrados: \n");
    for(int i = 0; i < numFuncionarios; i++)
    {
        printf("Nome: %s\n", funcionarios[i]->nome);
        printf("Idade: %d\n", funcionarios[i]->idade);
        printf("Salario: %f\n", funcionarios[i]->salario);
        printf("\n";
        
    }
    
    for(int i = 0; i < numFuncionarios; i++)
    {
        free(funcionarios[i]);
    }
    
    free(funcionarios);
    
    return 0;
}
