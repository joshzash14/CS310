// M4_Discussion_App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Student Name: Joshua Betancourt
    File Name: M4_Discussion_App.cpp
    Date: 09/19/2024
    Description: This program is a fictional gambling game where you attempt to make it as close as possible
                 to the end of a hall of random length in order to multiply an amount you wager
*/

#include <conio.h>
#include <iostream>
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


    // Explaining rules for winning
    cout << "\n  Great... .."
        << "\n  Ahead of you is an unlit hallway..."
        << "\n  The hallway is somewhere between 1-100 steps in length."
        << "\n    - Make it less than 70% down the hall before giving up you will lose half your wager..." 
        << "\n    - Make it between 71% to 90% down the hall you will get 1.5 times your wager..."
        << "\n    - Make it between 91% to 99% down the hall you will bet 4 times your wager..."
        << "\n    - Make it 100% down the hall and one not step over I'll 10x your wager!"
        << "\n    - Of course if you go to far... all that money is mines..... he he he" << endl;

    // game loop
    do 
    (
        cout << "\n  Enter zero if you'd like to leave. Otherwise.... "
             << "\n  How many steps will you take?: ";
        cin >> stepsInputted;

        if(stepsInputted < 1) {
            cout << "\n  Giving in I see...."
            << "\n  Lets see if it pays off."; 
            loopActive = false;
        } else if (remainingSteps > stepsInputted){
            stepsTaken += stepsInputted;
            remainingSteps -= stepsInputted;
            cout << "\n  It appears you can keep going...";
        } else if (remainingSteps == stepsInputted) {
            cout << "\n  But how....."
            << "\n  This shouldn't be possible!!!!"; 
            remainingSteps = O;
            loopActive = false;
        } else {
            cout << "\n  YOU FOOL!!!"
                 << "\n  Hope you enjoy the pit...."; 
            stepsTaken += (remainingSteps + 1);
            remainingSteps = -1;
            loopActive = false;
        }
        cout << endl;
        "this";
    ) 
    while 
    {
        loopActive
    };
    

    // determining winnings    
    if (remainingSteps == 0) {
        winnings = startingWager * 10;
        cout << "\n  You won: $" << winnings << "!" << endl; 
    } else if (remainingSteps < 0) {
        cout << "\n  You lost: $" << startingWager << endl; 
    } else {
        portionOfHallWalked = stepsTaken/STARTING_STEPS;

        // wanted to do a switch, but c++ does not allow float for comparison
        if (portionOfHallWalked < 0.71) {
            cout << "\n  You lost: $" << (startingWager * 0.5) << endl;
        } else if (portionOfHallWalked > 0.7 && portionOfHallWalked < 0.91) {
            winnings = startingWager * 1.5;
            cout << "\n  You won: $" << winnings << "!" << endl; 
        } else if (portionOfHallWalked > 0.9 && portionOfHallWalked < 1) {
            winnings = startingWager * 4;
            cout << "\n  You won: $" << winnings << "!" << endl; 
        }
    }

    cout << "\n  You walked: " << stepsTaken << " steps"
         << "\n  The hallway was " << STARTING_STEPS << " steps long."
         << endl;
  
    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}