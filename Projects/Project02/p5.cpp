/***************************************************
Filename: p5.cpp
Author: MIDN Ian Coffey (m261194)
Simulate the First 3 Rounds of a Game of BlackJack
***************************************************/

// Import Libraries
#include <iostream>
#include <string>
#include <array>

// Function Prototypes
void dealTo(int* hand, int* deck, int* deckPos);
void shuffleDeck(int* deck, int seed);
void printHand(int* user, int* dealer);
int arrayLength(int* array);

using namespace std;

int main() 
{
    // Variable Declarations
    char cmd;
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

    // Prompt User if They Want to Shuffle the Deck
    int seed;
    char c;
    cout << "Shuffle: [n | u <seed>]: ";
    cin >> c;

    // Shuffle Deck if Prompted
    if (c == 'u') 
    {
        // Input Seed
        cin >> seed;

        // Shuffle Deck
        shuffleDeck(deck, seed);
    }

    // Deal 2 Cards to Both Dealer & Player
    dealTo(userHand, deck, &deckPos);
    dealTo(dealerHand, deck, &deckPos);
    dealTo(userHand, deck, &deckPos);
    dealTo(dealerHand, deck, &deckPos);

    // Output Dealer & Player Cards to Screen
    cout << "\n Player Dealer" << endl;
    printHand(userHand, dealerHand);


    // For Loop to Run Three Rounds
    for (int i = 1; i <= 3; i++)
    {
        // Prompt User Input
        cout << "\nRound " << i << " Player's turn" << endl;\
        cout << "hit or stand ? [h/s] ";
        cin >> cmd;

        // Determine If User Wants to Hit or Stand
        if (cmd == 'h') 
        {
            // Deal Card to User
            dealTo(userHand, deck, &deckPos);
        } 

        // Output Updated Hands
        cout << "\n Player Dealer" << endl;
        printHand(userHand, dealerHand);

        // Prompt Dealer Input
        cout << "\nRound " << i << " Dealer's turn" << endl;\
        cout << "hit or stand ? [h/s] ";
        cin >> cmd;

        // Determine If Dealer Wants to Hit or Stand
        if (cmd == 'h') 
        {
            // Deal Card to Dealer
            dealTo(dealerHand, deck, &deckPos);
        } 

        // Output Updated Hands
        cout << "\n Player Dealer" << endl;
        printHand(userHand, dealerHand);

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
void printHand(int* user, int* dealer) 
{
    // Variable Declarations
    int faceValue, suitValue;
    int control;

    // Declare Fancy Cards Suits
    string clubs = "\u2663";
    string diamonds = "\u2666";
    string hearts = "\u2665";
    string spades = "\u2660";

    // Determine Which Hand Is Larger To Use for For Loop
    int userHandLength = arrayLength(user);
    int dealerHandLength = arrayLength(dealer);

    // Assign Control Variable To Largest Hand
    if (userHandLength > dealerHandLength) 
    {
        control = userHandLength;

    } else {

        control = dealerHandLength;
    }

    // Use For Loop To Output User & Player Hands
    for (int i = 0; i < control; i++) 
    {
        // Variable Assignments
        faceValue = user[i] % 100;
        suitValue = user[i] / 100;

        // Run Nested For Loop Twice To Output
        // User & Dealer Hand Horizontally
        for (int j = 0; j < 2; j++) 
        {
            cout << "|";

            // Determine How Much Space is Needed
            if (faceValue != 10) 
            {
                // Output Space
                cout << "  ";
            }
            else 
            {
                cout << " ";
            }

            // Determine If Jack, Queen, or King is Needed
            if (faceValue > 10) 
            {
                switch (faceValue) 
                {
                    case 11:
                        cout << "J";
                        break;
                    case 12:
                        cout << "Q";
                        break;
                    case 13:
                        cout << "K";
                        break;
                    case 14:
                        cout << "A";
                        break;
                    default:
                        cout << " ";
                        break;
                }

            } else {
                
                // Check If There is A Card before Printing Out
                // Otherwise Just Print Space
                if (faceValue == 0) 
                {
                    cout << " ";

                } else {

                    cout << faceValue;
                }
            }

            // Determine Which Suit is Needed
            switch (suitValue) 
            {
                case 1:
                    cout << clubs;
                    break;
                case 2:
                    cout << diamonds;
                    break;
                case 3:
                    cout << hearts;
                    break;
                case 4:
                    cout << spades;
                    break;
                default:
                    cout << " ";
                    break;
            }

            cout << "  ";

            // Reassign Cards to Dealer
            faceValue = dealer[i] % 100;
            suitValue = dealer[i] / 100;

        }

        cout << "|" << endl;

    }
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

// Shuffle Deck Given Inputed Seed
void shuffleDeck(int* deck, int seed) 
{
    srand(seed);

    // Shuffle Deck
    for (int i = 0; i < 52; i++) 
    {
        int temp = 0, j = rand() % 52;

        // Swap Values
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}