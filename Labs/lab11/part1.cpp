/***************************************************
Filename: part1.cpp
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

int main() 
{
    cout << "10 X's:"<< endl;
    repeat("X", 10);
    cout << endl;

    string DIAMOND = "\u2bc1";
    cout << "8 diamonds:" << endl;
    repeat(DIAMOND, 8);
    cout << endl;

    string TRIANGLE = "\u25b2";
    cout << "13 triangles:" << endl;
    repeat(TRIANGLE, 13);
    cout << endl;
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

