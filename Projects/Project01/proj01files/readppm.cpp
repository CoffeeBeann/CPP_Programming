/***************************************************
Filename: readppm.cpp
Author: MIDN Ian Coffey (m261194)
Read In PPM Image Format & Output Pixel Information
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file, fileHeader;
    int width, height, red, green, blue, maxValue;

    // Prompt User Input
    cout << "Input file: ";
    cin >> file;

    // Declare File Object
    ifstream inputFile(file);

    // Read In File Header, Width, & Height
    inputFile >> fileHeader >> width >> height >> maxValue;

    // Output Header Information
    cout << fileHeader << endl;
    cout << "width = " << width << ", height = " << height << endl;
    cout << "max value = " << maxValue << endl;

  
    // Nested For Loops to Read In & Output Pixel Information
    for (int row = 0; row < height; row++) 
    {
        // Output Row 
        cout << "*** row " << row << " ***" << endl;

        for (int column = 0; column < width; column++) 
        {
            // Read In Color Information
            inputFile >> red >> green >> blue;

            // Output Color Information
            cout << "row " << row << ", col " << column;
            cout << ": r" << red << " g" << green << " b" << blue << endl;
        }
    }


    // End Program
    return 0;
}