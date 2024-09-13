/***************************************************
Filename: mylib.h
Author: MIDN Ian Coffey (m261194)
Library File For Functions and Structs
***************************************************/

// Import Libraries
#pragma once
#include <iostream>
#include "Pos.h"

using namespace std;

// Struct Definition for Spawn Points
struct Spawn        
{
    Pos loc;
    Spawn* next;
};

// Struct Definition for Player 
struct Player 
{
    Pos loc;
    Pos prevLoc;
    int dir;
    bool isMoving;
    Player* next;
};

// Struct Definition for Space Ship
struct Ship
{
    Pos loc;
    Pos prevLoc;
    int dir;
};

// Struct Definition for Each Iteration of Game
struct Round 
{
    string name;
    int shipSpawn;
    int hunterSpawn;
    int points;
    Round* next;
};

// Overloading Prototypes
istream& operator >> (istream& is, Round& newRound);

// Function Prototypes
Spawn* add2back(Pos newSpawn, Spawn* oldList);
Round* add2back(Round newGame, Round* oldList);
void deleteSpawnList(Spawn* List);
void printSpawnList(ostream& os, Spawn* List);
bool closeToX(Pos current, Pos goal);
int length(Spawn* List);