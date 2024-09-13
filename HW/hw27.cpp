/***************************************************
Filename: hw27.cpp
Author: MIDN Ian Coffey (m261194)
Create Vector Multiplication Program
***************************************************/

// Import Libraries
#include <iostream>

using namespace std;

// Struct Definition
struct Point3
{
  double x, y, z;
};

// Overloading Operator Prototypes
istream& operator >>(istream& IN, Point3& a);
ostream& operator <<(ostream& OUT, Point3& a);
double operator *(Point3& a, Point3& b);

// Main
int main()
{
  Point3 a, b;

  cin >> a >> b;

  cout << "Inner product of " << a << " and " << b
       << " is " << a*b << endl;

  return 0;
}

// Overloading >> Functions
istream& operator >>(istream& IN, Point3& a) 
{
    char c;

    // Input Vectors
    return IN >> c >> a.x >> c >> a.y >> c >> a.z >> c;
}

// Overloading << Function
ostream& operator <<(ostream& OUT, Point3& a) 
{
    return OUT << "(" << a.x << ", " << a.y << ", " << a.z << ")";
}

// Overloading * Function
double operator *(Point3& a, Point3& b) 
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

