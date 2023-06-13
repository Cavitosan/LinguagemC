/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void fibonacci(int n){
    int i, a = 0, b = 1, c;
    
    printf("\nSequência de Fibonacci: \n");
    
    for(i = 0; i < n; i++)
    {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    
}

void metodoBolha(int arr[], int n)
{
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int ehPrimo(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    
    for(int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    setlocale(LC_ALL, NULL);
    srand(time(NULL));
    
    int opcao, num = 0, i = 0;
    int vetor[10];
    
    
    printf("Informe uma opção de programa.\n");
    printf("\n 1 >> Fibonacci\n 2 >> Ordenação de Vetor\n 3 >> Verificação de número primo\n 4 >> Sair\n >> ");
    scanf("%d", &opcao);
    
    if (opcao >= 1)
    {
        switch(opcao)
        {
            case 1:
                printf("\nInforme um valor de termos desejados: \n");
                scanf("%d", &num);
                fibonacci(num);
                break;
                
            case 2:
                for(i = 0; i < 10; i++)
                {
                    vetor[i] = rand() %100;
                }
                
                metodoBolha(vetor, 10);
                
                for(i = 0; i < 10; i++)
                {
                    printf("%d ", vetor[i]);
                }
                
            case 3:
                printf("\nDigite um número:\n>> ");
                scanf("%d", &num);
                
                if(ehPrimo(num))
                {
                    printf("\n%d é um número primo.\n", num);
                }
                else
                {
                    printf("\n%d não é um número primo.\n", num);
                }
                break;
        }
        
    }
    else if (opcao == 4)
    {
        printf("\nSaindo do programa...");
        
    }
    else
    {
        printf("\nValor inválido! Saindo do programa...\n");
        
    }
    
    
    return 0;
}
