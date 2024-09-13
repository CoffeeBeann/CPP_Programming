/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Determine if a given Year is a Leap Year
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    int year;

    // Prompt User Input
    cout << "Enter year: ";
    cin >> year;

    // Determine if it is a Leap Year & Output Result
    if ((year % 4) == 0) 
    {
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0) 
            {
                cout << "Is Leap Year" << endl;
                
            } else {

                cout << "Is Not Leap Year" << endl;
            }

        } else {

            cout << "Is Leap Year" << endl;
        }
    } else {

        cout << "Is Not Leap Year" << endl;
    }
    // End Program
    return 0; 
}