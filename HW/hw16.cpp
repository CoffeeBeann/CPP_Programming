/***************************************************
Filename: hw16.cpp
Author: MIDN Ian Coffey (m261194)
Read In Frations From User & Determine Simplification
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

// Function Prototpe Declaration
int greatestDivisor(int a, int b);
bool isPrimeK(int a);

int main()
{
    // Variable Declaration
    int num1, num2, lowestTerm, factor;
    char slash = 'x';

    // Read In User Input With While Loop
    while (slash != ';') 
    {
        // Read in New Numbers
        cin >> num1 >>  slash >> num2 >> slash;

        // See if Num1 or Num2 are Prime
        if (isPrimeK(num1) || isPrimeK(num2)) 
        {
            cout << num1 << "/" << num2 << " is in lowest terms" << endl;
        }
    }
}

// Definition for isPrimeK
bool isPrimeK(int a)
{
    // Check if Number is 1
    if (a == 1) 
    {
        return false;
    }

    // Determine What Number Evenly Divises A
    for (int i = 2; i < a; i++) 
    {
        if (a % i == 0) 
        {
            return false;
        }
    }

    return a;
}

// Definition for greatestDivisor
int greatestDivisor(int a, int b) 
{
    // Determine Greatest Common Divisor
    int factor;

    while (b != 0) 
    {
        factor = a % b;
        a = b;
        b = factor;
    }

    // Return Answer
    return a;
}