/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor = 42;
    int *ponteiro = NULL;
    
    // Atribuindo o endereço da variável valor ao ponteiro
    ponteiro = &valor;
    
    printf("Valor: %d\n", valor);
    printf("Endereço de valor: %p\n", &valor);
    printf("Valor do ponteiro: %d\n", *ponteiro);
    printf("Endereço armazenado no ponteiro: %p\n", ponteiro);
    
    // Alocação dinâmica de memória para um inteiro
    
    int *ponteiro_dinamico = (int *)malloc(sizeof(int));
    if (ponteiro_dinamico == NULL)
    {
        printf("Erro na alocação de memória.\n");
        return 1;
    }
    
    *ponteiro_dinamico = 100;
    
    printf("\nValor armazenado no ponteiro dinamico: %d\n", *ponteiro_dinamico);
    
    free(ponteiro_dinamico);
    
    return 0;
}
