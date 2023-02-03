/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //necessário para a função objeto do script

//procedimento que converte string para maiscula

void maiusculo(char s1[], char s2[]){
    int i = 0;
    
    while(s1[i] != '\0'){
        s2[i] = toupper(s1[i]);
        i++;
    }
    s2[i] = '\0';
}


//procedimento que converte string para minusculo

void minusculo(char s1[], char s2[]){
    int i = 0;
    
    while(s1[i] != '\0'){
        s2[i] = tolower(s1[i]);
        i++;
    }
    s2[i] = '\0';
}

int main()
{
    printf("C - Aula151: ConverterString em Maisculo ou Minusculo\n");
    
    //strupr(); Essas funções só funcionam no windows!
    //strlwr();
    
    char str1[] = "Ola.Bom dia";
    char str2[50];
    
    maiusculo(str1, str2);
    printf("String Original: %s\n", str1);
    printf("String Toupper:  %s\n", str2);
    
    printf("\n");
    
    minusculo(str1, str2);
    printf("String Original: %s\n", str1);
    printf("String Tolower:  %s\n", str2);
    
    return 0;
}
