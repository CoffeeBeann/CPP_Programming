#pragma once 
#include <iostream>
using namespace std;

struct point
{
  double x, y;
};

istream& operator >> (istream& is, point& p);
ostream& operator << (ostream& os, point p);
point operator + (point a, point b);
point operator / (point p, double z);