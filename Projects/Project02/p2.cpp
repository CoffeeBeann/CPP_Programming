/***************************************************
Filename: p2.cpp
Author: MIDN Ian Coffey (m261194)
Output Cards to Both Dealer & User Hands
***************************************************/

// Import Libraries
#include <iostream>
#include <string>

// Function Prototypes
void dealTo(int* hand, int* deck, int* deckPos);
void printHand(int* hand);
int arrayLength(int* array);

using namespace std;

int main() 
{
    // Variable Declarations
    string cmd = "";
    int deckPos = 0;

    // Array Declarations
    int* deck = new int[52];
    int* userHand = new int[52];
    int* dealerHand = new int[52];

    // Initialize All Arrays With 0's
    for (int i = 0; i < 52; i++) 
    {
        userHand[i] = 0;
        dealerHand[i] = 0;
    }

    // Use Nested For Loops to Input Card Values
    int count = 0;
    int cardValue;

    for (int suit = 1; suit <= 4; suit++) 
    {
        for (int face = 2; face <= 14; face++) 
        {
            // Calculate Card Value
            cardValue = ((suit * 100) + face);

            // Save Card to Deck Array
            deck[count] = cardValue;

            // Increment count
            count++;
        }
    }

    // Output Bracket
    cout << "[";

    // Output Deck of Cards
    for (int i = 0; i < 52; i++) 
    {
        // If On Last Card In Deck, Dont Print Space Afterwards
        if (i == 51) 
        {
            cout << deck[i];

        } else {

            cout << deck[i] << " ";
        }
    }

    // Output Bracket
    cout << "]" << endl;

    // While Loop to Keep Program Running
    while (cmd != "quit") 
    {
        // Prompt User Input
        cout << "> ";
        cin >> cmd;

        // Determine User Input & Perform Appropriate Functions
        if (cmd == "print-p") 
        {
            printHand(userHand);

        } else if (cmd == "deal-p") 
        {
            dealTo(userHand, deck, &deckPos);

        } else if (cmd == "print-d") 
        {
            printHand(dealerHand);

        } else if (cmd == "deal-d") 
        {
            dealTo(dealerHand, deck, &deckPos);

        } else {

            break;
        }
    }

    // Delete Arrays
    delete[] deck;
    delete[] userHand;
    delete[] dealerHand;

    // End Program
    return 0;
}

// Deal A Card to A Given User
void dealTo(int* hand, int* deck, int* deckPos) 
{
    // Find Next Card to be Dealt
    int newCard = deck[*deckPos];

    // Find Length of User Hand Array
    int N = arrayLength(hand);

    // Set UserHand to New Card At Specified Postion
    hand[N] = newCard;

    // Increment Deck Position
    (*deckPos)++;

}

// Print the Hand of a Given User or Dealer
void printHand(int* hand) 
{
    // Determine Length of userHand
    int N = arrayLength(hand);

    cout << "[";

    // Output Array
    for (int i = 0; i < N; i++) 
    {
        if (i == N - 1) 
        {
            cout << hand[i];

        } else 
        {
            cout << hand[i] << " ";   
        }
    }

    cout << "]" << endl;
}

// Determine the Length of a Given Integer Array
int arrayLength(int* array) 
{
    int length = 0;

    while (array[length] > 0) 
    {
        length++;
    }

    return length;
}