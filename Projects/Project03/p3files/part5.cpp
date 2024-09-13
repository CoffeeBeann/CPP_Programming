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
    int rows, cols, numZ, startX, startY, totalScore = 0, lives = 3;
    Pos playerPos, goalPos;
    Round* gameRound = NULL;
    Player player;
    string fileName;
    bool collidedWithShip = false;
    bool collidedWithHunter = false;
    bool gameOver = false;
    bool nextGame = false;
    char c;

    // Declare Game Script Input Stream
    ifstream script("gameScript.txt");

    // Read Game Script File & Store Information
    Round newRound;
    do 
    {
        string a;
        char c;
        script >> newRound;
        gameRound = add2back(newRound, gameRound);
    }
    while (script >> newRound);

    // For Loop TO Run Untill gameScript is Empty
    for (Round* A = gameRound; A != NULL; A = A->next) 
    {
        // Output Board File information to Terminal
        cout << "board file: " << A->name << " " << "(" <<
        A->shipSpawn << "," << A->hunterSpawn << "," << A->points << ")" << endl;

        // Create New Linked List
        Spawn* SPAWNLIST = NULL;
        
        // Add to Total Score
        totalScore += A->points;

        // Load new Board & Read Dimensions
        ifstream fin(A->name);
        fin >> rows >> c >> cols;

        // Declare 2d Array for Board
        char** board = new char*[rows];
        fin >> numZ;

        // Get Rid of New Line in File
        c = fin.get();

        // Start Ncurses
        startCurses();

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

        // Intitialize & Create Space Ship & Hunter Arrays With Length of Spawn List
        int count = 0, listLength = length(SPAWNLIST);
        Ship** shipList = new Ship*[listLength];
        Player** hunterList = new Player*[listLength];

        // Assign Designated Ships & Hunters to Each Spawn Point
        for (Spawn* T = SPAWNLIST; T != NULL; T = T->next) 
        {
            shipList[count] = new Ship[A->shipSpawn]; 
            hunterList[count] = new Player[A->hunterSpawn];

            // Hunter Assignment
            for (int k = 0; k < A->hunterSpawn; k++) 
            {
                hunterList[count][k].loc = T->loc;
                hunterList[count][k].prevLoc = T->loc;
                hunterList[count][k].dir = (rand() % 4);
            }

            // Ship Assignment
            for (int i = 0; i < A->shipSpawn; i++) 
            {
                // Intitialize Ship Variables
                shipList[count][i].loc = T->loc;
                shipList[count][i].prevLoc = T->loc;
                shipList[count][i].dir = (rand() % 4);

            }
            
            // Increment Count
            count++;
        }
        
        // Variable Declarations For Upcoming Loop
        int direction = 0;

        do 
        {
            // Erase Player Character, Ships, & Hunters
            drawChar(' ', player.loc.row, player.loc.col); 

            // Nested For Loop To Erase Hunters & Ships
            for (int i = 0; i < listLength; i++) 
            {
                for (int j = 0; j < A->shipSpawn; j++) 
                {
                    // Be Sure to Not Delete "x" In case of overlapp
                    if (board[shipList[i][j].loc.row][shipList[i][j].loc.col] != 'X') 
                    {
                        drawChar(' ', shipList[i][j].loc.row, shipList[i][j].loc.col); 
                    }
                }

                for (int k = 0; k < A->hunterSpawn; k++) 
                {
                    // Ensure That Hunters Don't Hit X
                    if (board[hunterList[i][k].loc.row][hunterList[i][k].loc.col] != 'X') 
                    {
                        drawChar(' ', hunterList[i][k].loc.row, hunterList[i][k].loc.col); 
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
                for (int j = 0; j < A->shipSpawn; j++) 
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

            // Update Hunter Directions
            for (int i = 0; i < listLength; i++) 
            {
                for (int j = 0; j < A->hunterSpawn; j++) 
                {
                    // 50/50 Chance of Changing Direction
                    if ((rand() % 2) >= 0) 
                    {
                        // 50/50 Chance of moving Column Position or Row Position
                        if ((rand() % 2) == 0) 
                        {
                            // Caclulate Column Change
                            int dc = player.loc.col - hunterList[i][j].loc.col;

                            if (dc < 0) 
                                hunterList[i][j].dir = 3; // West
                            else    
                                hunterList[i][j].dir = 1; // East

                        } else {

                            int dr = player.loc.row - hunterList[i][j].loc.row;

                            if (dr < 0)
                                hunterList[i][j].dir = 0; // North
                            else    
                                hunterList[i][j].dir = 2; // South
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

            // Check if Ships or hunter run into any Walls
            for (int i = 0; i < listLength; i++) 
            {  
                Pos temp;

                for (int k = 0; k < A->hunterSpawn; k++) 
                {
                    temp = step(hunterList[i][k].loc, hunterList[i][k].dir); 

                    if (board[temp.row][temp.col] == '#') 
                    {
                        // Swich Direction
                        hunterList[i][k].dir = turn(hunterList[i][k].dir, 180);
                    }

                    // Save Previous Hunter Position For Future Collision Detection
                    hunterList[i][k].prevLoc = hunterList[i][k].loc;

                    // Step Hunter in New Direction
                    hunterList[i][k].loc = step(hunterList[i][k].loc, hunterList[i][k].dir);
                }

                // Check For Ship Collision With walls
                for (int j = 0; j < A->shipSpawn; j++) 
                {
                    temp = step(shipList[i][j].loc, shipList[i][j].dir);

                    if (board[temp.row][temp.col] == '#') 
                    {
                        // Swich Direction
                        shipList[i][j].dir = turn(shipList[i][j].dir, 180);  
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

            // Draw New Hunter Positions
            for (int i = 0; i < listLength; i++) 
            {
                for (int j = 0; j < A->hunterSpawn; j++) 
                {
                    if (board[hunterList[i][j].loc.row][hunterList[i][j].loc.col] != 'X') 
                    {
                        drawChar('K', hunterList[i][j].loc.row, hunterList[i][j].loc.col); 
                    }
                }
            }

            // Check if hunters Caught Player
            for (int i = 0; i < listLength; i++) 
            {
                for (int j = 0; j < A->hunterSpawn; j++) 
                {
                    if (equal(player.loc, hunterList[i][j].loc) || equal(player.loc, hunterList[i][j].prevLoc)) 
                    {
                        lives--;
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
                        lives--;
                    }
                }
            } 

            // Check For Round Completion
            nextGame = closeToX(player.loc, goalPos);

            // Refresh Window & Sleep
            usleep(100000);
            refreshWindow();
    
            direction = inputChar();
            totalScore--;

        } while((lives != 0) && !nextGame);

        if (lives <= 0) 
        {
            usleep(2000000);
        }

        endCurses();

        // Output Player Starts & Spawns
        cout << "Player start: (" << startX << "," << startY << ")" << endl;
        cout << "Spawn spots: ";
        printSpawnList(cout, SPAWNLIST);

        if (lives <= 0) 
        {
            cout << "You lost, they got you!" << endl;
            break;

        } else {

            cout << "You won, high score = " << totalScore << endl;
        }

        // Reset or delete Variables & Prepare For Next Round
        nextGame = false;

        // Delete Arrays
        for (int i = 0; i < rows; i++) 
        {
            delete[] board[i];
        }

        delete[] board;
        deleteSpawnList(SPAWNLIST);

    }

    // Close Program
    return 0;
}
