/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

 // Definição da estrutura
typedef struct{
    int valor;
} MinhaClasse;

// Função para inicializar a estrutura
void inicializar(MinhaClasse *objeto, int valor){
    objeto->valor = valor;
}

//Função para exibir o valor de estrutura
void exibir(MinhaClasse *objeto){
    printf("Valor: %d\n", objeto->valor);
}

int main()
{
    //Criação de uma instancia da estrutura
    MinhaClasse objeto;

    // Inicializar do objeto
    inicializar(&objeto, 10);
    
    //Exibição do valor do objeto
    exibir(&objeto);
    
    return 0;
}
