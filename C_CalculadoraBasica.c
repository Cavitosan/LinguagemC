/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("----- ========== CALCULADORA ========== -----\n\n");
    
    int num1, num2, opcao;
    
    do{
    
    printf("\nInforme o valor do número 1: ");
    scanf("%d", &num1);
    
    printf("\nInforme o valor do número 2: ");
    scanf("%d", &num2);
    
    
    printf("\nSelecione a operação que deseja realizar para esses números: %d -- %d ", num1, num2);
    printf("\n 1 - Soma\n 2 - Subtração\n 3 - Multiplicação\n 4 - Divisão\n 5 - Par ou Impar\n 0 - Sair do programa\n >>> ");
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            printf("\nA operação selecionada foi SOMA: %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("\nA operação selecionada foi SUBTRAÇÃO: %d - %d = %d\n", num1, num2, num1 - num2);        
            break;
        case 3:
            printf("\nA operação selecionada foi MULTIPLICAÇÃO: %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4:
            if(num1 && num2 != 0)
            {
                printf("\nA operação selecionada foi DIVISAO: %d / %d = %.3f\n", num1, num2, (float)num1 / (float)num2);
            }
            else
            {
                printf("\nNão é possível divisão por 0...\n");    
            }
            break;
        case 5:
            //Verificando o valor 1
            if(num1 % 2 == 0)
            {
                printf("\nO valor 1: %d - é um número par!\n", num1);
            }
            else
            {
                printf("\nO valor 1: %d - é um número ímpar!\n", num1);
            }
            
            //Verificando o valor 2
            if(num2 % 2 == 0)
            {
                printf("\nO valor 2: %d - é um número par!\n", num2);
            }
            else
            {
                printf("\nO valor 2: %d - é um número ímpar!\n", num2);
            }
            
            
        case 0:
            printf("Saindo do programa...");
            break;
        default:
            printf("\nValor inválido...\n");
            break;
    }
        
    }while(opcao != 0);

    return 0;
}
