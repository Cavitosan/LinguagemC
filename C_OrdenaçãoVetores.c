/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    
    printf("C - Exercícios Lista de Vetores 7");
    
    int contador = 0, troca = 0, i, j, aux, vetor[100] = {}; //o método bubblesort funciona a depender da quantidade de elementos no array. Se array[10] então o método deve ser realizado 10x
    
    printf("\n\n");
    
    for (i = 0; i < 100; i++){
        vetor[i] = rand() % 1000; //o resto será no máximo 999
    }
    
    printf("\nVetor sem ordenação: \n\n");
    for(i = 0; i < 100; i++){
        printf("%.3d ", vetor[i]);
        if (i % 3 == 0){
            printf("\n");
        }
    }
    
    /*for(j = 1; j <= 100; j++){
        for(i = 0; i < 100 - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                
            }
        }

    } *///método bubblesort é ineficiente. Maneira mais eficiente abaixo:
    
    do{ 
        troca = 0;
        contador ++;
        for(i = 0; i < 100 - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1;
            }
            
        }

    }while(troca); //mesma coisa que troca == 1, ou troca == true
    
    printf("Pressione uma tecla para continuar: ");
    getchar();
    
    printf("\nContador: %d - Vetor ordenado: \n", contador);
    for (i = 0; i < 100; i++){
        printf("%.3d ", vetor[i]);
        if (i % 3 == 0){
            printf("\n");
        }
    }
    

    return 0;
}

