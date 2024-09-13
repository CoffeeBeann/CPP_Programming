/***************************************************
Filename: part3.cpp
Author: MIDN Ian Coffey (m261194)
Concatenate List Based Off User Input 
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
    char cmd;
    int count = 0, totalScore = 0;

    // Prompt User Input
    cout << "Input file is: " << endl;
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
        // Output Current Node
        LIST = add2front(newData, LIST);
        count++;
    }

    // Create Temporary Counters For Upcoming For Loop
    int nodesBefore = 0;

    // For Loop To Output Linked List & Prompt User Input
    for (Node* T = LIST; T != NULL; T = T->next) 
    {
        // Output Node Information
        cout << "The current node: " << T->data << endl;
        cout << "Nodes before the current: ";
        printUntil(LIST, nodesBefore);

        cout << "\n#nodes after the current: " << --count << endl;
        cout << "[a]ccept or [r]eject: " << endl;
        cin >> cmd;

        // Increment Nodes Before Counter & Add To Total
        nodesBefore++;
        totalScore += T->data.num;
    }

    cout << "List is: ";

    // Print Only Words
    printWords(cout, LIST);

    // Output Total Score
    cout << "Score is: " << totalScore << endl;

    // Delete List
    deleteList(LIST);

    return 0;
}
