/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Jogo da Velha//

#include <stdio.h> // printf - scanf
#include <stdlib.h> // system ("clear")
#include <conio.h> // gecth()


int main()
{
    void tabuleiro();
    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //Declaração do vetor
    char res; // variavel resposta de jogar novamente
    int cont_jogadas, jogada, i; //contador, jogada no programa, contador para limpar a função
    int vez = 0; // Como a vez é iniciada em 0, a primeira jogada será par, ver linha 41
    
    tabuleiro (casas);

    do{ //O jogo já é iniciado de uma vez, sem opção selecionar não em primeiro momento
        cont_jogadas = 1;
        for(i = 0; i<=8;i++){
            casas[i] = ' ';
        }
        
        do{
            tabuleiro(casas); // Aqui, a função for acima já limpou os campos char da função com um espaço em branco
            printf("Digite a casa para marcar[1 - 9]\n");
            scanf("%i", &jogada);
            
            if(jogada < 1 || jogada > 9){
                jogada = 0; // Não há campo 0 (pois seria 0 - 1), logo, esse é o controle de jogada inválida
            }else if (casas[jogada - 1] != ' '){ //Aqui é caso o campo jogada - 1 já possua um valor diferente de espaço em branco
                jogada = 0;
                }else{
                    if (vez % 2 == 0){ 
                    casas[jogada - 1] = 'X'; //A var vez é iniciada em 0, logo, X será sempre a primeira jogada
                    }else{
                    casas[jogada - 1] = 'O';
                    }
                cont_jogadas++;
                vez++;
                    }
                }while(cont_jogadas <= 9);
       
       
        tabuleiro(casas);
        printf("Deseja jogar novamente? (s/n)\n");
        scanf("%s", &res);
        
    }while(res == 's' || res == 'S');

    getch();    
    return 0;
}
    void tabuleiro (char casas2[]){
        system("clear"); // Esse compilador não aceita system(cls)
        printf("\t %c | %c | %c \n", casas2[0], casas2[1], casas2[2]);
        printf("\t-------------- \n");
        printf("\t %c | %c | %c \n", casas2[3], casas2[4], casas2[5]);
        printf("\t-------------- \n");
        printf("\t %c | %c | %c \n", casas2[6], casas2[7], casas2[8]);
    };

