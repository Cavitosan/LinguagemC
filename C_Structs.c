/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    int idade;
    char curso[30];
}Pessoa;

//função que lê os dados de uma pessoa e retorna para quem chamou
Pessoa lerPessoa(){
    Pessoa pessoa;
    
    printf("Informe o nome da pessoa: ");
    scanf("%s", pessoa.nome);
    
    printf("Informe a idade da pessoa: ");
    scanf("%d", &pessoa.idade);
    
    printf("Informe o curso da pessoa: ");
    scanf("%s", pessoa.curso);
    
    return pessoa;
}

Pessoa imprimirPessoa(Pessoa pessoa){
    printf("\n");
    printf("====================");
    printf("\tNome da pessoa: %s\n", pessoa.nome);
    printf("\tIdade da pessoa: %d\n", pessoa.idade);
    printf("\tCurso da pessoa: %s\n", pessoa.curso);
    printf("====================");
    printf("\n\n");
}


int main()
{
    printf("===== C_Structs - função que retorna uma struct =====\n\n");

    int i = 0;
    Pessoa pessoa;
    Pessoa pessoa_vetor[3];

    pessoa = lerPessoa();
    imprimirPessoa(pessoa);

    for(i = 0; i < 3; i++) {
        pessoa_vetor[i] = lerPessoa();
    }
    
    for(i = 0; i < 3; i++) {
        imprimirPessoa(pessoa_vetor[i]);
    }

    return 0;
}

