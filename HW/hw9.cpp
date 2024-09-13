/***************************************************
Filename: hw.cpp
Author: MIDN Ian Coffey (m261194)
Input Student Grades & Output Statistics
***************************************************/

// Import Libraries
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    // Variable Declaration
    string file, bestStudent, trash, studentName;
    int hw, quiz, exam;
    float grade, bestGrade = 0;

    // Prompt User Input
    cout << "Filename: ";
    cin >> file;

    // Declare Ifstream Object 
    ifstream inputFile(file);

    // Read in & Discard Unnecessary Information
    inputFile >> trash >> trash >> trash >> trash;

    // Loop Runs Until File Ends
    while (inputFile >> studentName >> hw >> quiz >> exam) 
    {
        grade = (hw * 0.2) + (quiz * 0.2) + (exam * 0.6);

        if (grade > bestGrade) 
        {
            bestGrade = grade;
            bestStudent = studentName;
        }

        // Output Student Statistics
        cout << studentName << "    " << grade << endl;
    }

    // Output Best Student
    cout << "The Best Student is " << bestStudent << endl;

    // End Program
    return 0;
}