/***************************************************
Filename: hw18.cpp
Author: MIDN Ian Coffey (m261194)
Compute the Dot Product of Two Given Vectors
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

int main () 
{
    // Variable Declarations
    char discard, arrayOne, arrayTwo;
    double total = 0;
    int n;


    // Read in Array Length
    cin >> discard >> discard >> n;

    // Declare Array Objects
    double *X = new double[n];
    double *Y = new double[n];

    // Read In First Array Name
    cin >> arrayOne >> discard >> discard;

    // Read In First Array Information
    for (int i = 0; i < n; i++) 
    {
        cin >> X[i] >> discard;
    }

    // Read In Second Array Name
    cin >> arrayTwo >> discard >> discard;

    // Read In First Array Information
    for (int j = 0; j < n; j++) 
    {
        cin >> Y[j] >> discard;
    }

    // Output Formatting for Answer
    cout << "<" << arrayOne << "," << arrayTwo << "> = ";

    // Use For Loop To Output Contents of Array One & Two In Answer Format
    for (int i = 0; i <= n - 1; i++) 
    {
        // Determine If Brackets Need to be Placed Around X[i] 
        if (X[i] < 0) 
        {
            cout << "(" << X[i] << ") " ;

        } else {
            
            cout << X[i] << " ";
        }

        // Add Addition Sign Between X[i] & Y[i]
        cout << "* ";

        // Determine If Brackets Need to be Placed Around Y[i] 
        if (Y[i] < 0) 
        {
            cout << "(" << Y[i] << ") " ;

        } else {
            
            cout << Y[i] << " ";
        }

        // Check If Equal Sign Needs to Be Added To Sequence
        if (i == n - 1) 
        {
            cout << "= ";

        } else {

            cout << "+ ";

        }

        // Calculate Total
        total += (X[i] * Y[i]);
    }

    // Output Total
    cout << total << endl;

    // End Program
    return 0;
}