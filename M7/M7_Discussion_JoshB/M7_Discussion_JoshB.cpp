/*
    Student Name: Joshua Betancourt
    File Name: M7_Discussion_JoshB.cpp
    Date: 10/10/2024
    Description: This program is a
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <regex>                // needed to use regex for validation


#include <iomanip>

#include <cstdlib>  // library to help with random number generation found at https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/


using namespace std;

int main()
{

    // Setting the formatting for all number outputs
    cout << fixed << setprecision(2); // for setting the decimal precision
    locale loc(""); // for the thousands separator 
    cout.imbue(loc);
   
    // used to create seed/starting point for random number generator (rand() function call later in code)
    srand(time(0)); 

    // setting number of steps before losing
    float STARTING_STEPS = rand() % 100 + 1;

    // creating local variables for program
    bool loopActive;

    float portionOfHallWalked;
    float stepsTaken = 0;

    int remainingSteps = STARTING_STEPS;
    int startingWager;
    int stepsInputted;
    int winnings;

    // Displaying intro to application and prompting user for input.
    cout << "\n\n  Lets play a game...."
        << "\n\n  You'll be given a chance to 10x a wager..."
        << "\n  I'll let you know the rules once you provide the wager"
        << "\n\n  How much would you like to wager?: ";
    cin >> startingWager;
    cout << endl;

    // game loop
    do 
    (
        cout << "\n  Enter zero if you'd like to leave. Otherwise.... "
             << "\n  How many steps will you take?: ";
        cin >> stepsInputted;

    ) 
    while 
    (
        loopActive
    );
    

    // determining winnings    
   
  
    // Display the closing messages for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}