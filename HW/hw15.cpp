#include <iostream>
using namespace std;

//==========================================
// Give the prototype of firstfactor below
//==========================================

int firstfactor(int a);

// main function
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next prime factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}


//==========================================
// Define firstfactor below
//==========================================

int firstfactor(int a) 
{
    int factor = 2;

    while (a % factor != 0) 
    {
        factor++;
    }

    return factor;

}