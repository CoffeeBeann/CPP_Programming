/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Track Number of Cookies Eaten & Output Statistics
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    int cookiesEaten = 0, maxCookies = 0, day = 1, cookies, totalCookies;

    // Prompt User for Input
    cout << "How many cookies? ";
    cin >> totalCookies;

    // Establish While Loop Until All Cookies are Eaten
    while (cookiesEaten < totalCookies) 
    {
        // Prompt User Input
        cout << "Cookies eaten on day " << day << ": ";
        cin >> cookies;

        // Add to Total 
        cookiesEaten += cookies;
        day++;

        // Check If It Was a Daily Max
        if (cookies > maxCookies) 
        {
            maxCookies = cookies;
        }
    }

    if (cookiesEaten == totalCookies) 
    {
        // Output Results
        cout << "You ate " << totalCookies << " cookies over " << (--day) << " days." << endl;
        cout << "On your piggiest day you ate " << maxCookies << " cookies." << endl;

    } else {

        // Output Error
        cout << "Not enough cookies!" << endl;
    }

    // End Program
    return 0; 
}