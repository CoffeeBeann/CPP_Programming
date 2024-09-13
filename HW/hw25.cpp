/***************************************************
Filename: hw25.cpp
Author: MIDN Ian Coffey (m261194)
Define a Recursive Function to Return Spaces
***************************************************/

#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
  int sp = 0;

  if( num < 0 )
  {
    sp++;         // +1 for '-' sign
    num = -num;   // make num positive
  }

  if ((num / 10) > 0) 
  {
    sp++;
    num /= 10;
    return (sp + calspace(num));
  }
  else 
  {
    sp++;
    return sp;
  }
}