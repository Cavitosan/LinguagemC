/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main()
{
    printf("\nJogo da Adivinhação de Palavras em C\n");
    
    char secret_word[MAX_LENGTH] = "hello";
    char guess[MAX_LENGTH];
    int lives = 5;

    printf("\n---------- Bem-vindo ao Adivinhe a Palavra! ----------\n");
    printf("Voce possui %d vidas restando.\n", lives);
    printf("Digite seu palpite: ");
    
    while(lives > 0){
        
        scanf("%s", guess);
        
        if(strcmp(guess, secret_word) == 0){
            printf("\nParabéns! Você informou a palavra correta!\n");
            break; //sai do loop
        }else{
            printf("\nErrado!Tente de novo!\n");
            lives --;
            printf("\nVoce possui %d vidas restando.", lives);
        }
        
    }
    
    if (lives == 0){
        printf("\n---------- GAME OVER --------");
        printf("\nA palavra correta era: %s\n", secret_word);
    }
    

    return 0;
}
