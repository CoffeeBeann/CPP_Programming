/***************************************************
Filename: Pair.h
Author: MIDN Ian Coffey (m261194)
Header File With Structs & Overloading Prototypes
***************************************************/

// Import Libraries
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Pair Struct
struct Pair 
{
    string name;
    int num;
};

// Struct For Linked List
struct Node 
{
    Pair data;
    Node* next;
};


// Overloading Prototypes For Pair
istream& operator >> (istream& is, Pair& data);
ostream& operator << (ostream& os, Pair& data);

// Function Prototypes For Node
Node* add2front(Pair newPair, Node* oldList);
Node* add2back(Pair newPair, Node* oldList);
void printUntil(Node* List, int pos);
void printUntilWords(Node* List, int pos);
void printWords(ostream& os, Node* List);
void deleteList(Node* List);
void printList(ostream& os, Node* List);