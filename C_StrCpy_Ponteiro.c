/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void strcpy_custom(char *destino, char *origem)
{
    while(*origem != '\0')
    {
        *destino = *origem;
        destino++;
        origem++;
    }

    *destino = '\0'; // Adiciona o caractere nulo no final da string
}

int main()
{
    char origem[] = "Olá, Mundo!";
    char destino[20];
    
    strcpy_custom(destino, origem);
    
    printf("String de origem: %s\n", origem);
    printf("String de destino: %s\n", destino);

    return 0;
}
