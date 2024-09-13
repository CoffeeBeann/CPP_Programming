/*************************************************
Filename: part2.cpp
Author: MIDN Ian Coffey
Binary & Decimal Calculator
**************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main() 
{
    // Variable Declaration
    char type1, type2, op;
    int num1, num2, total, finalBin1, finalBin2, finalBin3, finalBin4;

    // Enter Type1 For First Input
    cin >> type1;

    // Determine If First Input is Binary
    if (type1 == 'B') 
    {
        // Read In All Digits
        char bin1, bin2, bin3, bin4;
        int digit1, digit2, digit3, digit4;
        cin >> bin1 >> bin2 >> bin3 >> bin4;

        // Convert Chars to Int
        digit1 = bin1 - '0';
        digit2 = bin2 - '0';
        digit3 = bin3 - '0';
        digit4 = bin4 - '0';
        
        // Convert Binary To Decimal
        num1 = (digit1 * 8) + (digit2 * 4) + (digit3 * 2) + digit4;

    } else {

        // Read in Decimal Number
        cin >> num1;

    }

    // Read in Operator
    cin >> op;

    // Check if Operator is '='
    if (op == '=') 
    {
        // Determine if Num1 Needs to be Binary
        if (num1 < 16) 
        {
            // Convert to Binary
            finalBin1 = num1 / 8;
            finalBin2 = (num1 - (8 * finalBin1)) / 4;
            finalBin3 = (num1 - (8 * finalBin1) - (4 * finalBin2)) / 2;
            finalBin4 = (num1 - (8 * finalBin1) - (4 * finalBin2) - (2 * finalBin3));

            // Output Answer
             cout << "B" << finalBin1 << finalBin2 << finalBin3 << finalBin4 << endl;

             // End Program
             return 0;

        } else {

            // Output Decimal
            cout << "D" << num1;

            // End Program
             return 0;
        }
    }

    // Enter Type 2 For Second Input
    cin >> type2;

    // Determine If Second Input is Binary
    if (type2 == 'B') 
    {
        // Read In All Digits
        char bin5, bin6, bin7, bin8;
        int digit5, digit6, digit7, digit8;
        cin >> bin5 >> bin6 >> bin7 >> bin8;

        // Convert Chars to Int
        digit5 = bin5 - '0';
        digit6 = bin6 - '0';
        digit7 = bin7 - '0';
        digit8 = bin8 - '0';
        
        // Convert Binary To Decimal
        num2 = (digit5 * 8) + (digit6 * 4) + (digit7 * 2) + digit8;

    } else {

        // Read in Decimal Number
        cin >> num2;
    }

    // Add Num1 & Num2
    total = num1 + num2;

    // If Total is Less than 16, Convert to Binary
    if (total < 16) 
    {
        finalBin1 = total / 8;
        finalBin2 = (total - (8 * finalBin1)) / 4;
        finalBin3 = (total - (8 * finalBin1) - (4 * finalBin2)) / 2;
        finalBin4 = (total - (8 * finalBin1) - (4 * finalBin2) - (2 * finalBin3));

        // Output Answer
        cout << "B" << finalBin1 << finalBin2 << finalBin3 << finalBin4 << endl;
    } else {

        // Output Answer
        cout << "D" << total << endl;
    }

    // End Program 
    return 0;
}