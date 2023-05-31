/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*

    CELULA
    eBomba 0 ou 1
    estaAberta 0 ou 1
    vizinhos 0 a 4

*/

typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;

Celula jogo[5][5];
int tam = 5;
int l, c;



// função para inicializar a matriz
void inicializarJogo()
{
    for(l = 0; l < tam; l++)
    {
        for(c = 0; c < tam; c++)
        {
            jogo[l][c].eBomba = 0;
            jogo[l][c].estaAberta = 0;
            jogo[l][c].vizinhos = 0;
        }
    }
}


// função para sortear n bombas
void sortearBombas(int n)
{
    int i;
    
    srand(time(NULL));
    
    for (i = 1; i < n; i++)
    {
        l = rand() % tam;
        c = rand() % tam;
        if (jogo[l][c].eBomba == 0)
        {
            jogo[l][c].eBomba = 1;
        }else
        {
            i--;
        }
        
    }
}

/*
        função que diz se um par de coordenadas é válido ou não
        1 - é válido
        0 - não é válido
*/
int coordenadaEhValida(int l, int c)
{
    if(l >= 0 && l < tam && c >= 0 && c < tam)
    {
        return 1;
    }else
    {
        return 0;
    }
}



/* função que retorna a quantidade de bombas na vizinhança de l e c
   n - quantidade de bombas
*/

int quantiBombasVizinhas(int l, int c)
{
   /*
        l - 1 e c (acima)
        l + 1 e c (abaixo)
        l e c + 1 (direita)
        l e c - 1 (esquerda)
   */
   
   int quantidade = 0;
   
   if (coordenadaEhValida(l - 1, c) && jogo[l - 1][c].eBomba)
   {
       quantidade++;
   }
    if (coordenadaEhValida(l + 1, c) && jogo[l + 1][c].eBomba)
   {
       quantidade++;
   }
    if (coordenadaEhValida(l, c + 1) && jogo[l][c + 1].eBomba)
   {
       quantidade++;
   }
    if (coordenadaEhValida(l, c - 1) && jogo[l][c - 1].eBomba)
   {
       quantidade++;
   }
   
   return quantidade;
}

// função para contar bombas vizinhas
void contarBombas()
{
    int i, j;
    
    for(l = 0; l < tam; l++)
    {
        for(c = 0; c < tam; c++)
        {
            jogo[l][c].vizinhos = quantiBombasVizinhas(l, c);
        }
    }
    
}

// função para imprimir o jogo 
void imprimir()
{
    printf("\n\n\t  ");
    for(l = 0; l < tam; l++)
    {
        printf("  %d ", l); // indices das colunas
    }
    
    printf("\n\t  ---------------------\n");
    
    for(l = 0; l < tam; l++)
    {
        printf("\t%d |", l); // índice das linhas
        for(c = 0; c < tam; c++)
        {
            if (jogo[l][c].estaAberta)
            {
                if(jogo[l][c].eBomba)
                {
                    printf(" * ");
                    
                }else
                {
                    printf(" %d ", jogo[l][c].vizinhos);    
                }
                
                
            }else
            {
                printf("   ");
            }
            printf("|");
            
        }
        printf("\n\t  ---------------------\n");
    }
    
}

//procedimento para abrir a coordenada digitada pelo usuario
void abrirCelula(int l, int c)
{
    
    if(coordenadaEhValida(l, c) == 1 && jogo[l][c].estaAberta == 0)
    {
        jogo[l][c].estaAberta = 1;
        
        if(jogo[l][c].vizinhos == 0)
            {
            /*
            l - 1 e c acima
            l + 1 e c abaixo
            l e c + 1 direita
            l e c - 1 esquerda
            */
            
            abrirCelula(l - 1, c); //acima
            abrirCelula(l + 1, c); //abaixo
            abrirCelula(l, c + 1);//direita
            abrirCelula(l, c - 1);//esquerda
            
        
        }
    
    }
}

// procedimento que faz a leitura das coordenadas
void jogar(){
    int linha, coluna;
    
    do{
        imprimir();
        do{
            printf("\nDigite as coordenadas de linha e coluna: \n");
            scanf("%d%d", &linha, &coluna);
            
            if(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1)
            {
                printf("Coordenada inválida ou já aberta!");
            }
            
        } while(coordenadaEhValida(linha, coluna) == 0 || jogo[linha][coluna].estaAberta == 1);
        
        abrirCelula(linha, coluna);
        
    }while(ganhou() != 0 && jogo[linha][coluna].eBomba == 0);
    
    
    if(jogo[linha][coluna].eBomba == 1)
    {
        printf("\nQue pena, voce perdeu!\n");
        
    }else
    {
        printf("\nParabéns, voce ganhou!\n");
    }
    imprimir();
    
}
//função para verificar vitória
//1 == ganhou ; 0 == não ganhou ainda
int ganhou()
{
    
    int quantidade = 0;
    
    for(int l = 0; l < tam; l++)
    {
        for(int c = 0; c < tam; c++)
        {
            if(jogo[l][c].estaAberta == 0 && jogo[l][c].eBomba == 0)
            {
                quantidade++;
            }
        }
    }
    
    return quantidade;
    
}


// Campo minado - CursoYoutube

int main()
{
    int opcao;
    
    do{
        
        inicializarJogo();
        sortearBombas(10);
        contarBombas();
        printf("\n\t       CAMPO MINADO\n");
        jogar();
        
        printf("Digite 1 para jogar novamente: ");
        scanf("%d", &opcao);
        
    }while(opcao == 1);

    return 0;
}





