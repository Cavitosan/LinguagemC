/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <locale.h>

//Encontrar o menor e o maior

void encontrarMinMax(int matriz[], int tamanho, int *min, int *max){
    *min = matriz[0];
    *max = matriz[0];
    
    for(int i = 1; i < tamanho; i++)
    {
        if(matriz[i] < *min)
        {
            *min = matriz[i];
        }
        if(matriz[i] > *max)
        {
            *max = matriz[i];
        }
        
    }
}


int main()
{
    int matriz[] = {5, 8, 2, 10, 1};
    int tamanho = sizeof(matriz) / sizeof(matriz[0]);
    int min, max;
    
    setlocale(LC_ALL, NULL);
    
    encontrarMinMax(matriz, tamanho, &min, &max);
    
    printf("O menor elemento da matriz é: %d\n", min);
    printf("O maior elemento da matriz é: %d\n", max);


    return 0;
}
