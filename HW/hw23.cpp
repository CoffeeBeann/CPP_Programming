/***************************************************
Filename: hw23.cpp
Author: MIDN Ian Coffey (m261194)
Sum the Given Rows & Col to Determine Multiples of 3
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;


int main() 
{
    // Variable Declarations
    int row, col;
    char c;

    // Prompt User Input
    cout << "What size? ";
    cin >> row >> c >> col;

    // Declare New int**
    int** A = new int*[row];

    // Initialize Matrix
    for (int i = 0; i < row; i++) 
    {
        // Initialize int* A[i]
        A[i] = new int[col];

        for (int j = 0; j < col; j++) 
        {
            // Place New Value Into A[i][j]
            cin >> A[i][j];
        }
    }

    cout << "rows: ";

    // Sum the Rows To Determine Multiplicatives of 3
    for (int i = 0; i < row; i++) 
    {
        int total = 0;

        for (int j = 0; j < col; j++) 
        {
            total += A[i][j];
        }

        if (total % 3 == 0) 
            cout << i << " ";
    
    }

    cout << "\ncols: ";

    // Sum the Cols To Determine Multiplicatives of 3
    for (int i = 0; i < col; i++) 
    {
        int total = 0;
        
        for (int j = 0; j < row; j++) 
        {
            total += A[j][i];
        }

        if (total % 3 == 0) 
            cout << i << " ";
    
    }

    // End Program
    return 0;
}

