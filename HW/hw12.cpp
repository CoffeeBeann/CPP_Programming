/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Output Rectangle With Given Inputs
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    int width, height, sideAsterisk, offset;

    // Prompt User Input
    cout << "Enter height (greater than 2) : ";
    cin >> height;

    cout << "Enter width (greater than 2) : ";
    cin >> width;

    cout << "Enter offset: ";
    cin >> offset;

    // Use Nested For Loops to Output Rectangle With Given Parameters
    sideAsterisk = height - 2;


    for (int i = 0; i < height; i++) 
    {
        // Output Offset Spaces
        for (int j = 0; j < offset; j++) 
        {
            cout << " ";
        }

        // Output Starting Asterisks 
        cout << "*";

        // For Loop To Output Width Asterisk
        for (int k = 0; k < width - 1; k++) 
        {
            // Determine If @ Begining or End of Square
            if (i == 0 || i == height - 1) 
            {
                cout << "*";

            } else if (k == width - 2){

                cout << "*";

            } else {

                cout << " ";
            }
        }

        // Output New Line
        cout << endl;
    }

    // End Program
    return 0;
    
}   