/*************************************************
Filename: p3.cpp
Author: MIDN Ian Coffey
Rig A Game of Craps in Favor of the House
**************************************************/

// Import Libraries
#include <iostream>
#include <cstdlib>

using namespace std;

// Prototype Declarations
int rolldie();
int throwdice(int setPoint, bool firstThrow);

int main() 
{
    // Variable Declaration
    int seed, setPoint, die1, die2;
    int winCheck;
    char playAgain = 'y';
    bool firstThrow = true;

    // Create New Seed for Random Function
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);

    while (playAgain == 'y') 
    {
        // Simulate First Throw of the Dice
        winCheck = throwdice(0, firstThrow);

        // Set First Throw to False
        firstThrow = false;

        // Check if Anyone Won
        if (winCheck == 0 || winCheck == -1) 
        {
            // Prompt to Play Again
            cout << "Play again? ";
            cin >> playAgain;

            if (playAgain == 'n') 
            {
                return 0;
            }
            else 
            {
                // Set First Throw to True
                firstThrow = true;
            }
        } 
        else 
        {
            // Initialize Setpoint
            setPoint = winCheck;

            // Establish While Loop to Roll Die Untill Someone Wins
            while (winCheck != 0 && winCheck != -1) 
            {
                winCheck = throwdice(setPoint, firstThrow);

                // Check if Anyone Won
                if (winCheck == 0 || winCheck == -1) 
                {
                    // Prompt to Play Again
                    cout << "Play again? ";
                    cin >> playAgain;

                    if (playAgain == 'n') 
                    {
                        return 0;
                    }
                    else 
                    {
                        // Set First Throw to True
                        firstThrow = true;

                        // Break While Loop
                        break;
                    }
                }
            }
        }
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

int throwdice(int setPoint, bool firstThrow) 
{
    // Variable Declarations
    int die1, die2, total;

    // Roll Die
    die1 = rolldie();
    die2 = rolldie();
    total = die1 + die2;

    // Output Dice Roll
    cout << "Player rolled " << die1 << " + " << die2 << " = " << total;

    // Check if this is the first throw of the game
    if (firstThrow) 
    {
        // Check if player wins
        if (total == 7 || total == 11) 
        {
            // Output Win Message
            cout << " Player wins!" << endl;

            return 0;
        }
        // Check if House Wins
        else if (total == 2 || total == 3 || total == 12) 
        {
            // Output Win Message
            cout << " House wins!" << endl;

            return -1;
        }
        else 
        {
            // Return Total
            cout << " setpoint is " << total << "!" << endl;
            return total;
        }
    }

    // Run craps game as Normal
    else 
    {
        // Check if player wins
        if (total == setPoint) 
        {
            // Output Win Message
            cout << " Player wins!" << endl;

            return 0;
        }
        // Check if House Wins
        else if (total == 7 || total == 12) 
        {
            // Output Win Message
            cout << " House wins!" << endl;

            return -1;
        }
        else 
        {
            // Output Roll Again message
            cout << " roll again" << endl;

            // Return Total
            return total;
        }
    }   
}