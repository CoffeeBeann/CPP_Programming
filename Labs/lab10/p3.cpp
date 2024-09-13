/*************************************************
Filename: p3.cpp
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

int main() {

    // Set Random Time
    srand(time(0));

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

    // Draw Points
    for (int j = 0; j < N; j++) 
    {
        drawChar(points[j].name, points[j].x, points[j].y);
    }

    // Refresh Window & Sleep
    refreshWindow();
    usleep(80000);

    // Use For Loop To Animate 
    for (int frame = 0; frame < 20; frame++) 
    {
        // Erase Points
        for (int k = 0; k < N; k++) 
        {
            drawChar(' ', points[k].x, points[k].y);
        }

        // Draw Points
        for (int j = 0; j < N; j++) 
        {
            points[j].y += 1;
            drawChar(points[j].name, points[j].x, points[j].y);
        }

        refreshWindow();
        usleep(80000);
    }

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
