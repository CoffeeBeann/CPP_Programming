/*************************************************
Filename: part3.cpp
Author: MIDN Ian Coffey
Determine the Shape of a Triangle
**************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    float side1, side2, side3, theta1, theta2, theta3, A, B, C;
    string sideRelation, shapeRelation;

    // Prompt User for Input
    cout << "Enter side lengths: ";
    cin >> side1 >> side2 >> side3;

    // Determine the Longest Side Length
    if ((side1 > side2) && (side1 > side3)) 
    {
        // Assign A, B, & C
        A = side2;
        B = side3;
        C = side1;

    } else if ((side2 > side1) && (side2 > side3)) 
    {
        // Assign A, B, & C
        A = side1;
        B = side3;
        C = side2;

    } else if ((side3 > side1) && (side3 > side2)) 
    {
        // Assign A, B, & C
        A = side1;
        B = side2;
        C = side3;

    } else if ((side1 == side2) && (side2 == side3))
    {
        // Output Answer
        cout << "This is a acute equilateral triangle." << endl;

        // End Program 
        return 0;

    } else if ((side1 == side2) || (side2 == side3) || (side1 == side3))
    {
        // Output Answer
        cout << "This is a acute isosceles triangle." << endl;

        // End Program 
        return 0;
    }

    // Determine if Triangle if Valid
    if (((A + B) <= C)) 
    {
        // Output Angry Message
        cout << "Error! these lengths violate the triangle inequality!" << endl;

        // End Program 
        return 0;
    }

    // Determine Shape Relation
    if (((A * A) + (B * B)) == (C * C)) 
    {
        shapeRelation = "right";

    } else if (((A * A) + (B * B)) > (C * C)) 
    {
        shapeRelation = "acute";

    } else if (((A * A) + (B * B)) < (C * C)) 
    {
        shapeRelation = "obtuse";

    }

    // Determine Angle Relation
    if ((A == B) || (A == C) || (B == C)) 
    {
        sideRelation = "isosceles";

    } else if ((A != B) && (A != C) && (B != C)) 
    {
        sideRelation = "scalene";
    }

    // Output Answer
    cout << "This is a " << shapeRelation << " " << sideRelation << " triangle." << endl;
   
    // End Program
    return 0;
}