/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Read In Birthdays & Determine Adult / Child Status
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file, name;
    int month, day, year, childCount = 0, adultCount = 0;
    char slash;

    // Prompt User Input
    cout << "Filename: ";
    cin >> file;

    // Declare File Object 
    ifstream inputFile(file);

    // Check If File Is Valid
    if (!(inputFile)) 
    {
        // Output Error
        cout << "File not found!" << endl;

        // End Program
        return 0;
    }

    // Read In Name & Birthdays Untill File Ends
    while (inputFile >> name >> month >> slash >> day >> slash >> year) 
    {
        // Convert 2 Digit Year to 4 Digits
        if (year <= 19 ) 
        {
            year += 2000;

        } else {
            
            year += 1900;
        }

        // Determine If They Are An Adult
        if (year < 2000) 
        {
            adultCount++;

        } else if (year == 2000) 
        {
            // Check If Month is Earlier Than September or if it is September
            if (month < 9) 
            {
                adultCount++;

            } else if (month == 9) 
            {
                // Check If Day Is On or Ealier Than The 27th
                if (day <= 27) 
                {
                    adultCount++;
                } else {
                     
                    childCount++;
                }
            } else {
                
                childCount++;
            }
        } else {
            
            // Add To Child Count
            childCount++;
        }
    }

    // Output Results
    cout << adultCount << " adults and " << childCount << " children" << endl;

    // End Program
    return 0;
}   