/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float grade;
};


// Definição da estrutura de dados para a lista encadeada
struct Node 
{
    struct Student data;
    struct Node *next;
};

// Função para inserir um novo elemento no início da lista
struct Node* insertFront(struct Node *head, struct Student newData)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Função para imprimir os elementos da lista
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("Nome: %s, Idade: %d, Nota: %.2f\n", current->data.name, current->data.age, current->data.grade);
        current = current->next;
        
    }
}

// Implementação básica de uma pilha utilizando a mesma estrutura de nó
struct Stack
{
    struct Node *top;
};

// Função para empilhar um novo elemento
void push(struct Stack *stack, struct Student newData) 
{
    stack->top = insertFront(stack->top, newData);
}


// Função para desempilhar um elemento
void pop(struct Stack *stack)
{
    if(stack->top != NULL)
    {
        struct Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}


int main()
{
    //Lista encadeada
    struct Node *list = NULL;
    
    struct Student student1 = {"Joao", 20, 8.5};
    struct Student student2 = {"Maria", 22, 9.0};

    list = insertFront(list, student1);
    list = insertFront(list, student2);
    
    printf("Lista encadeada:\n");
    printList(list);
    
    // pilha
    struct Stack stack;
    stack.top = NULL;
    
    push(&stack, student1);
    push(&stack, student2);
    
    printf("\nPilha: \n");
    printList(stack.top);
    
    return 0;
}
