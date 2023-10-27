
#include <stdio.h>
#include <locale.h>

#define SIZE 6

void imprimirTrianguloEsquerda(int matriz[SIZE][SIZE])
{
    int i, j;
    
    printf("Triângulo à esquerda: \n");
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(j <= i)
            {
                matriz[i][j] = 1; //Marca os elementos do triangulo à esquerda
            }
            else
            {
                matriz[i][j] = 0; // Marca o resto como 0
            }
            printf("%d ", matriz[i][j]); // Imprime a matriz
        }
        printf("\n");
    }
}


void imprimirTrianguloDireita(int matriz[SIZE][SIZE])
{
    int i, j;
    
    printf("Triângulo à direita: \n");
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(j >= i)
            {
                matriz[i][j] = 1; //Marca os elementos do triangulo à direita
            }
            else
            {
                matriz[i][j] = 0; // Marca o resto como 0
            }
            printf("%d ", matriz[i][j]); // Imprime a matriz
        }
        printf("\n");
    }
        
    
}

void imprimirTrianguloPrimeirasLinhas(int matriz[SIZE][SIZE])
{
    int i, j;
    
    printf("Triângulo nas primeiras linhas: \n");
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i <= j)
            {
                matriz[i][j] = 1; //Marca os elementos do triangulo nas primeiras linhas
            }
            else
            {
                matriz[i][j] = 0; // Marca o resto como 0
            }
            printf("%d ", matriz[i][j]); // Imprime a matriz
        }
        printf("\n");
    }
    
}
    
void imprimirTrianguloUltimasLinhas(int matriz[SIZE][SIZE])
{
    int i, j;
    
    printf("Triângulo nas últimas linhas: \n");
    
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(i >= j)
            {
                matriz[i][j] = 1; //Marca os elementos do triangulo nas últimas linhas
            }
            else
            {
                matriz[i][j] = 0; // Marca o resto como 0
            }
            printf("%d ", matriz[i][j]); // Imprime a matriz
        }
        printf("\n");
    }
    
}



int main()
{
    int matriz[SIZE][SIZE];
    
    imprimirTrianguloEsquerda(matriz);
    imprimirTrianguloDireita(matriz);
    imprimirTrianguloPrimeirasLinhas(matriz);
    imprimirTrianguloUltimasLinhas(matriz);

    return 0;
}
