/*************************************************
Filename: part1.cpp
Author: MIDN Ian Coffey
Convert Temperatures to Fahrenheit & Output Average
**************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file, discard;
    double tempFahrenheit, tempCelsius, averageTemp = 0;
    int count = 0, trash;
    char slash;

    // Prompt User Input
    cin >> file;

    // Declare File Object 
    ifstream inputFile(file);

    // Check if File exist
    if (!(inputFile)) 
    {
        // Output Error
        cout << "Could not open file '" << file << "'" << endl;

        // Return 1 to Main
        return 1;
    }

    // Discard Top Heading in File
    inputFile >> discard >> discard;

    // Read in Temperatures from File & Calculate Average (Discards Useless Information As Well)
    while (inputFile >> trash >> slash >> trash >> slash >> trash >> trash >> slash >> trash >> slash >> trash >> tempCelsius) 
    {
        // Calculate Fahrenheit
        tempFahrenheit = ((1.8 * tempCelsius) + 32);

        // Add to Total
        averageTemp += tempFahrenheit;

        // Add 1 to count
        count++;
    }

    // Calculate Average Temperature
    averageTemp = averageTemp / count;

    // Output Average
    cout << "file: " << file << endl;
    cout << "ave: " << averageTemp << endl; 
    
    // End Program
    return 0;
}