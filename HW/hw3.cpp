/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Subtract Two Inputed Lengths 
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    double foot1, foot2, foot3, inch1, inch2, inch3, length1, length2, length3;
    char trash;
    
    // Prompt User Input
    cout << "Enter two lengths in feet and inches (larger first!)" << endl;
    cin >> foot1 >> trash >> inch1 >> trash >> trash >> foot2 >> trash >> inch2 >> trash >> trash; 

    // Calculate Difference
    length1 = foot1 + (inch1 / 12);
    length2 = foot2 + (inch2 / 12);
    length3 = length1 - length2;
    foot3 = int(length3);
    inch3 = (length3 - foot3) * 12;
    
    // Output Answer
    cout << "Difference is " << foot3 << "' " << inch3 << "''" << endl;

    // End Program
    return 0; 
}