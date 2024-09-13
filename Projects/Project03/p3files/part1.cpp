/***************************************************
Filename: part1.cpp
Author: MIDN Ian Coffey (m261194)
Read a Board File & Output To Ncurses Screen
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "easycurses.h"
#include "Pos.h"
#include "mylib.h"

using namespace std;

int main() 
{
    // Variable Declaration
    int rows, cols, numZ, startX, startY;
    Spawn* SPAWNLIST = NULL;
    string fileName;
    char c;

    // Prompt File Name
    cout << "board file: ";
    cin >> fileName;
    ifstream fin(fileName);

    // Read In Row & Column #s from File
    if (ifstream(fileName)) 
    {
        fin >> rows >> c >> cols;

    } else {

        cout << "Bad File Name" << endl;
        return 0;
    }

    // Start Ncurses
    startCurses();

    // Declare 2d Array for Board
    char** board = new char*[rows];
    fin >> numZ;

    // Get Rid of New Line in File
    c = fin.get();

    // Read In & Print Out Board Information
    for (int i = 0; i < rows; i++) 
    {
        // Offset Cols by 1 to Deal With New Line
        board[i] = new char[cols + 1];

        for (int j = 0; j <= cols; j++) 
        {
            board[i][j] = fin.get();

            // Ensure that Board Is Not Outputting New Line
            if (board[i][j] != '\n') 
            {
                if (board[i][j] == 'Z') 
                {        
                    drawChar(' ', i, j);

                    // Create New Position To Add To Linked List
                    Pos newSpawn{i, j};
                    SPAWNLIST = add2back(newSpawn, SPAWNLIST);
                }
                else if (board[i][j] == 'Y')
                {
                    drawChar(' ', i, j);
                    startX = i;
                    startY = j;

                } else {
                    drawChar(board[i][j], i, j);
                }
            }
        }
    }

    refreshWindow();

    // Keep User In Ncurses Until User Presses Y
    char z;
    do 
    {
        usleep(150000); 
        z = inputChar();

    } while(z != 'y'); 

    // Close Window
    endCurses();

    // Output Player Starts & Spawns
    cout << "Player start: (" << startX << "," << startY << ")" << endl;
    cout << "Spawn spots: ";
    printSpawnList(cout, SPAWNLIST);

    // Delete Arrays
    for (int i = 0; i < rows; i++) 
    {
        delete[] board[i];
    }

    delete[] board;
    deleteSpawnList(SPAWNLIST);

    // Close Program
    return 0;
}