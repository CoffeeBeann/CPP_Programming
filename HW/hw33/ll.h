// Header File For hw.cpp
#pragma once
#include <iostream>

using namespace std;

// Stuct Definition
struct Node 
{
    int data;
    Node* next;
};

// Function Prototypes
Node* add2back(int data, Node* oldlist);
Node* remove(int data, Node* List);
Node* deleteFront(Node* List);
Node* enter_after(int data, int afterVal, Node* List);
void deletelist(Node* List);
void print(Node* List);