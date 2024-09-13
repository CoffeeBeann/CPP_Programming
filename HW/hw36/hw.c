/***************************************************
Filename: hw36.c
Author: MIDN Ian Coffey (m261194)
Search For A Given Char In a Linked List
***************************************************/

// Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct For Node
struct Node 
{
    char data[128];
    struct Node* next;
};

// Function Prototypes For Node
struct Node* add2front(char* val, struct Node* L);
void deleteList(struct Node* L);

int main() 
{
    // Variable Declarations
    struct Node* List = NULL;
    char string[128];
    char c;

    // Prompt User Input
    printf("Enter words followed by END:\n");

    // Read In Strings
    do 
    {
        scanf("%s", string);
        List = add2front(string, List);
    }
    while (strcmp(string, "END") != 0); 

    // Prompt User For Letter To Seach For
    printf("What letter? ");
    scanf(" %c", &c);

    // Traverse Linked List & Output Matches
    for (struct Node* T = List; T != NULL; T = T->next)  
    {
        if (T->data[0] == c) 
        {
            printf("%s\n", T->data);
        }
    }

    // Delete List
    deleteList(List);

    return 0;
}   

// Function Definitions
struct Node* add2front(char* val, struct Node* L)
{
    struct Node* T = malloc(sizeof(struct Node));
    strcpy(T->data, val);   
    T->next = L;
    return T;
}

// Deletes a list
void deleteList(struct Node* L)
{
    if( L != NULL )
    {
        deleteList(L->next);
        free(L);
    }
}
