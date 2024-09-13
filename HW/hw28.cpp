/***************************************************
Filename: hw28.cpp
Author: MIDN Ian Coffey (m261194)
Create A Schedule Query Program
***************************************************/

// Import Libraries
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Struct Definitions
struct Section
{
    string name;
    string days;
    int id;
};


// Overloading Prototype Functions
Section* read(ifstream* is, int* n);
void searchByCourse(Section* section, int n);
void searchBySection(Section* section, int n);
void searchByDay(Section* section, int n);


int main()
{
    string fname;
    cout << "Filename: ";
    cin >> fname;
    ifstream fin(fname);

    int n;
    Section* sections = read(&fin, &n);

    string cmd;
    cout << "> ";
    while( (cin >> cmd) && (cmd != "quit") )
    {
        if( cmd == "course" )
            searchByCourse(sections, n);
        else if ( cmd == "section" )
            searchBySection(sections, n);
        else if ( cmd == "day" )
            searchByDay(sections, n);

        cout << endl << "> ";
    }


    delete [] sections;
    return 0;
}

// Function to Read File & Store it Into An Array
Section* read(ifstream* is, int* n) 
{
    // Variable Declarations
    char junk;
    int size;

    // Read in N
    *is >> junk >> junk >> *n;

    Section* section = new Section[*n];

    // Traverse File To Read In Information
    for (int i = 0; i < *n; i++) 
    {
        *is >> section[i].name >> section[i].id >> section[i].days;
    }

    // Return Pointer 
    return section;
}
\// Function to Search for a Course by Course Name
void searchByCourse(Section* section, int n) 
{
    // Variable Declarations
    string course;
    cin >> course;

    // Traverse Array To Find Mathcing Course
    for (int i = 0; i < n; i++) 
    {
        if (section[i].name == course) 
        {
            cout << section[i].name << " " << section[i].id << " " << section[i].days << endl;
        }
    }

}

// Function to Search For a Course by Section Number
void searchBySection(Section* section, int n) 
{
    // Variable Declarations
    int sect;
    cin >> sect;

    // Traverse Array To Find Mathcing Section
    for (int i = 0; i < n; i++) 
    {
        if (section[i].id == sect) 
        {
            cout << section[i].name << " " << section[i].id << " " << section[i].days << endl;
        }
    }
}

// Function To Search For A Course By Day
void searchByDay(Section* section, int n) 
{
    // Variable Declarations
    char day;
    cin >> day;

    // Traverse Array To Find Mathcing Day
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < section[i].days.length(); j++) 
        {
            if (section[i].days[j] == day) 
            {
                cout << section[i].name << " " << section[i].id << " " << section[i].days << endl;
            }
        }
    }
}
