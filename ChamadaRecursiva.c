/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void imprimir(int x){
    
    if (x == 0){
        printf("%d ", x);
    }else{
        printf("%d ", x);
        imprimir(x - 1);
    }
        
}

void imprimirCrescente(int x){
    
    if (x == 0){
        printf("%d ", x);
    }else{
        imprimirCrescente(x - 1);
        printf("%d ", x);
        
    }
        
}

int main()
{
    printf("C - Aula153: Procedimentos recursivos\n\n");
    
    int n;
    
    printf("Digite um valor maior que zero: ");
    scanf("%d", &n);
    
    //imprimir(n);
    imprimirCrescente(n);
    
    

    return 0;
}

