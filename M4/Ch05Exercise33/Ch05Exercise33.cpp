/*
    Student Name: Joshua Betancourt
    File Name: Ch05Exercise33.cpp
    Date: 09/22/2024
    Description: This program is used to help determine how many dishes can be prepared when the user provides:
        - The time it takes for the first dish to complete
        - The time it takes for all the following dishes to complete
        - The total time available to complete the dishes 
    *** All inputs provided in minutes ***
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{

    // creating the local variables for the program
    int firstDishTime;
    int numberOfDishes = 0;
    int secondDishTime;
    int timePerDish = 0;
    int totalTimeAvailable;

    // Displaying the name of the application as well as prompting the user for information.
    // Formatting to support default terminal size readability.
    cout << "\n\n  Welcome, lets find out how many dishes we can complete today."
         << "\n  ** Note all information you provide should be in whole minutes **"
         << "\n  Please provide the time it takes to complete the first dish: ";
    cin >> firstDishTime;
    cout << endl;

    cout << "  Please provide the time it takes to complete the second dish: ";
    cin >> secondDishTime;
    cout << endl;

    cout << "  Lastly, provide the total amount of time you have to prepare your dishes: ";
    cin >> totalTimeAvailable;
    cout << endl;

    // Calculating the number of dishes which can be completed
    if ((totalTimeAvailable - firstDishTime) > 0) {
        totalTimeAvailable -= firstDishTime;
        timePerDish += firstDishTime;
        numberOfDishes ++;
        while ((totalTimeAvailable - timePerDish) > 0)
        {
            timePerDish += secondDishTime;
            totalTimeAvailable -= timePerDish;
            numberOfDishes ++;
        }

        // Display the results based on the user's inputs.
        cout << "  Based on the information you provided you will be able to complete " 
         << numberOfDishes 
         << " dishes."
         << endl;

    } else {
        cout << "  Based on the information you provided you not have enough time to complete any dishes." 
        << endl;
    }

    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}