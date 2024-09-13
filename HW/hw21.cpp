/***************************************************
Filename: hw21.cpp
Author: MIDN Ian Coffey (m261194)
Input Flight Legs & Output Reverse Trip & Time
***************************************************/

// Import Libraries
#include <iostream>
#include <string>

using namespace std;

// Prototype Declarations
string reverse(string leg, bool lastTime);

int main() 
{
    // Variable Declaration
    int legNum, finalHour;
    double minute = 0, hour = 0, totalTime = 0, finalMinute;
    string leg, tempLeg = "";
    char c, locationOne, locationTwo, locationThree;

    // Prompt User Input
    cout << "How many legs? ";
    cin >> legNum;

    // Declare String Array With Given Length
    string* flight = new string[legNum];

    // Input Flight Lengths
    for (int i = 0; i < legNum; i++)
    {
        // Read In Information
        cin >> locationOne >> locationTwo >> locationThree >> leg >> hour >> c >> minute;

        // Check if There is a City Mismatch
        if (leg == tempLeg) 
        {
            // Output Error Message
            cout << "City mismatch" << endl;
            
            // End Program
            return 0;
        } 
        else {

            tempLeg = leg;
        }

        // Add to Total Time
        totalTime += hour + (minute / 60);

        // Save Flight Information Into Array
        flight[i] = leg;
    }

    // Calculate Final Hour
    finalHour = (int) totalTime;

    // Calculate Final Minute
    finalMinute = (totalTime - finalHour) * 60;

    // Output Reverse Trip
    string* reverseTrip = new string[legNum + 1];
    cout << "Reverse trip: ";

    for (int j = legNum - 1; j >= 0; j--) 
    {
        cout << reverse(flight[j]);
    }

    // New Line
    cout << endl;

    // Output Total Time
    cout << "Total time: " << finalHour << " hours " << finalMinute <<  " minutes" << endl;

    // End Program
    return 0;
}

// Function to Input a Travel Leg & Reverse the Destinations
string reverse(string leg, bool lastTime) 
{
    string location = "xxx", endLocation = "xxx", reverseLeg;

    // Read In First Location & Store In End Leg
    for (int i = 0; i < 3; i++) 
    {
        endLocation[i] = leg[i];
    }

    // Read In Second Location & Store In Start Leg
    for (int j = 0; j < 3; j++) 
    {
        startLocation[j] = leg[j + 5];
    }

    // Concatinate Strings Together
    reverseLeg = startLocation + "->" + endLocation + "->";

    // Return Reversed Leg
    return reverseLeg;
}