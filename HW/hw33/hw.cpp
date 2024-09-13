/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Read In User Numbers & Perform Linked List Operations
***************************************************/

// Import Libraries
#include <iostream>
#include "ll.h"
using namespace std;

int main()
{
  Node* L = NULL;

  // read the numbers into list L
  int d;
  while( cin >> d && d > 0)
    L = add2back(d, L);

  // print list L
  print(L);

  // handle the commands
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "enter" )
    {
      // enter d after x
      string s;
      int x;
      cin >> d >> s >> x;
      enter_after(d, x, L); 
    }
    else if ( cmd == "remove" )
    {
      // remove d
      cin >> d;
      L = remove(d, L); 
    }

    // print L
    print(L);
  }

  // delete the list 
  deletelist(L);
  return 0;
}
    