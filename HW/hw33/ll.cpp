// CPP File for LL.h 
#include <iostream>
#include "ll.h"

using namespace std;

// Function Definitions
Node* add2back(int data, Node* oldlist) 
{
    if (oldlist == NULL) 
    {
        return new Node{data, NULL};

    } else {

        oldlist->next = add2back(data, oldlist->next);
        return oldlist;      
    }
}

// Function To Remove A Peice of data from the list
Node* remove(int data, Node* List) 
{
    // Base Case
    if (List == NULL) 
    {
        return NULL;
    } else 
    {
        // Inductive Case
        if (List->data == data) 
        {
            Node* temp = List->next;
            delete List;
            return temp;
        }
    }
    
    // Use Recursion
    List->next = remove(data, List->next);
    return List;


}

// Use Recursion for Enter_after
Node* enter_after(int data, int afterVal, Node* List) 
{
    // Check If After Val is found
    if (List->data == afterVal) 
    {
        List->next = new Node{data, List->next};

    }else {
        
        // Iterate to next step
        enter_after(data, afterVal, List->next);
    }

    // Return the list
    return List;
}

void deletelist(Node* List) 
{
    // Delete list with while loop
    while (List != NULL) 
    {
        List = deleteFront(List);
    }
}

// additional function for deletelist
Node* deleteFront(Node* List)
{
    // Check for empty list
    if (List == NULL) 
    {
        return NULL;
    }

    // Delete front node
    Node* T = List->next;   
    delete List;              
    return T;
}

// Print list
void print(Node* List) 
{
    // Use for loop to traverse list
    for (Node* T = List; T != NULL; T = T->next) 
    {
        cout << T->data << " ";
    }
    cout << endl;
}