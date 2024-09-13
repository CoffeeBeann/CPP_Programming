/***************************************************
Filename: hw26.cpp
Author: MIDN Ian Coffey (m261194)
Simulate Car Tracking Program
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

// Struct Definition
struct car 
{
    char name;
    double vel;
    double pos;
};

int main()
{
    // Variable & File Declarations
    string junk, fname;
    char c;
    int n;

    // Read In & Declare File
    cin >> fname;
    ifstream carInfo(fname);

    // Read in N
    carInfo >> c >> c >> n;

    // Declare Array of Cars
    car* list = new car[n];

    // Traverse Data In File To Initilize Cars
    for (int i = 0; i < n; i++) 
    {
        carInfo >> list[i].name >> junk >> list[i].pos >> junk >> list[i].vel;
    }

    // Output Car Positions From 0 - 8 Hours Using For Loop
    for (int i = 0; i < 9; i++) 
    {
        cout << "hour " << i << " ";

        for (int j = 0; j < n; j++) 
        {
            // Update Position for Car
            cout << "[" << list[j].name << ":" << (list[j].pos + (i * list[j].vel)) << "]";
        }

        cout << endl;
    }

    // Delete Arrays
    delete [] list;

    return 0;
}