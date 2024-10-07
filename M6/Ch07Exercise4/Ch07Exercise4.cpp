
/*
    Student Name: Joshua Betancourt
    File Name: Ch07Exercise4.cpp
    Date: 10/07/2024
    Description: This program is used to calculate a customer's service consulting charge based on the provided information.
        Inputs: If customer is low income
                How many minutes of consulting where provided
                The consultant's hourly rate
 
Write a program that prompts the user to input a string. 
The program then uses the function substr to remove all the vowels from the string. 
For example, if str = "There", then after removing all the vowels, str = "Thr".
After removing all the vowels, output the string.
Your program must contain a function to remove all the vowels and a function to determine whether a character is a vowel.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // needed for string input/input validation

float calculateBillingAmount(float hourlyRate, int consultingTime, bool lowIncome);
std::string captureStringInput();

int main()
{

    // creating local variables for program
    float hourlyRate;
    int consultingTime;
    float consultingFee;
    bool lowIncome = false;

    std::string userInput;

    // Welcome user to program and then  begin prompting them for needed information
    std::cout << "\n\n  Welcome, let me trim you string of any vowels!" << std::endl;

    // Have user identify if customer is low income earner
    userInput = captureStringInput();

    std::cout << "\n  Please provide the consulting time provided today in whole minutes: ";
    std::cin >> consultingTime;
    std::cout << std::endl;

    std::cout << "\n  Please provide your hourly rate: ";
    std::cin >> hourlyRate;
    std::cout << std::endl;

    consultingFee = calculateBillingAmount(hourlyRate, consultingTime, lowIncome);

    std::cout << "\n  The charge for today's service is: $" << consultingFee << ".";

    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

float calculateBillingAmount (float hourlyRate, int consultingTime, bool lowIncome) {
    // setting fee to zero as there are only two scenario's in which the fee is not zero
    float consultingFee = 0.00;

    // calculating consultingFee if service falls within one of two boundaries
    if (lowIncome && (consultingTime > 30)) {
        float chargedTime = consultingTime - 30;
        consultingFee = (hourlyRate * 0.40) * (chargedTime / 60);
    } else if (!lowIncome && consultingTime > 20) {
        float chargedTime = consultingTime - 20;
        consultingFee = (hourlyRate * 0.70) * (chargedTime / 60); 
    }

    return consultingFee;
};

// prompt user to identify if customer is a low income earner and convert input to boolean
std::string captureStringInput() {
    std::string updatedInput;
    bool validInput = false;

    std::cout << "\n  Please provide string (word) without any spaces, numbers, or special characters: ";
    std::cin >> updatedInput;
    std::cout << std::endl; 

    while (!validInput) {
        updatedInput.
    if (updatedInput == "y" || updatedInput == "Y") {
        validInput = true;
        lowIncomeBoolean = true;
        break;
    } else if (updatedInput == "n" || updatedInput == "N") {
        validInput = true;
        break;
    } else
        std::cout << "\n The provided input was not valid. Please try again."
                  << "\n\n  Please indicate if the customer is a low income earner: "
                  << "\n    (Y) If earned income for this year is at or under $25,000"
                  << "\n    (N) If earned income for this year is at or above $25,001"
                  << "\n  Answer: ";
        std::cin >> updatedInput;
        std::cout << std::endl; 
    } 

    return validInput;
}