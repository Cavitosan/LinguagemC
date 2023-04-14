/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int num_conta;
    float saldo;
}Conta;

int main()
{
    Conta conta;
    int opcao;
    float valor;
    
    printf("Bem-vindo ao sistema bancario!\n");
    printf("Digite o numero da conta: ");
    scanf("%d", &conta.num_conta);
    conta.saldo = 0.0;
    
    while(1)
    {
        printf("\nEscolha uma opção: \n");
        printf("1 - Deposito\n");
        printf("2 - Saque\n");
        printf("3 - Ver Saldo\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Digite o valor do deposito: ");
                scanf("%f", &valor);
                conta.saldo += valor;
                printf("Deposito realizado com sucesso!\n");
                break;
            case 2:
                printf("Digite o valor do saque: ");
                scanf("%f", &valor);
                if (valor > conta.saldo) 
                {
                    printf("Saldo insuficiente.\n");
                }else{
                    conta.saldo -= valor;
                    printf("Saque realizado com sucesso!\n");
                    }
                break;
            case 3:
                printf("Saldo atual: R$%.2f\n", conta.saldo);
                break;
            case 4:
                printf("Obrigado por utilizar nosso sistema bancario!\n");
                exit(0);
            default:
                printf("Opção inválido. Favor digitar novamente.\n");
                break;
        }
        
    }
    
    return 0;
}

