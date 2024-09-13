/*************************************************
Filename: p1.cpp
Author: MIDN Ian Coffey
Output 5 Random Dice Roll
**************************************************/

// Import Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

// Prototype Declarations
int rolldie();

int main() 
{
    // Variable Declarations
    int die1, die2;

    // Create New Seed for Random Function
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    for (int i = 0; i < 5; i++) 
    {
        // Call Roll Function
        die1 = rolldie();
        die2 = rolldie();

        // Role Die
        cout << "Player rolled " << die1 << " + " << die2 << " = " << (die1 + die2) << endl;
    }

    // End Program
    return 0;
}

int rolldie() 
{
    // Variable Declarations
    int die = 0;

    while (die >= 7 || die <= 0)
    {
        // Perform Random Calculations
        die = rand() % 8;
    }

    // Return Roll
    return die;

}