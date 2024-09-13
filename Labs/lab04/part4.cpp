/*************************************************
Filename: part4.cpp
Author: MIDN Ian Coffey
Read In Temperature & Output Statistics To File
**************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string inFile, outFile, discard;
    double tempFahrenheit, tempCelsius, averageTemp = 0, maxTemp = 0, minTemp = 100;
    int count = 0, year, month, day, minTempYear, minTempMonth, minTempDay, maxTempYear, maxTempMonth, maxTempDay, hour, trash;
    char slash;

    // Prompt User Input
    cin >> inFile >> outFile;

    // Declare File Object 
    ifstream inputFile(inFile);
    ofstream outputFile(outFile);

    // Check if File exist
    if (!(inputFile)) 
    {
        // Output Error
        cout << "Could not open file '" << inFile << "'" << endl;

        // Return 1 to Main
        return 1;
    }

    // Discard Top Heading in File
    inputFile >> discard >> discard;

    // Read in Temperatures from File & Calculate Average (And Discard Useless Information)
    while (inputFile >> year >> slash >> month >> slash >> day >> hour >> slash >> trash >> slash >> trash >> tempCelsius) 
    {
        // Calculate Fahrenheit
        tempFahrenheit = ((1.8 * tempCelsius) + 32);

        // Add to Total
        averageTemp += tempFahrenheit;

        // Check If Temp Is A Max 
        if (tempFahrenheit > maxTemp) 
        {
            maxTemp = tempFahrenheit;

            // Save Date
            maxTempYear = year;
            maxTempMonth = month;
            maxTempDay = day;
        }

        // Check If Temp Is A Min
        if (tempFahrenheit < minTemp) 
        {
            minTemp = tempFahrenheit;

            // Save Date
            minTempYear = year;
            minTempMonth = month;
            minTempDay = day;
        }

        // Add 1 to count
        count++;

        // Check if New Day Is About To Started & Output New Header If So
        if (hour == 0) {

            if (day < 10) 
            {
                // Output With Concatenation of 0
                outputFile << year << "-0" << month << "-0" << day << "\t" << tempFahrenheit << "\t";

            } else {

                // Output Without Concatenation of 0
                outputFile << year << "-0" << month << "-" << day << "\t" << tempFahrenheit << "\t";

            }
        } else if (hour == 23) {

            outputFile << tempFahrenheit << "\n";

        } else {
            
            // Output Next Temperature To File
            outputFile << tempFahrenheit << "\t";

        }
    }

    // Calculate Average Temperature
    averageTemp = averageTemp / count;

    // Output File & Average
    cout << "file: " << inFile << endl;
    cout << "ave: " << averageTemp << endl; 

    // Output Additional 0 If day is Less Than 10
    if (minTempDay < 10) 
    {
        // Output With Concatenation of 0
        cout << "min: " << minTemp << " on " << minTempYear << "-0" << minTempMonth << "-0" << minTempDay << endl;

    } else {

        // Output Without Concatenation of 0
        cout << "min: " << minTemp << " on " << minTempYear << "-0" << minTempMonth << "-" << minTempDay << endl;  

    }

    // Output Additional 0 If day is Less Than 10
    if (maxTempDay < 10) 
    {
        // Output With Concatenation of 0
        cout << "max: " << maxTemp << " on " << maxTempYear << "-0" << maxTempMonth << "-0" << maxTempDay << endl;

    } else {

        // Output Without Concatenation of 0
        cout << "max: " << maxTemp << " on " << maxTempYear << "-0" << maxTempMonth << "-" << maxTempDay << endl;

    }

    cout << "output in: " << outFile << endl;
    
    // End Program
    return 0;
}