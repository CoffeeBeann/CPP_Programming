/*************************************************
Filename: lab08.cpp
Author: MIDN Ian Coffey
Perform Hang Man Game Functions
**************************************************/

// Import Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function Prototypes
void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{
    // Variable & File Declarations
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    ifstream wordFile("words07.txt");
    string randPhrase;
    int seed, randNum, wrongGuess = 8;

    // Output Small Decorative Header
    cout << "Welcome to hangman!" << endl;

    // Prompt User Input for Seed
    cout << "Enter a seed value: ";
    cin >> seed;

    // Create Random Number
    srand(seed);
    randNum = rand() % 1466;

    // Retrieve String From Random Position in File
    for (int i = 0; i <= randNum; i++) 
    {
        wordFile >> randPhrase;
    }

    // Declare & Initialize Vars for While Loop
    string cover = mkShadowString(randPhrase);
    char guess = 'X';

    // Use While Loop To Keep User In Game
    while (wrongGuess != 0) 
    {
        // Variable Declarations
        string userTry;
        cover = uncover(randPhrase, cover, guess);

        // Output Game Information
        cout << "Wrong guesses remaining: " << wrongGuess << '\t' << alphabet << endl;
        printSpaced(cover);

        // Prompt User Guess
        cout << "\n: ";
        cin >> guess;

        // Check if User Was Right
        userTry = uncover(randPhrase, cover, guess);

        // Check if User Won
        if (userTry == randPhrase) 
        {
            break;
        }

        // Output Corresponding Message
        if (userTry == cover) 
        {
            cout << "There were no " << guess << "'s!" << endl;
            alphabet = crossOut(guess, alphabet);
            wrongGuess--;

        } else {

            // Edit Alphabet
            alphabet = crossOut(guess, alphabet);
        }
    }

    // Check If user Won or Lost
    if (wrongGuess == 0) 
    {
        cout << "You lose!!!! The word was " << randPhrase << endl;
    }
    else {

        cout << "You win!!!! The word was " << randPhrase << endl;
    }

    // End Program
    return 0;
}

void printSpaced(string s) 
{
    // Traverse Length of String with For Loop
    for (int i = 0; i < s.length(); i++) 
    {
        // Determine If Space Is Needed After Chartacter
        if (i == s.length() - 1) 
        {
            cout << s[i];

        } else {

            cout << s[i] << " ";
        }   
    }
}

string mkShadowString(string s) 
{
    // Declare New String to Send Back to Main
    string shadow = "";

    // Traverse Length of String To Set To _'s
    for (int i = 0; i < s.length(); i++) 
    {
        shadow += "_";
    }

    return shadow;
}

string uncover(string original, string covered, char c) 
{
    // Traverse String to Check for Matches
    for (int i = 0; i < covered.length(); i++) 
    {
        if (original[i] == c) 
        {
            covered[i] = c;
        } 
    }

    return covered;
}
string crossOut(char c, string s) 
{
    // Traverse String to Check for Matches
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == c) 
        {
            s[i] = '*';
        }
    }

    return s;
}
