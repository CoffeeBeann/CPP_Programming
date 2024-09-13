/***************************************************
Filename: shift.cpp
Author: MIDN Ian Coffey (m261194)
Shift an Image By a Given # of Rows & Columns
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file1, file2, file3, fileHeader;
    int widthFG, heightFG, widthBG, heightBG;
    int redFG, greenFG, blueFG, redBG, greenBG, blueBG;
    int maxValue, rowShift, colShift;

    // Prompt User Foreground File// Declare Background File Object
    cout << "Foreground file: ";
    cin >> file1;

    // Declare File Object
    ifstream foregroundFile(file1);

    // Prompt User Background File
    cout << "Background file: ";
    cin >> file2;

    // Declare Background File Object
    ifstream backgroundFile(file2);

    // Prompt User For Rowshift
    cout << "Row shift: ";
    cin >> rowShift;

    // Prompt User For Column Shift
    cout << "Column shift: ";
    cin >> colShift;

    // Prompt User For Output File
    cout << "Output file: ";
    cin >> file3;

    // Declare Output File
    ofstream outputFile(file3);

    if (!foregroundFile || !backgroundFile) 
    {
        // Output Error
        cout << "Error: Input file not found" << endl;

        // End Program
        return 1;
    }

    // Read In Foreground & Background Header, Width, & Height
    foregroundFile >> fileHeader >> widthFG >> heightFG >> maxValue;
    backgroundFile >> fileHeader >> widthBG >> heightBG >> maxValue;

    // Check if Rowshift is Within Bounds of Background Image
    if (heightFG + rowShift > heightBG) 
    {
        // Output Error
        cout << "Error: The foreground goes past the background" << endl;

        // End Program
        return 1;
    }

    // Check if Column Shift is Within Bounds of Background Image
    if (colShift + widthFG > widthBG) 
    {
        // Output Error
        cout << "Error: The foreground goes past the background" << endl;

        // End Program
        return 1;
    }

    // Output Header Information To Output File
    outputFile << fileHeader << endl;
    outputFile << widthBG << " " << heightBG << endl;
    outputFile << maxValue << endl;

  
    // Nested For Loops to Read In & Replace Necessary Pixel Information

    //*************************************************************//
    //*WENT TO MGSP FOR THIS LOOP BECAUSE FOREGROUND WAS DISTORTED*//
    //*************************************************************//

    for (int row = 0; row < heightBG; row++) 
    {
        // For Loop To Traverse Foreground Width
        for (int column = 0; column < widthBG; column++) 
        {
            // Read In Background Pixel Information
            backgroundFile >> redBG >> greenBG >> blueBG;
        
            // Determine if Current Position is Within Bounds of Background or Foreground Image 
            if ((row >= rowShift) && (row <= rowShift + heightFG) && 
                (column >= colShift) && (column < colShift + widthFG))
            {
                // Read in Foreground Pixels
                foregroundFile >> redFG >> greenFG >> blueFG;

                // Perform Green Screen Replacement
                if ((redFG == 0) && (greenFG == 255) && (blueFG == 0)) 
                {
                    // Output Background
                    outputFile << redBG << " " << greenBG << " " << blueBG << " ";
                } 
                else {

                    // Output Foreground
                    outputFile << redFG << " " << greenFG << " " << blueFG << " ";
                }

                    
            }
            else
            {
                // Output Background Image Pixels
                outputFile << redBG << " " << greenBG << " " << blueBG << " ";

            } 
           
        }

        // Start New Line
        outputFile << endl;

    }

    // Output Success Message
    cout << "Image saved to " << file3 << endl;
  
    // End Program
    return 0;
}