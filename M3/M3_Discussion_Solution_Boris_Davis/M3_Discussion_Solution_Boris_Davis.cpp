// M3_Discussion_Solution_Boris_Davis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Student Name: Boris Davis
    File Name: M3_Discussion.cpp
    Date: 9/11/2024

    Description: This program displays the season based on the month entered.
*/

#include <iostream>
#include <conio.h>

using namespace std;


int main()

{
    int num;

    cout << "\n\n  Find out was season you where born in." 
            "\n  Enter a number 1-12 to represent the month you where born. For example 1 would be for January: ";
    cin >> num;
    cout << endl;


    if (num == 1)
        cout << "\n  January: Winter" << endl;
    else if (num == 2)
        cout << "\n  February: Winter" << endl;
    else if (num == 3)
        cout << "\n  March: Spring" << endl;
    else if (num == 4)
        cout << "\n  April: Spring" << endl;
    else if (num == 5)
        cout << "\n  May: Spring" << endl;
    else if (num == 6)
        cout << "\n  June: Summer" << endl;
    else if (num == 7)
        cout << "\n  July: Summer" << endl;
    else if (num == 8)
        cout << "\n  August: Summer" << endl;
    else if (num == 9)
        cout << "\n  September: Fall" << endl;
    else if (num == 10)
        cout << "\n  October: Fall" << endl;
    else if (num == 11)
        cout << "\n  November: Fall" << endl;
    else if (num == 12)
        cout << "\n  December: Winter" << endl;
    else
        cout << "\n  Invalid input. Please enter a number between 1-12" << endl;

    // Display the closing messages for non Visual Studio IDEs
    cout << "\n\n  Press any key to continue ..." << endl;
    _getch();  // halt processing 

    return 0;  // exit code
}
