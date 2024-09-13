/***************************************************
Filename: part1.cpp
Author: MIDN Ian Coffey (m261194)
Traverse a File & Output Its Contents
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>
#include "Pair.h"

using namespace std;

int main() 
{
    // Variable Declarations
    Node* LIST = NULL;
    string fname = "";
    Pair newData{"", 0};
    int count = 0;

    // Prompt User Input
    cout << "Input file is: ";
    cin >> fname;

    // Create & Validate File
    ifstream fin(fname);
    if (!fin) 
    {
        cout << "Error! File '" << fname << "' not found!"  << endl; 
        return 1;
    }    

    // Traverse File To Read Data & Get Length 
    while (fin >> newData)
    {
        LIST = add2front(newData, LIST);
        count++;
    }

    cout << "Count is " << count << endl;

    // Output Contents of Linked List
    printList(cout, LIST);

    // Delete List
    deleteList(LIST);

    return 0;
}
