/*
    Student Name: Joshua Betancourt
    File Name: Michael_Giuliano_M4_Discussion.cpp
    Date: 09/19/2024
    Description: This program is the working solution for Michael's M4 Discussion Submission
*/

#include <cmath>
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // creating variables for program
    bool isRunning = true;
    char fillChar = '*';
    double charsPerRow;
    double cumulativeWidth = 0.0;
    int charsToPrint;
    int height;
    int margin;
    int width;

    // Display banner and get mountain dimensions from user
    cout << endl
         << "\n\n  **************************************************" << endl
         << "  **               Mountain Drawer                **" << endl
         << "  **************************************************" << endl;
    cout << "\n  How many characters tall do you want your mountain? ";
    cin >> height;
    cout << "\n  How many characters wide do you want your mountain? ";
    cin >> width;
    cout << endl;

    // Calculate how many characters per row for an even slope
    charsPerRow = (double) width / height;

    // Loop to print each row of the mountain
    for (int i = 1; i <= height; i++)
    {
        cumulativeWidth += charsPerRow;

        // Ensure min number of chars to print is 1
        if (cumulativeWidth < 0.5)
            charsToPrint = 1;
        else
            charsToPrint = round(cumulativeWidth);

        // Calculate the number of spaces to print to center the mountain row
        margin = round((width - charsToPrint) / 2);

        // Print the mountain row
        cout << "  ";
        cout << setw(margin) << setfill(' ') << "";
        cout << setw(charsToPrint) << setfill(fillChar) << "" << endl;
    }

    // Display the closing message for non Visual Studio IDEs
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}