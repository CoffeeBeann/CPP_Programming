/***************************************************
Filename: mylib.cpp
Author: MIDN Ian Coffey (m261194)
Function Definitions for mylib.h
***************************************************/

// Import Libraries
#include <iostream>
#include "Pos.h"
#include "mylib.h"

// Overload Definitions
istream& operator >> (istream& is, Round& round) 
{
    string a;
    char c;
    return is >> round.name >> round.shipSpawn 
    >> round.hunterSpawn >> a >> c >> round.points;
}

// Function To Add New Data To The Front of A Linked List
Spawn* add2back(Pos newSpawn, Spawn* oldList) 
{
    // Base Case For Empty List
    if (oldList == NULL) 
    {
        // Return New Node @ Back Of List
        return new Spawn{newSpawn, NULL};

    } else {

        // Case If List is Not Empty
        Spawn* last = oldList;

        // Traverse To Back of List
        while (last->next != NULL) 
        {
            last = last->next;
        }

        // Add New Node
        last->next = new Spawn{newSpawn, NULL};

        // Return New List
        return oldList;
    }
}

// Function to add2back for Game Rounds
Round* add2back(Round newRound, Round* oldList) 
{
    // Base Case For Empty List
    if (oldList == NULL) 
    {
        // Return New Node @ Back Of List
        return new Round{newRound.name, newRound.shipSpawn, 
        newRound.hunterSpawn, newRound.points, NULL};

    } else {

        // Case If List is Not Empty
        Round* last = oldList;

        // Traverse To Back of List
        while (last->next != NULL) 
        {
            last = last->next;
        }

        // Add New Node
        last->next = new Round{newRound.name, newRound.shipSpawn, 
        newRound.hunterSpawn, newRound.points, NULL};

        // Return New List
        return oldList;
    }
}

// Function To Delete A Given List
void deleteSpawnList(Spawn* List) 
{
    // Base Case
    if (List == NULL) 
    {
        return;

    } else {

        // Iterate To The Next Node
        deleteSpawnList(List->next);

        // Delete Node
        delete List;
    }

}

// Function To Print A Given Spawn List To The Console
void printSpawnList(ostream& os, Spawn* List) 
{
    // Output Data Using For Loop
    for (Spawn* T = List; T != NULL; T = T->next) 
    {
        os << "(" << T->loc.row << "," << T->loc.col << ") ";
    }
    
    // New Line
    os << endl;
}

bool closeToX(Pos current, Pos goal) 
{
    // Check If Player Is Within 1 Space of X
    return (abs(current.row - goal.row) <= 1) && (abs(current.col - goal.col) <= 1);
}

// Function To Find the Length of A Given List
int length(Spawn* List) 
{
    int length = 0;

    for (Spawn* T = List; T != NULL; T = T->next) 
    {
        length++;
    }

    return length;
}