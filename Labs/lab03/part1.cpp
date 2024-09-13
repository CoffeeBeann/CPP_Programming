/*************************************************
Filename: part1.cpp
Author: MIDN Ian Coffey
Input A Set of Coordinates & Output Box Coordinates
**************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    float coord1, coord2, coord3, coord4, coord5, coord6;
    char trash;

    // Prompt User Input
    cin >> trash >> coord1 >> trash >> coord2 >> trash >> trash >> coord3
    >> trash >> coord4 >> trash >> trash >> coord5 >> trash >> coord6;

    // Calculate Box Coordinates
    float lowestX, highestX, lowestY, highestY;
    lowestX = highestX = lowestY = highestY = 0;
    
    // Determine Lowest & Highest X Value
    if ((coord1 <= coord3) && (coord1 <= coord5)) 
    {
        // Assign Lowest X
        lowestX = coord1;

        // Decipher & Assign Highest X
        if (coord3 <= coord5) 
        {
            highestX = coord5;

        } else {

            highestX = coord3;
        }

    } else if ((coord3 <= coord1) && (coord3 <= coord5))
    {
        // Assign Lowest X
        lowestX = coord3;

        // Decipher & Assign Highest X
        if (coord1 < coord5) 
        {
            highestX = coord5;

        } else {

            highestX = coord1;
        }

    } else if ((coord5 <= coord3) && (coord5 <= coord1))
    {
        // Assign Lowest X
        lowestX = coord5;

        // Decipher & Assign Highest X
        if (coord3 < coord1) 
        {
            highestX = coord1;

        } else {

            highestX = coord3;
        }
    }

    // Determine Lowest & Highest Y Value
    if ((coord2 <= coord4) && (coord2 <= coord6)) 
    {
        // Assign Lowest Y
        lowestY = coord2;

        // Decipher & Assign Highest Y
        if (coord4 < coord6) 
        {
            highestY = coord6;

        } else {

            highestY = coord4;
        }

    } else if ((coord4 <= coord2) && (coord4 <= coord6))
    {
        // Assign Lowest Y
        lowestY = coord4;

        // Decipher & Assign Highest Y
        if (coord2 < coord6) 
        {
            highestY = coord6;

        } else {

            highestY = coord2;
        }

    } else if ((coord6 <= coord4) && (coord6 <= coord2))
    {
        // Assign Lowest Y
        lowestY = coord6;

        // Decipher & Assign Highest Y
        if (coord4 < coord2) 
        {
            highestY = coord2;

        } else {

            highestY = coord4;
        }
    }

    // Output Box Coordinates
    cout << lowestX << " " << lowestY << "\n"
         << lowestX << " " << highestY << "\n"
         << highestX << " " << highestY << "\n"
         << highestX << " " << lowestY << "\n"
         << lowestX << " " << lowestY << "\n\n";
        
    // Output Triangle Coordinates
    cout << coord1 << " " << coord2 << "\n"
         << coord3 << " " << coord4 << "\n"
         << coord5 << " " << coord6 << "\n"
         << coord1 << " " << coord2 << "\n";

    // End Program
    return 0;
}