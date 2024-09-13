/***************************************************
Filename: hw19.cpp
Author: MIDN Ian Coffey (m261194)
Output a Given Array of Asteriks and Peform Functions
***************************************************/

#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================
int readN();
int* readData(int n);
void show(int* A, int n);
void swap(int* A, int n); 


// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd = "show";
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  return 0;
}


// ======================================
// Function definitions below
// ======================================
int readN() 
{
    // Variable Declaration
    int n;
    char discard;

    // Read In N
    cin >> discard >> discard >> n;

    // Return n
    return n;
}

int* readData(int n) 
{
    // Create New Array
    int* B = new int[n];

    // Read In Information
    for (int i = 0; i < n; i++) 
    {
        cin >> B[i];
    }

    // Return Pointer
    return B;
}

void show(int* A, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "[" << i << "] ";

        for (int j = 0; j < A[i]; j++) 
        {
            cout << "*";
        }

        cout << endl;
    }
}

void swap(int* A, int n) 
{
    // Local Variable Declaration
    int rowNum1, rowNum2, temp;

    // Read in Rows to Swap
    cin >> rowNum1 >> rowNum2;

    temp = A[rowNum1];

    A[rowNum1] = A[rowNum2];

    A[rowNum2] = temp;

}
