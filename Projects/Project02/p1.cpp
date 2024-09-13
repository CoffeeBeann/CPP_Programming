/***************************************************
Filename: p1.cpp
Author: MIDN Ian Coffey (m261194)
Output a Deck of Cards
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declarations
    int cardValue;

    // Output Bracket
    cout << "[";

    // Use Nested For Loops to Output Card Values
    for (int suit = 1; suit <= 4; suit++) 
    {
        for (int face = 2; face <= 14; face++) 
        {
            // Calculate Card Value
            cardValue = ((suit * 100) + face);

            // Output Card
            cout << cardValue;

            // Output Space When Necessary
            if (cardValue != 414) 
            {
                cout << " ";
            }
        }
    }

    // Output Bracket
    cout << "]" << endl;
}
