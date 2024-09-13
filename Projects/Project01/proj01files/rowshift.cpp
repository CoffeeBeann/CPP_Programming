/***************************************************
Filename: rowshift.cpp
Author: MIDN Ian Coffey (m261194)
Overlay an Image and Shift It X Number of Rows
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
    int redFG, greenFG, blueFG, redBG, greenBG, blueBG, maxValue, rowShift;

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

    // Output Header Information To Output File
    outputFile << fileHeader << endl;
    outputFile << widthBG << " " << heightBG << endl;
    outputFile << maxValue << endl;

    // Nested For Loops To Read In Background Image Pixels For Rowshift
    for (int row = 0; row < rowShift; row++) 
    {
        for (int column = 0; column < widthBG; column++) 
        {
            // Read In Background Pixels
            backgroundFile >> redBG >> greenBG >> blueBG;

            // Output Pixel Information Into Output File
            outputFile << redBG << " " << greenBG << " " << blueBG << " ";
        }

        // Output New Line To File
        outputFile << endl;
    }
  
    // Nested For Loops to Read In & Replace Necessary Pixel Information
    for (int row = 0; row < (heightBG - rowShift); row++) 
    {
        // For Loop To Traverse Foreground Width
        for (int columnFG = 0; columnFG < widthFG; columnFG++) 
        {
            // Read In Color Information
            foregroundFile >> redFG >> greenFG >> blueFG;
            backgroundFile >> redBG >> greenBG >> blueBG;

            // Check If Information Indicates A Green Pixel
            if ((greenFG == 255) && (redFG == 0) && (blueFG == 0)) 
            {
                // Output Foreground Pixel to File
                outputFile << redBG << " " << greenBG << " " << blueBG << " ";

            } else {

                // Output Normal Background Pixel
                outputFile << redFG << " " << greenFG << " " << blueFG << " ";
            }
        }

        // For Loop To Traverse the Rest of the Background Width
        for (int columnBG = 0; columnBG < (widthBG - widthFG); columnBG++) 
        {
            // Read In Background Pixels
            backgroundFile >> redBG >> greenBG >> blueBG;

            // Output Pixel Information Into Output File
            outputFile << redBG << " " << greenBG << " " << blueBG << " ";
        }

        // Start New Line
        outputFile << endl;

    }

    // Output Success Message
    cout << "Image saved to " << file3 << endl;
  
    // End Program
    return 0;
}
