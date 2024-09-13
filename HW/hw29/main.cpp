/***************************************************
Filename: main.cpp
Author: MIDN Ian Coffey (m261194)
Read Trial Data & Return Roach Position
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>
#include "point.h"

using namespace std;


int main()
{
    // Open file and read heading info
    int N;
    string s;
    ifstream fin("trial.txt");
    fin >> N >> s >> s;

    // Read and store data readings
    datum* A = new datum[N];
    for(int i = 0; i < N; i++)
        fin >> A[i]; 

    // Get the query time from the user
    hhmmss T;
    cout << "Enter a time: ";
    cin >> T; 

    // Find the first sighting at or after given time
    int k = 0; 
    while (k < N && A[k].time < T)
        k++;
    
    // Write result
    if (k == 0)
    {
        cout << "This was before the first sighting at ";
        cout << A[0].position << endl;
    }
    else if (k == N)
    {
        cout << "This was after the last sighting at ";
        cout << A[N-1].position << endl;
    }
    else
    {
        cout << "The roach was somewhere between ";
        cout << A[k-1].position << " and " << A[k].position << endl;
    }

    return 0;
}

