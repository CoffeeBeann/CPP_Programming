/***************************************************
Filename: hw30.cpp
Author: MIDN Ian Coffey (m261194)
Read In Numbers Using Nodes
***************************************************/

// Import Libraries
#include <iostream>
using namespace std;

// Node Definition
struct Node
{
  int data;
  Node* next;
};

// Function Prototypes
Node* add2front(int data, Node* LIST);

// Main
int main()
{
    // Variable Declarations
    int x;
    Node* LIST = 0; 
    
    // Read in Numbers
    while(cin >> x && x > -1) 
    {
        LIST = add2front(x,LIST);
    }

    // Output 3rd To Last Digit
    cout << LIST->next->data << endl;

    // End Program
    return 0;
}

Node* add2front(int data, Node* LIST)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = LIST;
    return temp;
}
