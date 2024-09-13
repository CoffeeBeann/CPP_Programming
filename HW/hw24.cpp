/***************************************************
Filename: hw24.cpp
Author: MIDN Ian Coffey (m261194)
Define a Power Function
***************************************************/

#include <iostream>
using namespace std;

double pow(double, int);

int main()
{
  double x;
  int n;
  cout << "Enter x and n: ";
  cin >> x >> n;
  cout << "x^n is " << pow(x,n) << endl;
  return 0;
}

// Define pow: it must be recursive!
double pow(double a, int b) 
{
    // Base Case
    if (b == 1) 
    {
        return a;
    }
    // Recusion
    else 
    {
        return a * pow(a,b-1);
    }
}