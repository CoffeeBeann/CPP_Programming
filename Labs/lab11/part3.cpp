/***************************************************
Filename: part3.cpp
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
void cantorSet(int width, int levels);
bool isValid(int size);

int main() 
{
    // Variable Declarations
    int size, levels = 0;

    // Prompt User Input
    cout << "size: ";
    cin >> size;

    // Output Cantor Set 
    cout << "Width-" << size << " Cantor set:" << endl;

    // Determine Validity of Size
    if (isValid(size)) 
    {
        // Find Number of Levels
        int temp = size;

        while (temp != 1) 
        {
            temp /= 3;
            levels++;
        }

        for (int i = 0; i <= levels; i++) 
        {
            cantorSet(size, levels);
            cout << endl;
        }
        
        return 0;       

    } else {

        cout << "Bad Size!" << endl;
        return 1;
    }

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

void cantorSet(int width, int levels) 
{
    if (levels == 0) 
    {
        repeat("X", width);
    }
    else 
    {
        cantorSet(width / 3, levels);
        repeat("_", width);
        cantorSet(width / 3, levels);
    }
}

// Function To Determine If A Numver is A Power of Three
bool isValid(int size) 
{
    if (size < 3 && size != 1) 
    {
        return false;
    } 

    while (size % 3 == 0) 
    {
        size /= 3;
    }

    return (size == 1);
}
