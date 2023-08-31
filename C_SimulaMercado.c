/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_PRODUCTS 100

struct Product 
{
    char name[50];
    float price;
};

struct Cart 
{
    struct Product products[MAX_PRODUCTS];
    int itemCount;
};

void addToCart(struct Cart *cart, struct Product product)
{
    if(cart->itemCount < MAX_PRODUCTS)
    {
        cart->products[cart->itemCount] = product;
        cart->itemCount++;
        printf("%s adicionado ao carrinho.\n", product.name);
    }
    else
    {
        printf("Carrinho está cheio. Não é possível adicionar mais produtos.\n");
    }
}

float calculateTotal(struct Cart cart)
{
    float total = 0;
    for(int i = 0; i < cart.itemCount; i++)
    {
        total += cart.products[i].price;
    }
    return total;
}


int main()
{
    struct Cart cart;
    cart.itemCount = 0;
    
    struct Product products[] = {
        {"Arroz", 10.9},
        {"Feijao", 5.2},
        {"Macarrao", 3.0},
        //Adicione mais produtos aqui
    };
    
    int numProducts = sizeof(products) / sizeof(products[0]);
    
    printf("Bem-vindo ao Supermercado Simulado.\n");
    
    while(1)
    {
        printf("\nProdutos disponíveis: \n");
        for(int i = 0; i < numProducts; i++)
        {
            printf("%d. %s - R$%.2f\n", i + 1, products[i].name, products[i].price);
        }
        
        int choice;
        printf("Digite o número do produto que deseja adicionar ao carrinho (0 para sair): ");
        scanf("%d", &choice);
        
        if(choice == 0)
        {
            break;
        }else if (choice >= 1 && choice <= numProducts)
        {
            addToCart(&cart, products[choice - 1]);
        }
        else
        {
            printf("Escolha inválida.\n");
        }
        
    }
    
    printf("\nItens no carrinho: \n");
    for(int i = 0; i < cart.itemCount; i++)
    {
        printf("%s - R$%.2f\n", cart.products[i].name, cart.products[i].price);
    }
    
    float total = calculateTotal(cart);
    printf("Total da compra: R$%.2f", total);
    printf("\nObrigado por comprar conosco.\n");
    
    
    return 0;
}
