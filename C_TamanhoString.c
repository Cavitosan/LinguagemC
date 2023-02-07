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


int tamanhoString(char str[]){
    int tam = 0;
    while(str[tam] != '\0'){
        tam++;
    }
    return tam;
    
}

void imprimirString(char palavra[]){
    int i = 0;
    int tam = 0;
    
    while(palavra[i] != '\0'){
        printf("%c", palavra[i]);
        i++;
        tam++;
    }
    printf("\n");
    printf("\nTamanho da palavra: %d\n", tam);
    
}

int main()
{
    printf("C - Aula146: Função que retorna tamanho de string");

    setlocale(LC_ALL, "Portuguese");
    printf("\n\n");
    
    char vet[20] = {"Ola. Hoje é domingo."};
    
    int tchar = strlen(vet);
    
    printf("Strlen: %d\n\n", strlen(vet));
    
    printf("Minha função: %d\n\n", tamanhoString(vet));
    
    
    printf("C - Aula147: Procedimento para imprimir string char por char\n");

    imprimirString(vet);
    

    return 0;
}





