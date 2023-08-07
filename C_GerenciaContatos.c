/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact{
  char name[50];
  char phone[50];
  char email[50];
};

void addContact(struct Contact contacts[], int *numContacts)
{
    if(*numContacts < MAX_CONTACTS)
    {
        printf("\nEnter contact name: ");
        scanf("%s", contacts[*numContacts].name);
        
        printf("\nEnter phone number: ");
        scanf("%s", contacts[*numContacts].phone);
        
        printf("\nEnter phone email address: ");
        scanf("%s", contacts[*numContacts].email);
        
        (*numContacts++);
    }
    else
    {
        printf("Maximum number of contacts reached.\n");
    }
}

void displayContacts(struct Contact contacts[], int numContacts)
{
    printf("\nContacts: \n");
    for(int i = 0; i < numContacts; i++)
    {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
    }
}


int main()
{
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    
    FILE *file = fopen("contacts.txt", "a+"); //Abre ou cria o arquivo no modo de leitura e escrita
    
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    
    while(fread(&contacts[numContacts], sizeof(struct Contact), 1, file) == 1)
    {
        numContacts++;
    }
    
    fclose(file);
    
    int choice;
    
    do
    {
        printf("\n");
        printf("1. Add Contact\n");
        printf("2. Diplay Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                file = fopen("contacts.txt", "w");
                for(int i = 0; i < numContacts; i++)
                {
                    fwrite(&contacts[i], sizeof(struct Contact), 1, file);
                }
                fclose(file);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please insert a valid number.\n");
                break;
        }
        
        
    }while(choice != 3);
    
    
    return 0;
}
