/***************************************************
Filename: hw17.cpp
Author: MIDN Ian Coffey (m261194)
Read In User Phrase and Reverse it
***************************************************/

// Import Libraries
#include <iostream>
#include <array>

using namespace std;

int main() 
{
  // Variable Declarations
  int n;
  string userPhrase;

  // Prompt User for Size
  cout << "Number of words: ";
  cin >> n;

  // Declare new array
  string* userArray = new string[n];

  // Prompt User Input
  cout << "Sentence: ";

  // Prompt User for Phrases
  for (int i = 0; i < n; i++) 
  {
    cin >> userArray[i];
  }

  // Output Phrase with question mark
  for (int j = 0; j < n; j++) 
  {
    // Check if space or question mark needs ot be outputed
    if (j == n - 1) 
    {
      cout << userArray[j] << "?";
    } 
    else 
    {
      cout << userArray[j] << " ";
    }
  }

  // Outut Space Between Phrases
  cout << " ";
  
  // Output Reverse Phrase with Exclamation mark
  for (int k = n - 1; k >= 0; k--) 
  {
    // check if a space or an exclamation point needs to be added
    if (k == 0) 
    {
      cout << userArray[k] << "!";
    } 
    else 
    {
      cout << userArray[k] << " ";
    }
  }

  // End Program
  return 0;

}