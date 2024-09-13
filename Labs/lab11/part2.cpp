/***************************************************
Filename: part2.cpp
Author: MIDN Ian Coffey (m261194)
Output Fractals
***************************************************/

// Import Libraries
#include <iostream>
#include <string> 

using namespace std;

// Prints out the string s, count times in a row,
// in a **single** line.
// You must implement this using recursion!

// Prototype Declarations
void repeat(string s, int count);
void cantorSet(int size);

int main() 
{
    // Variable Declarations
    int size;

    // Prompt User Input
    cout << "size: ";
    cin >> size;

    // Output Cantor Set 
    cout << "Width-" << size << " Cantor set:" << endl;

    cantorSet(size);

    return 0;
}

void repeat(string s, int count) 
{
    if (count == 1) 
    {
        cout << s;

    } else {

        cout << s;
        repeat(s, count-1);
    }
}

void cantorSet(int size) 
{
    if (size == 1) 
    {
        cout << "X";

    } else {

        cantorSet(size / 3);
        repeat("_", size / 3);
        cantorSet(size / 3); 
    }
}

