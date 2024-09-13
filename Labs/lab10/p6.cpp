/*************************************************
Filename: p6.cpp
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
    char name, direction;
    int x, y;
};

// Function Prototypes
Point readPoint(istream& is);

int main()
{
    // Set Random Time
    srand(time(0));

    // Variable Declaration
    int maxX, maxY, N;
    char c;
    cin >> N;

    Point* points = new Point[N];

    // Initialize Points With For Loop
    for (int i = 0; i < N; i++) 
    {
        points[i] = readPoint(cin);
    }

    // Initialize ncurses
    startCurses();
    getWindowDimensions(maxX, maxY);
    
    // Draw Points & initialize direction
    for (int j = 0; j < N; j++) 
    {
        drawChar(points[j].name, points[j].x, points[j].y);
        points[j].direction = 'e';
    }

    // Refresh Window & Sleep
    refreshWindow();
    usleep(80000);

    do 
    {
        // Erase Points
        for (int k = 0; k < N; k++) 
        { 
            drawChar(' ', points[k].x, points[k].y);
        }
     
        // Decide if points will turn
        for (int i = 0; i < N; i++) 
        {
            if( rand() % 5 == 0 )
            {
                int r = rand() % 2;

                if ((points[i].direction == 'e') || (points[i].direction == 'w')) 
                {
                    if (r == 1) {
                        points[i].direction = 'n';
                    }
                    else {
                        points[i].direction = 's';
                    }
                }
                else if ((points[i].direction == 'n') || (points[i].direction == 's')) 
                {
                    if (r == 1) {
                        points[i].direction = 'w';
                    }
                    else {
                        points[i].direction = 'e';
                    }
                }
            }
        } // points have now been assigned new direction based off random chance

        // Check for out of bounds
        for (int k = 0; k < N; k++) 
        {
            if (points[k].y == maxY-1) 
            { 
                points[k].direction = 'w';
            }
            else if (points[k].y == 1) 
            {
                points[k].direction = 'e';
            }
            else if (points[k].x == maxX-1 ) 
            {
                points[k].direction = 'n';
            }
            else if (points[k].x == 1) 
            {
                points[k].direction = 's';
            }
        }

        // Draw Points
        for (int j = 0; j < N; j++) 
        {
            if (points[j].direction == 'e') 
            {
                points[j].y +=1;
            }
            else if (points[j].direction == 'w') 
            {
                points[j].y -= 1;
            }
            else if (points[j].direction == 'n') 
            {
                points[j].x -= 1;
            }
            else 
            {
                points[j].x += 1;
            }

            drawChar(points[j].name, points[j].x, points[j].y);
        }

        // Update Window
        refreshWindow();
        usleep(80000);

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
