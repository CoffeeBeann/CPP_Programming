/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Convert Uppercase Phrases to Lowercase
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    char c1, c2, c3;
    
    // Prompt User Input
    cout << "Input a 3-letter word in uppercase letters: ";
    cin >> c1 >> c2 >> c3;

    // Convert to Lowercase
    c1 += 32;
    c2 += 32;
    c3 += 32;
    
    // Output Phrase
    cout << "Output: " << c1 << c2 << c3 << endl;

    // End Program
    return 0; 
}