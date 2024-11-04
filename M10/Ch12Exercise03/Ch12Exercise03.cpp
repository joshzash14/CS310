/*
    Student Name: Joshua Betancourt
    File Name: Ch12Exercise03.cpp
    Date: 11/04/2024
    Description: This program is used to determine the winner of an election (Redo Programming Exercise 7 of Chapter 8 but using dynamic arrays.)
        Inputs: names and votes for user defined number of candidates
        Output: All candidate names, votes for each candidate and their percentage of votes followed by the winner of the election.
    Future optimization: Currently if two or more candidates have the same # of votes there is no logic for determining tie
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>              // needed for setw 
#include <string>               // needed for string input/input validation
#include <regex>                // needed to use regex for validation

std::string captureStringInput();
double calculateTotalFromArray(int arr[], int length);
int capturePositiveNumberInput();
int identifyMax (float arr[], int length);

int main()
{
    std::cout << std::fixed << std::setprecision(2); // for setting the decimal precision
    std::locale loc(""); // for the thousands separator 
    std::cout.imbue(loc);

    // creating local variables for program
    double totalVotes;
    int winnerIndex;
    int numberOfCandidates;

    // Displaying intro to application.
    std::cout << "\n\n  Welcome to my program."
              << "\n  Let me help you determine the winner of an election."
              << "\n  To start, please provide the number of candidates in your election: ";
    std::cin  >> numberOfCandidates;
    std::cout << std::endl;

    // declaring dynamically sized arrays based on user input.
    std::string* candidateArray = new std::string[numberOfCandidates];
    int* votesArray = new int[numberOfCandidates];
    float* percentageArray = new float[numberOfCandidates];

    // gather inputs from user
    for (int i = 0; i < numberOfCandidates; i++)
    {
        candidateArray[i] = captureStringInput();
        votesArray[i] = capturePositiveNumberInput();
    }
    
    totalVotes = calculateTotalFromArray(votesArray, numberOfCandidates);

    // calculate percentages and input into array
    for (int i = 0; i < numberOfCandidates; i++)
    {
        
        percentageArray[i] = (votesArray[i]/totalVotes) * 100;
    }
    
    // find highest percentage and then return index position
    winnerIndex = identifyMax(percentageArray, numberOfCandidates);

    // output all data and then winner of the election is winner
    std::cout << "\n"
              << std::setw(20) << "Name"
              << std::setw(20) << "Votes"
              << std::setw(20) << "Percentage"; 

    for (int i = 0; i < numberOfCandidates; i++)
    {
        std::cout << "\n"
                  << std::setw(20) << candidateArray[i]
                  << std::setw(20) << votesArray[i]
                  << std::setw(20) << percentageArray[i] << "%";
    }
    
    std::cout << "\n\n  The winner of this election is " << candidateArray[winnerIndex];

    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

// prompt user to provide a string. Returns string without spaces, numbers or special characters
std::string captureStringInput() {
    std::string updatedInput;
    bool validInput = false;

    // used for regex generation: https://regex101.com/r/FFKEcq/1
    // /^[A-Za-z]+$/gm  <- will only match if string one word without spaces, numbers or special characters

    const std::regex stringRegex("^[A-Za-z]+$"); // used following resource to learn how to use this: https://en.cppreference.com/w/cpp/regex/regex_match

    std::cout << "\n  Please provide the last name of the candidate without any spaces, numbers, or special characters: ";
    std::cin >> updatedInput;

    while (!validInput) {
    if (std::regex_match(updatedInput, stringRegex)) {
        validInput = true;
        break;
    } else
        std::cout << "\n  The provided input was not valid. Please try again."
                  << "\n\n  Please ensure the name does not have any spaces, numbers or special characters: ";
        std::cin >> updatedInput;
    } 

    return updatedInput;
}

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
            std::cout << "\n  Please provide the number of votes as a positive whole number: ";
            std::cin >> updatedInput;
            if(!updatedInput) {
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

// calculates total of int array of provided length
double calculateTotalFromArray(int arr[], int length) {
    double total = 0;
    for (int i = 0; i < length; i++)
    {
        total += arr[i];
    }
    return total;
}

int identifyMax (float arr[], int length) {
        int maxIndex = 0;
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
};