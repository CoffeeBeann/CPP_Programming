/***************************************************
Filename: hw31.cpp
Author: MIDN Ian Coffey (m261194)
Read In Numbers Using Nodes & Search For Letters
***************************************************/

// Import Libraries
#include <iostream>
#include <string>
using namespace std;

// Node Definition
struct Node
{
    string data;
    Node* next;
};

// Function Prototypes
Node* add2front(string data, Node* LIST);
void search(char target, Node* LIST);
void deletelist(Node* LIST);
Node* deletefront(Node* L);

// Main
int main()
{
    // Variable Delcarations
    Node* LIST = NULL;
    string userInput;
    char target;

    // Input Words From User
    cout << "Enter words followed by END: " << endl; 

    while (cin >> userInput && userInput != "END") 
    {
        LIST = add2front(userInput, LIST);
    }

    // Prompt For Letter to Search For
    cout << "What letter? ";
    cin >> target;
    search(target, LIST);

    
    // Delete List
    deletelist(LIST);

    // End Program
    return 0;

}

Node* add2front(string data, Node* LIST)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = LIST;
    return temp;
}

void search(char target, Node* LIST) 
{
    for(Node* T = LIST; T != NULL; T = T->next)
    {
        if (T->data[0] == target) 
        {
            cout << T->data << endl;
        }
    }
}

void deletelist(Node* L)
{
    while (L != NULL) 
    {
        L = deletefront(L);
    }
}

Node* deletefront(Node* L)
{
    if (L == NULL) 
    {
        return NULL;
    }

    Node* ret = L->next;   
    delete L;              
    return ret;
}
