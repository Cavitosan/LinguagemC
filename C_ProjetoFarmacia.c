/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>



typedef struct
{
    
    char nome[50];
    int quantidade;
    float preco;

    
} Medicamento;

void exibirMedicamento(Medicamento medicamento)
{
    printf("Nome: %s\n", medicamento.nome);
    printf("Quantidade em estoque: %d\n", medicamento.quantidade);
    printf("Preço: R$%.2f\n", medicamento.preco);
}

int main()
{
 
    setlocale(LC_ALL, "Portuguese");
 
    Medicamento farmacia[3];
    
    strcpy(farmacia[0].nome, "Paracetamol");
    farmacia[0].quantidade = 100;
    farmacia[0].preco = 10.0;
    
    strcpy(farmacia[1].nome, "Buscopan");
    farmacia[1].quantidade = 300;
    farmacia[1].preco = 5.0;
    
    strcpy(farmacia[2].nome, "Aspirina");
    farmacia[2].quantidade = 75;
    farmacia[2].preco = 15.0;
    
    int escolha;
    
    while(true)
    {
        printf("Bem-vindo à Farmácia!\n");
        printf("Escolha uma opção:\n");
        printf("1. Ver medicamentos disponíveis\n");
        printf("2. Comprar medicamento\n");
        printf("3. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);
        
        switch(escolha)
        {
            
            case 1:
                printf("Medicamentos disponíveis:\n");
                for(int i = 0; i < 3; i++)
                {
                    exibirMedicamento(farmacia[i]);
                }
                break;
            case 2:
                int id;
                int quantidadeCompra;
                
                printf("Informe o ID do medicamento que deseja comprar: ");
                scanf("%d", &id);
                
                if(id >= 0 && id < 3)
                {
                    printf("Informe a quantidade desejada: ");
                    scanf("%d", &quantidadeCompra);
                    
                    if(quantidadeCompra <= farmacia[id].quantidade)
                    {
                        printf("Compra realizada com sucesso!\n");
                        farmacia[id].quantidade -= quantidadeCompra;
                    }
                    else
                    {
                        printf("Desculpe, não temos estoque suficiente.\n");
                    }
                }
                else
                {
                    printf("ID de medicamento inválido.\n");
                }
                break;
                
            case 3:
                printf("Obrigado por visitar nossa farmácia. Volte sempre!\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente. \n");
        }
        
    }
    return 0;
}