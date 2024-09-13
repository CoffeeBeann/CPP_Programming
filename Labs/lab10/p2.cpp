/*************************************************
Filename: p2.cpp
Author: MIDN Ian Coffey
Run A Terminal To Output User Inputed Chars
**************************************************/

// Import Libraries
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"

using namespace std;

// Struct Definitions
struct Point 
{
    char name;
    int x, y;
};

// Function Prototypes
Point readPoint(istream& is);

int main() 
{
    // Variable Declaration
    int N;
    cin >> N;

    Point* points = new Point[N];

    // Initialize Points With For Loop
    for (int i = 0; i < N; i++) 
    {
        points[i] = readPoint(cin);
    }

    // Initialize ncurses
    startCurses();
    
    // Loop forever until user enters 'q'
    char c;
    do 
    {
        // Draw Points
        for (int j = 0; j < N; j++) 
        {
            drawCharAndRefresh(points[j].name, points[j].x, points[j].y);
            usleep(800000);
        }

        // Erase Points
        for (int k = 0; k < N; k++) 
        {
            drawChar(' ', points[k].x, points[k].y);
        }

        // Update Window
        refreshWindow();
        usleep(800000);

        c = inputChar();

    } while ( c != 113 );

    // Close ncurses
    endCurses();

    // Delete Arrays
    delete [] points;
    
    return 0;
}

// Function Definition for Read Point
Point readPoint(istream& is) 
{
    // Variable Declarations
    Point temp;
    char name, c;
    int x, y;

    // Read In information
    is >> temp.name >> c >> temp.x >> c >> temp.y >> c;

    // Return Pointer
    return temp;
}