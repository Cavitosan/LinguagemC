/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/*
* A ideia principal de uma union é que todos os seus membros 
* compartilham o mesmo espaço de memória, de modo que o 
* tamanho total da union é o tamanho do maior membro.
*/

union Dados
{
    int valorInteiro;
    float valorReal;
    char caractere;
};


int main()
{
    union Dados meuDado;
    
    meuDado.valorInteiro = 42;
    printf("Valor inteiro: %d\n", meuDado.valorInteiro);
    
    meuDado.valorReal = 3.14;
    printf("Valor real: %.3f\n", meuDado.valorReal);
    
    meuDado.caractere = 'A';
    printf("Caractere: %c\n", meuDado.caractere);
    
    printf("Tamanho da Union: %lu bytes", sizeof(meuDado)); //lu == long unsigned

    return 0;
}
