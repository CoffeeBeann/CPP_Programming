/***************************************************
Filename: part2.cpp
Author: MIDN Ian Coffey (m261194)
Read a Board File & Simulate Player 
***************************************************/

// Got Help With MGSP

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
    Pos playerPos, goalPos;
    Spawn* SPAWNLIST = NULL;
    Player player;
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
                    // Draw & Initialize Player Object
                    drawChar('P', i, j);
                    playerPos = Pos{i, j};

                    // Create New Player & Set Previous Loc To Spawn Location
                    player = {playerPos, playerPos, 0, false, NULL};

                    // Save Start Position
                    startX = i;
                    startY = j;
                } 
                else if (board[i][j] == 'X') 
                {
                    // Save Goal Position
                    goalPos = Pos{i, j};
                    drawChar(board[i][j], i, j);
                } 
                else {

                    drawChar(board[i][j], i, j);
                }
            }
        }
    }

    refreshWindow();

    // Variable Declarations For Upcoming Loop
    int direction = 0, score = 500;

    do 
    {
        // Erase Player Character
        drawChar(' ', player.loc.row, player.loc.col); 

        // Update Direction
        switch(direction)
        {
            case 'w':
                player.dir = 0;
                player.isMoving = true;
                break;
            case 'a':
                player.dir = 3;
                player.isMoving = true;
                break;
            case 's':
                player.dir = 2;
                player.isMoving = true;
                break;
            case 'd':
                player.dir = 1;
                player.isMoving = true;
                break;
            case 'r':
                player.isMoving = false;
            default:
                break;
        }

        // Check If Player Decided To Move
        if (player.isMoving) 
        {
            // Create Temp Location to Test if Updated Location Runs Into Wall
            Pos temp = step(player.loc, player.dir);

            // Check For Walls
            if (board[temp.row][temp.col] == '#') 
            {
                // Change Directions
                player.dir = turn(player.dir, 180);
                
                // Check If Player is Stuck Between Two Walls
                temp = step(player.loc, player.dir);

                if (board[temp.row][temp.col] == '#') 
                {
                    // Stop Moving If Stuck
                    player.isMoving = false;

                } else {

                    // No Double Wall, bounce as Normal
                    player.loc = step(player.loc, player.dir);
                }

            } else {

                // No Wall Detected, Step as Normal
                player.loc = step(player.loc, player.dir);

            }
        }

        // Draw New Position
        drawChar('P', player.loc.row, player.loc.col);
 
        refreshWindow();
        usleep(100000);
        direction = inputChar();
        score--;

    } while(!closeToX(player.loc, goalPos)); 

    // Close Window
    endCurses();

    // Output Player Starts & Spawns
    cout << "Player start: (" << startX << "," << startY << ")" << endl;
    cout << "Spawn spots: ";
    printSpawnList(cout, SPAWNLIST);
    cout << "You won, high score = " << score << endl;

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