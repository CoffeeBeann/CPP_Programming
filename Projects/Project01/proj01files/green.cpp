/***************************************************
Filename: green.cpp
Author: MIDN Ian Coffey (m261194)
Overlay a Foreground Image Over a Background
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
    int redFG, greenFG, blueFG, redBG, greenBG, blueBG, maxValue;

    // Prompt User Foreground File
    cout << "Foreground file: ";
    cin >> file1;

    // Declare File Object
    ifstream foregroundFile(file1);

    // Prompt User Background File
    cout << "Background file: ";
    cin >> file2;

    // Declare Background File Object
    ifstream backgroundFile(file2);

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

    // Check if Dimensions are the Same
    if ((widthFG != widthBG) || (heightFG != heightBG)) 
    {
        // Output Dimension Error
        cout << "Error: Images have different sizes" << endl;

        // End Program
        return 1;
    }

    // Output Header Information To Output File
    outputFile << fileHeader << endl;
    outputFile << widthFG << " " << heightFG << endl;
    outputFile << maxValue << endl;
  
    // Nested For Loops to Read In & Replace Necessary Pixel Information
    for (int row = 0; row < heightFG; row++) 
    {

        for (int column = 0; column < widthFG; column++) 
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

        // Start New Line
        outputFile << endl;

    }

    // Output Success Message
    cout << "Image saved to " << file3 << endl;
  
    // End Program
    return 0;
}
