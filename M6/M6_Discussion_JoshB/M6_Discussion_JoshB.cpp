/*
    Student Name: Joshua Betancourt
    File Name: M6_Discussion_JoshB.cpp
    Date: 10/03/2024
    Description: This program is used to identify your birth month. User provides the number representing a calendar month.
*/

#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>  // library to help with random number generation found at https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
using namespace std;

int captureNumericInput (STRING message) {
    int userInput;
    cout << message;
    cin >> userInput;
    return userInput;
}

string identifyBirthMonth(integer providedHealth, ) {
    string month;
    switch (providedNumber)
    {
    case 1:
    case 2:
    case 12:
        break;
    case 3:
    case 4:
    case 5:
        month = "May";
        break;
    case 6:
    case 7:
    case 8:
        month = "August";
        break;
    case 9:
    case 10:
    case 11:
        month = "November";
        break;
    default:
        month = "out of range";
        break;
    }

    return month;
}

int main()
{
    cout << fixed << setprecision(2); // for setting the decimal precision
    locale loc(""); // for the thousands separator 
    cout.imbue(loc);
   
    // used to create seed/starting point for random number generator (rand() function call later in code)
    srand(time(0)); 

    // setting number of steps before losing
    float damage_taken = rand() % 100 + 1;

    enum { Death = 0, Low = 25, Medium = 70, Full = 100} playerHealth;
    string month;
    int providedNumber;

    cout << "\n\n  Welcome, let me identify your birth month." << endl;

    providedNumber = captureNumericInput("  Please provide the number representing your birth month: ");
    month = identifyBirthMonth(providedNumber);

    if (month != "out of range") {
        cout << "\n  Your birth month is " << month << endl;
    } else {
        cout << "\n  Sorry there is not a calendar month that aligns with your input." << endl;
    };
    
    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}


