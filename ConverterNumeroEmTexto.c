/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    printf("C - Aula152: Converter número em texto\n\n");
    
    int tam;
    char str1[10] = {"%"}, str2[10];
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    scanf(" %c");
    
    //sprintf(str2, "%d[^\n]", tam);//imprime o valor em variavel3
    snprintf(str2, 10, "%d[^\n]", tam); //A saída resultante é colocada na variável indicada
    //printf("%s\n", str2);
    strcat(str1, str2);
    
    printf("%s\n", str2);
    
    
    char palavras[tam];
    
    /*printf("Digite uma frase: ");
    scanf("%50[^\n]", palavras);*/
    
    
    //char palavras[tam];
    printf("Digite uma frase: \n");
    scanf(str1, palavras);
    printf("%s\n", str1);

    return 0;
}

