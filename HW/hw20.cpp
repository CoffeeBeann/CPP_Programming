/***************************************************
Filename: hw19.cpp
Author: MIDN Ian Coffey (m261194)
Output a Given Array of Asteriks and Peform Functions
***************************************************/

// Import Libraries
#include <iostream>
#include <string>

using namespace std;

// TO DO: Give function prototypes
void get_names(string* candidate1, string* candidate2);
bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2);
void display_results(string candidate1, int count1, string candidate2, int count2);

// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}

void get_names(string* candidate1, string* candidate2) 
{
    // Prompt User Input
    cout << "Candidate Names: ";
    cin >> *candidate1 >> *candidate2;
}

bool update_counts(string selection, string candidate1, int* count1, string candidate2, int* count2) 
{
    // Check if User Desires To End Program
    if (selection == "END") 
    {
        return false;
    }

    // Run Count As Normal
    if (selection == candidate1) 
    {
        // Increment Count for Candidate 1
        (*count1)++;

    }
    else if (selection == candidate2) 
    {
        // Increment Count for Candidate 2
        (*count2)++;

    }
    else 
    {
        // Output Error Message
        cout << "Invalid Name" << endl;

    }

    return true;
   
}

void display_results(string candidate1, int count1, string candidate2, int count2) 
{
    // Check if There is a Tie
    if (count1 == count2) 
    {
        cout << "Tie!" << endl;
    }

    // Check if Candidate 1 Won
    else if (count1 > count2) 
    {
        cout << candidate1 << " wins with " << count1 << " of the " << (count1 + count2) << " votes" << endl;
    }

    // By Defualt Candidate 2 Won
    else 
    {
        cout << candidate2 << " wins with " << count2 << " of the " << (count1 + count2) << " votes" << endl;
    }
}
