/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//Utilizando enums

// Definindo um enum para dias da semana

enum DiasSemana
{
  DOMINGO,
  SEGUNDA,
  TERCA,
  QUARTA,
  QUINTA,
  SEXTA,
  SABADO
};

int main()
{
    // Declarando uma variavel do tipo enum DiasSemana
    enum DiasSemana diaAtual;
    
    diaAtual = QUARTA;
    
    switch(diaAtual)
    {
        case DOMINGO:
            printf("Hoje é domingo...");
            break;
        case SEGUNDA:
            printf("Hoje é segunda...");
            break;
        case TERCA:
            printf("Hoje é terça...");
            break;
        case QUARTA:
            printf("Hoje é quarta...");
            break;
        case QUINTA:
            printf("Hoje é quinta...");
            break;
        case SEXTA:
            printf("Hoje é sexta...");
            break;
        case SABADO:
            printf("Hoje é sabado...");
            break;
        default:
            printf("Não sei que dia é hoje...");
            break;
    }

    return 0;
}
