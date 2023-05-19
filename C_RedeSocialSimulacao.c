/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_POSTS 100

typedef struct{
    char username[20];
    char bio[100];
    int num_posts;
    char posts[MAX_POSTS][200];
} User;

User users[MAX_USERS];
int num_users = 0;

void createProfile()
{
    if (num_users >= MAX_USERS){
        printf("Limite de usuarios alcançado!\n");
        return;
    }
    
    User newUser;
    printf("\nDigite o nome de usuário: ");
    scanf("%s", newUser.username);
    printf("\nDigite uma biografia: ");
    getchar();
    fgets(newUser.bio, sizeof(newUser.bio), stdin);
    newUser.bio[strlen(newUser.bio) - 1] = '\0'; // Remover a nova linha
    
    users[num_users++] = newUser;
    printf("Perfil criado com sucesso!\n");
    
}

void createPost()
{
    char username[20];
    int i, user_index = -1;
    
    printf("\nDigite seu nome de usuário: ");
    scanf("%s", username);
    
    for(i = 0; i < num_users; i++)
    {
        if(strcmp(users[i].username, username) == 0)
        {
            user_index = i;
            break;
        }
    }
    
    if (user_index == -1)
    {
        printf("Usuário não encontrado\n");
        return;
    }
    
    
    if(users[user_index].num_posts >= MAX_POSTS)
    {
        printf("Limite de postagens alcançado!\n");
        return;
    }
    
    printf("Digite sua postagem: ");
    getchar();
    fgets(users[user_index].posts[users[user_index].num_posts++], sizeof(users[user_index].posts[0]), stdin);
    printf("\nPostagem criada com sucesso.\n");
    
}

void viewProfile()
{
    char username[20];
    int i, user_index = -1;
    
    printf("\nDigite o nome do usuário: ");
    scanf("%s", username);
    
    for(i = 0; i < num_users; i++)
    {
        if(strcmp(users[i].username, username) == 0)
        {
            user_index = i;
            break;
        }
    }
    
    if (user_index == -1)
    {
        printf("\nUsuário não encontrado!\n");
        return;
    }
    
    
    printf("\nPerfil do usuário: ");
    printf("\nNome de usuário: %s", users[user_index].username);
    printf("\nBiografia: %s", users[user_index].bio);
    printf("\nPostagens: ");
    
    for(i = 0; i< users[user_index].num_posts; i++)
    {
        printf("\n- %s\n", users[user_index].posts[i]);
    }
    
    
}


int main()
{
    int choice;
    
    do
    {
        printf("\n---- REDE SOCIAL ----\n");
        printf("\n1.Criar perfil");
        printf("\n2.Criar postagem");
        printf("\n3.Visualizar perfil");
        printf("\n4. Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                createProfile();
                break;
            case 2:
                createPost();
                break;
            case 3:
                viewProfile();
                break;
            case 4:
                printf("Encerrando o programa...");
                break;
            default:
                printf("\nOpção inválida\n");
        }
        
    } while (choice != 4);
    

    return 0;
}
