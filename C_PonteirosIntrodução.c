/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//introdução a ponteiros - Programe seu futuro

void imprimir(int *num) {
    printf("%d\n", *num);
    *num = 80;
}

void alterarvet(int vet[], int tam){
    int i;
    for(i = 0; i < tam; i++)
    {
        vet[i] = vet[i] * 2;
    }
    printf("\n");
}

void imprimirvet(int vet[], int tam){
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("%d ", *(vet + i));
    }
    
    
    printf("\n");
}

typedef struct{
    int dia, mes, ano;
}Data;

void imprimirData(Data *x){
    
    printf("\nFunção Imprimir Data:\n\n %d / %d / %d", x->dia, x->mes, x->ano); //Para manipulação de ponteiros para struct em C é dessa forma

}


int main()
{
    int num = 10;
    int *idade = malloc(sizeof(int));
    *idade = 35;
    
    printf("\nO valor de num é: %d\n", num);
    printf("\nO endereço de num é: %d\n", &num); // Verificando o endereço de memoria da variavel

    int *p;
    
    p = &num;

    printf("\nO valor de p eh: %d\n", p);
    printf("\nO valor apontado por p: %d\n", *p);
    printf("\nEndereço de p: %d\n", &p);

    int *p1; // ponteiro o asterisco fica à esquerda
    char *p2;
    
    printf("Tamanho: %ld\n", sizeof(p1));
    printf("Tamanho: %ld\n", sizeof(p2));

    // O ponteiro é como se fosse uma ceta, um "apontador", logo terá sempre
    // o mesmo tamanho


    //apenas o nome de um vetor já é um ponteiro
    //por isso não usamos & para strings no scanf
    
    imprimir(idade);
    printf("Valor de idade na função main: %d\n", idade);
    
    free(idade);
    
    int vet[10] = {1, 45, 68, 25, 17, 54, 68, 98, 75, 14};
    alterarvet(vet, 10);
    imprimirvet(vet, 10);
    
    Data data;
    Data *pont; // ponteiro para o tipo data

    pont = &data;
    
    printf("data: %p\tp: %p\n", &data, pont);
    
    data.dia = 29;
    data.mes = 2;
    data.ano = 2021;
    
    printf("%d / %d / %d", data.dia, data.mes, data.ano);
    imprimirData(pont);
    
    return 0;
}




