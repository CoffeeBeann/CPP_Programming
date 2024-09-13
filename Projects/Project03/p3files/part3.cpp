/***************************************************
Filename: part3.cpp
Author: MIDN Ian Coffey (m261194)
Simulate Player With Space Ship
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
    // Set Random Time
    srand(time(0));

    // Variable Declaration
    int rows, cols, numZ, startX, startY;
    Pos playerPos, goalPos;
    Spawn* SPAWNLIST = NULL;
    Player player;
    string fileName;
    bool collidedWithShip = false;
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

    // Intitialize & Create Space Ship Array With Length of Spawn List
    int count = 0, listLength = length(SPAWNLIST);
    Ship** shipList = new Ship*[listLength];

    // Assign 5 Ships to Each Spawn Point
    for (Spawn* T = SPAWNLIST; T != NULL; T = T->next) 
    {
        shipList[count] = new Ship[5]; 

        for (int i = 0; i < 5; i++) 
        {
            // Intitialize Current & Previous Location
            shipList[count][i].loc = T->loc;
            shipList[count][i].prevLoc = T->loc;

            // Randomly Assign Direction To Each Ship
            shipList[count][i].dir = (rand() % 4);

        }
        
        // Increment Count
        count++;
    }
        
    // Variable Declarations For Upcoming Loop
    int direction = 0, score = 500;

    do 
    {
        // Erase Player Character & Ships
        drawChar(' ', player.loc.row, player.loc.col); 
        for (int i = 0; i < listLength; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                // Be Sure to Not Delete "x" In case of overlapp
                if (board[shipList[i][j].loc.row][shipList[i][j].loc.col] != 'X') 
                {
                    drawChar(' ', shipList[i][j].loc.row, shipList[i][j].loc.col); 
                }
            }
        }

        // Update Player Direction
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

        // Update Ship Directions
        for (int i = 0; i < listLength; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                // 1 in 10 Chance To Move Ship
                if ((rand() % 10) == 0) 
                {
                    // 1 in 2 Chance between left or right
                    if ((rand() % 2) == 0) 
                    {
                        shipList[i][j].dir = turn(shipList[i][j].dir, 90);

                    } else {

                        shipList[i][j].dir = turn(shipList[i][j].dir, -90);
                    }

                }

            }

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

        // Check if Ships run into any Walls
        for (int i = 0; i < listLength; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                Pos temp = step(shipList[i][j].loc, shipList[i][j].dir);

                if (board[temp.row][temp.col] == '#') 
                {
                    // Swich Direction
                    shipList[i][j].dir = turn(shipList[i][j].dir, 180);  

                    // Check if ship is stuck
                }

                // Save Previous Position For Future Collision Detection
                shipList[i][j].prevLoc = shipList[i][j].loc;

                // Step in New Direction
                shipList[i][j].loc = step(shipList[i][j].loc, shipList[i][j].dir);
            }
        }
        
        // Draw New Position For Player
        drawChar('P', player.loc.row, player.loc.col);

        // Draw New Position For Ships With Nested For Loops
        for (int i = 0; i < listLength; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                if (board[shipList[i][j].loc.row][shipList[i][j].loc.col] != 'X') 
                {
                    drawChar('*', shipList[i][j].loc.row, shipList[i][j].loc.col);
                }
            }
        }

        // Check If Player Collided With Ship
        for (int i = 0; i < listLength; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                if (equal(player.loc, shipList[i][j].loc) || equal(player.loc, shipList[i][j].prevLoc))
                {
                    collidedWithShip = true;
                }
            }
        }   

        // Check for Collision for sleep
        if (collidedWithShip) 
        {
            usleep(2000000);
        }
        else {

            // Refresh Window & Sleep
            usleep(100000);
            refreshWindow();
        }
  
        direction = inputChar();
        score--;

    } while(!closeToX(player.loc, goalPos) && (!collidedWithShip));

    // Close Window
    endCurses();

    // Output Player Starts & Spawns
    cout << "Player start: (" << startX << "," << startY << ")" << endl;
    cout << "Spawn spots: ";
    printSpawnList(cout, SPAWNLIST);

    // Check If Player Lost or Not
    if (collidedWithShip) 
    {
        cout << "You lost, they got you!" << endl;

    } else {

        cout << "You won, high score = " << score << endl;
    }
    
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