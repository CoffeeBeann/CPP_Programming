/***************************************************
Filename: gray.cpp
Author: MIDN Ian Coffey (m261194)
Turn an Image to Black and White
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file1, file2, fileHeader;
    int width, height, red, green, blue, maxValue, averageColor;

    // Prompt User Input File
    cout << "Input file: ";
    cin >> file1;

    // Declare File Object
    ifstream inputFile(file1);

    // Prompt User Output File
    cout << "Output file: ";
    cin >> file2;

    // Declare Output File Object
    ofstream outputFile(file2);

    if (!inputFile) 
    {
        // Output Error
        cout << "Error: Input file not found";

        // End Program
        return 1;

    } else if (!outputFile) 
    {
        // Output Error
        cout << "Error: Output file not found";

        // End Program
        return 1;
    }

    // Read In File Header, Width, & Height
    inputFile >> fileHeader >> width >> height >> maxValue;

    // Output Header Information To File
    outputFile << fileHeader << endl;
    outputFile << width << " " << height << endl;
    outputFile << maxValue << endl;
  
    // Nested For Loops to Read In & Output Pixel Information
    for (int row = 0; row < height; row++) 
    {

        for (int column = 0; column < width; column++) 
        {
            // Read In Color Information
            inputFile >> red >> green >> blue;

            // Calculate Grayscale
            averageColor = ((red + green + blue) / 3);
    
            // Output Color Information to File
            outputFile << averageColor << " " << averageColor << " " << averageColor << " "; 
        }

        // Start New Line
        outputFile << endl;

    }

    // Output Success Message
    cout << "Image saved to " << file2 << endl;
  
    // End Program
    return 0;
}