/***************************************************
Filename: demo.cpp
Author: MIDN Ian Coffey (m261194)
demo
***************************************************/

// Import Libraries  
#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

int main() 
{
    int** Array = new int*[5];
    int count = 1;

    for (int i = 0; i < 5; i++) 
    {
        Array[i] = new int[3];

        for (int j = 0; j < 3; j++) 
        {
            Array[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
           cout << Array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
