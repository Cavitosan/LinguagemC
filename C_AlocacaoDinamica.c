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
    int tamanho;
    
    printf("Informe o tamanho do array: ");
    scanf("%d", &tamanho);
    
    // Alocação dinâmica de memória para o array de inteiros
    int *array = (int *)malloc(tamanho * sizeof(int));
    
    if(array == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }
    
    // Preenchendo o array com valores
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = i * 10;
    }
    
    // Exibindo os valores do array
    printf("Valores do array:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n");
    
    // Liberando a memória alocada
    free(array);
    
    return 0;
}
