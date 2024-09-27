// M5_Discussion_JoshB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Student Name: Joshua Betancourt
    File Name: M5_Discussion_JoshB.cpp
    Date: 09/26/2024
    Description: This program is used to identify your birth month. User provides the number representing a calendar month.
*/

#include <conio.h>
#include <iostream>
using namespace std;

int captureNumericInput (STRING message) {
    int userInput;
    cout << message;
    cin >> userInput;
    return userInput;
}

string identifyBirthMonth(integer providedNumber) {
    string month;
    switch (providedNumber)
    {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 1:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    default:
        month = "out of range";
        break;
    }

    return month;
}

int main()
{
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

