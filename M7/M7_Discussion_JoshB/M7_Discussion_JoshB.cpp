/*
    Student Name: Joshua Betancourt
    File Name: M7_Discussion_JoshB.cpp
    Date: 10/10/2024
    Description: This program is a a simple lottery experience using a 2d array. Currently in a broken state for user to fix.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>

int generateRandomNumber();
int capturePositiveNumberInput();
bool identifyIfWinner(int userNumber, int scratchTicketNumbers[5][5]);

int main()
{
    // creating local variables for program
    bool loopActive = true;
    bool winningTicket;
    char keepPlaying;
    const int NUMBER_OF_ROWS = 5;
    const int NUMBER_OF_COLUMNS = 5;
    int providedWinningNumber;
   
    // providing default values for these arrays to reduce complexity of random number generation
    int winningArray(NUMBER_OF_ROWS) = { 15, 65, 84, 2, 33};
    int scratchTicketNumbers[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS] = ({34, 94, 34, 56, 8}, {6, 48, 7, 32, 8}, {4, 89, 32, 72, 14}, {8, 64, 34, 28, 64}, {6, 18, 5, 87, 22});

    // Displaying intro to application.
    std::cout << "\n\n  Lets play the lottery!"
        << "\n\n  For $20 you get one 5x5 scratcher"
        << "\n  You'll get to submit a number between 1 and 500."
        << "\n  If the sum of any row is equal to your number you win $1,000!";
    std::cout << std::endl;

    // program loop
    do 
    {
        // capturing user input
        providedWinningNumber = capturePositiveNumberInput();

        //outputting scratch ticket number
        std::cout << "\n\n  Your scratch ticket numbers are: ";
        for (int row = 0; row < NUMBER_OF_ROWS; row++)
        {
            std::cout << "\n ";
            for (int column = 0; column < NUMBER_OF_COLUMNS; column++)
            {
                std::cout << " " << scratchTicketNumbers[row][column] << " ";
            }
            
        }
        
        // identifying if user won
        winningTicket = identifyIfWinner(providedWinningNumber, scratchTicketNumbers);

        // informing user of win or loss then prompting for another attempt
        if (winningTicket) {
            std::cout << "\n\n  You won $1,000!!";
        } else {
            std::cout << "\n\n  Sorry you did not win...";
        }

        std::cout << "\n\n  Want to buy another?"
            << "\n  Enter Y to by another. Otherwise provide any other character and press enter to give up: ";
        std::cin >> keepPlaying;
        if (!(keepPlaying == 'Y' || keepPlaying == 'y'))
        {
            loopActive = false;
        }
    } 
    while 
    (
        loopActive
    );
    
    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

// function to identify winner, need to pass scratch ticket array and user inputted number
bool identifyIfWinner(int userNumber, int scratchTicketNumbers[5]) {
    bool winner = false;

    // sum each row and check if any winner
    for (int row = 0; row < 5; row++)
    {
        int sum = 0;
        for (int column = 0; column < 5; column++)
        {
            sum = sum + scratchTicketNumbers(row)(column);
    }

    if (sum == userNumber) {
        winner = true;
    }
}

return winner;
};

// function ensuring user input is a positive number
int capturePositiveNumberInput() {
    int updatedInput = 0;
    bool validInput = false;

    // modified version of what is found on pg 1021 of our book
    char str[] = "error";
    do
    {
        try
        {
            std::cout << "\n  Please provide a whole number between 1 and 500: ";
            std::cin >> updatedInput;
            if(!updatedInput || (updatedInput < 1) || (updatedInput > 500)) {
                throw str;
            }
            validInput = true;

        }
        catch(const char messageStr[])
        {
            std::cout << "\n  The provided input was not valid. Please try again.";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        
    } while (!validInput);
    
    return updatedInput;
}
