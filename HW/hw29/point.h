
// Import Libraries
#pragma once
#include <iostream>
using namespace std;

// Struct Definitions
struct point
{
  double x, y;
};

// Function Prototypes for Points
istream& operator >> (istream& in, point& p);
ostream& operator << (ostream& os, point p);

// Time Struct Definition
struct hhmmss
{
  int h,m,s;
};

// Function Protoypes For Time
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);

// Datum Struct Definition
struct datum
{
  point position;
  hhmmss time;
};

// Function Prototype for Datum
istream& operator >> (istream& is, datum& D);
 