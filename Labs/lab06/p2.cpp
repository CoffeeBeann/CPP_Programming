/*************************************************
Filename: p2.cpp
Author: MIDN Ian Coffey
Simulate a game of Craps
**************************************************/

// Import Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

// Prototype Declarations
int rolldie();
int throwdice();

int main() 
{
    // Variable Declarations
    int die1, die2, winCheck = 2;

    // Create New Seed for Random Function
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    // Perform While loop to Play game until Winner is found
    while (winCheck != 0 && winCheck != -1)
    {
        winCheck = throwdice();
    }

    // Check who won the game
    if (winCheck == 0) 
    {
        cout << " Player wins!" << endl;
    }
    else 
    {
        cout << " House wins!" << endl;
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

int throwdice() 
{
    // Variable Declarations
    int die1, die2, total;

    // Roll Die
    die1 = rolldie();
    die2 = rolldie();
    total = die1 + die2;

    // Output Dice Roll
    cout << "Player rolled " << die1 << " + " << die2 << " = " << total;

    // Check if player wins
    if (total == 7 || total == 11) 
    {
        return 0;
    }
    // Check if House Wins
    else if (total == 2 || total == 3 || total == 12) 
    {
        return -1;
    }
    else 
    {
        // Cout To roll Again;
        cout << " roll again" << endl;
        
        // Return Total
        return total;
    }

}