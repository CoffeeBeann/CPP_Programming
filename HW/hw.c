/***************************************************
Filename: hw34.c
Author: MIDN Ian Coffey (m261194)
Calculate the Midpoint of Two Given Points
***************************************************/

// Import Libraries
#include <stdio.h>

int main() 
{
    // Variable Declarations
    double x1, y1, x2, y2, midX, midY;
    char c;

    // Read In User Input
    scanf("%c%lf%c%lf%c%c", &c, &x1, &c, &y1, &c, &c);
    scanf("%c%lf%c%lf%c", &c, &x2, &c, &y2, &c);

    // Calculate MidPoint
    midX = (x1 + x2) / 2;
    midY = (y1 + y2) / 2;

    printf("(%lf,%lf)", midX, midY);

    return 0;
}   
