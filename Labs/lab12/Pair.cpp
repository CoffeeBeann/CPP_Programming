/***************************************************
Filename: Pair.cpp
Author: MIDN Ian Coffey (m261194)
Overloading Function Definitions for Pair.h
***************************************************/

// Import Libraries
#include <iostream>
#include "Pair.h"

using namespace std;

// Overloading Definitions
istream& operator >> (istream& is, Pair& data) 
{
    char c;
    return is >> c >> data.name >> data.num >> c;
}

ostream& operator << (ostream& os, Pair& data) 
{
    return os << "(" << data.name << " " << data.num << ")";
}

// Function To Add New Data To The Front of A Linked List
Node* add2front(Pair newPair, Node* oldList)
{
    Node* temp = new Node;
    temp->data.name = newPair.name;
    temp->data.num = newPair.num;
    temp->next = oldList;
    return temp;
}

Node* add2back(Pair newPair, Node* oldList) 
{
    // Base Case For Empty List
    if (oldList == NULL) 
    {
        // Return New Node @ Back Of List
        return new Node{newPair, NULL};

    } else {

        // Case If List is Not Empty
        Node* last = oldList;

        // Traverse To Back of List
        while (last->next != NULL) 
        {
            last = last->next;
        }

        // Add New Node
        last->next = new Node{newPair, NULL};

        // Return New List
        return oldList;
    }
}

// Function To Print A Linked List But Stop @ A Certain Position
void printUntil(Node* List, int pos) 
{
    for (int i = pos; i > 0; i--) 
    {
        cout << List->data << " ";
        List = List->next;
    }
}

void printUntilWords(Node* List, int pos) 
{
    for (int i = pos; i > 0; i--) 
    {
        cout << List->data.name << " ";
        List = List->next;
    }
}

// Function That Recieves A Linked List To Output Only The Words
void printWords(ostream& os, Node* List) 
{
    // Output Data Using For Loop
    for (Node* T = List; T != NULL; T = T->next) 
    {
        os << T->data.name << " ";
    }
    
    // New Line
    os << endl;
}

// Function To Delete A Given List
void deleteList(Node* List) 
{
    // Base Case
    if (List == NULL) 
    {
        return;

    } else {

        // Iterate To The Next Node
        deleteList(List->next);

        // Delete Node
        delete List;
    }

}

// Function To Print A Given List To The Console
void printList(ostream& os, Node* List) 
{
    // Output Data Using For Loop
    for (Node* T = List; T != NULL; T = T->next) 
    {
        os << T->data << " ";
    }
    
    // New Line
    os << endl;
}

