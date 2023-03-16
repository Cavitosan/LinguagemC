/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// variaveis globais x 0 " "
char jogo[3][3];
int l, c;

//procedimento para inicializar todas as posições da matriz
void inicializarMatriz(){
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            jogo[l][c] = ' ';
        }
    
    }
}

void imprimir(){
    printf("\n\n\t 0   1   2\n");
    
    for (l = 0; l < 3; l++) {
        for (c = 0; c < 3; c++) {
            if(c == 0) {
                printf("\t");
            }
            printf(" %c ", jogo[l][c]);
            if (c < 2) {
                printf("|");
            }
            if (c == 2) {
                printf(" %d", l);
            }
        }
        printf("\n");
        if (l < 2) {
            printf("\t-----------\n");
        }
    }
}

/*função para verificar vitoria por linha
* 1 == ganhou
* 0 == não ganhou ainda
*/

int ganhouPorLinha(int l, char c) {
    if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c) {
        return 1;
    }else {
        return 0;
    }
}

/*função para verificar vitoria por linhas
* 1 == ganhou
* 0 == não ganhou ainda
*/

int ganhouPorLinhas(char c){
    int ganhou = 0;
    for (l = 0; l < 3; l++) {
        ganhou += ganhouPorLinha(l, c);
    }
    return ganhou;
}

/*
* função para verificar vitoria em uma(1) coluna
*1 == ganhou 
*0 == não ganhou ainda
*/
int ganhouPorColuna(int c, char j){
    if (jogo[0][c] == j && jogo[1][c] && jogo[2][c] == j){
        return 1;
    }else {
        return 0;
    }
    
}

//função para verificar vitoria em mais de 1 coluna
int ganhouPorColunas(char j){
    int ganhou = 0;
    for (c = 0; c < 3; c++) {
        ganhou += ganhouPorColuna(c, j);
        
    }
    return ganhou;
}

//função para verificar vitoria em diagonal principal
int ganhouPorDiagPrin(char c){
    if(jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c){
        return 1;
    }else {
        return 0;
    }
    
}

//função para verificar vitoria em diagonal secundaria
int ganhouPorDiagSec(char c){
    if(jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c){
        return 1;
    }else {
        return 0;
    }
    
}


//Função que diz se uma coordenada é válida ou não
int ehValida(int l, int c){
    if (l >= 0 && l < 3 && c >= 0 && c < 3 && jogo[l][c] == ' ') {
        return 1;
    }else {
        return 0;
    }
    
}

//procedimento para ler as coordenadas do jogador
void lerCoordenadas(char j){
    int linha, coluna;
    
    printf("Digite a linha e a coluna: ");
    scanf("%d%d", &linha, &coluna);
    
    while(ehValida(linha, coluna) == 0){
        printf("Coordenadas inválidas! Digite outra linha e coluna: ");
        scanf("%d%d", &linha, &coluna);
    }
    jogo[linha][coluna] = j;
}
//Funçãp que retorna a quantidade de posições vazias
int quantVazias(){
    int quantidade = 0;
    
    for (l = 0; l < 3; l++){
        for(c = 0; c < 3; c++) {
            if (jogo[l][c] = ' ') {
                quantidade++;
            }
        }
    }
    return quantidade;
    
}


//procedimento jogar com o loop principal do Jogo
void jogar() {
    int jogador = 1, vitoriaX = 0, vitoria0 = 0;
    char jogador1 = 'X', jogador2 = '0';
    
    do{
        imprimir();
        
        if (jogador == 1) {
            lerCoordenadas(jogador1);
            jogador++;
            vitoriaX += ganhouPorLinhas(jogador1);
            vitoriaX += ganhouPorColunas(jogador1);
            vitoriaX += ganhouPorDiagPrin(jogador1);
            vitoriaX += ganhouPorDiagSec(jogador1);
            
           
            
            
            
        }else {
            lerCoordenadas(jogador2);
            jogador = 1;
            vitoria0 += ganhouPorLinhas(jogador2);
            vitoria0 += ganhouPorColunas(jogador2);
            vitoria0 += ganhouPorDiagPrin(jogador2);
            vitoria0 += ganhouPorDiagSec(jogador2);
            
        }
        
    }while(vitoriaX == 0 && vitoria0 == 0 && quantVazias > 0);
    
    imprimir();
    
    if(vitoria0 == 1) {
        printf("\nParabens jogador 2! Voce venceu!\n");
    }else if (vitoriaX == 1) {
        printf("\nParabens jogador 1! Voce venceu!\n");
    }else {
        printf("\nQue pena! Deu empate! Ambos vocês perderam!\n");
    }
    
}

int main()
{
    printf("C -  Jogo da Velha\n\n");
    
    int opcao;
    
    do {
        inicializarMatriz();
        jogar();
    
        printf("\nDigite 1 para jogar novamente!\n");
        scanf("%d", &opcao);
        
    }while(opcao == 1);
    

    return 0;
}




