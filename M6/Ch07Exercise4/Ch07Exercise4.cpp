
/*
    Student Name: Joshua Betancourt
    File Name: Ch07Exercise4.cpp
    Date: 10/07/2024
    Description: This program is used to remove all vowels from a provided string.
        Input: any string by user

 
Write a program that prompts the user to input a string. 
The program then uses the function substr to remove all the vowels from the string. 
For example, if str = "There", then after removing all the vowels, str = "Thr".
After removing all the vowels, output the string.
Your program must contain a function to remove all the vowels and a function to determine whether a character is a vowel.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // needed for string input/input validation
#include <regex>                // needed to use regex for validation

std::string removeVowels(std::string providedString);
std::string captureStringInput();

int main()
{

    // creating local variables for program
    std::string userInput;
    std::string updatedString;

    // Welcome user to program and then  begin prompting them for needed information
    std::cout << "\n\n  Welcome, let me trim you string of any vowels!" << std::endl;

    // Have user identify if customer is low income earner
    userInput = captureStringInput();
    updatedString = removeVowels(userInput);

    std::cout << "\n  Your updated string without any vowels is: " << updatedString << ".";

    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

// Scrapes vowels from provided string
std::string removeVowels(std::string providedString) {
    std::string formattedString;

    return formattedString;
};

// prompt user to provide a string. Returns string without spaces, numbers or special characters
std::string captureStringInput() {
    std::string updatedInput;
    bool validInput = false;

    // used for regex generation: https://regex101.com/r/FFKEcq/1
    // /^[A-Za-z]+$/gm  <- will only match if string one word without spaces, numbers or special characters

    const std::regex stringRegex("^[A-Za-z]+$"); // used following resource to learn how to use this: https://en.cppreference.com/w/cpp/regex/regex_match

    std::cout << "\n  Please provide string (word) without any spaces, numbers, or special characters: ";
    std::cin >> updatedInput;
    std::cout << std::endl; 

    while (!validInput) {
    if (std::regex_match(updatedInput, stringRegex)) {
        validInput = true;
        break;
    } else
        std::cout << "\n The provided input was not valid. Please try again."
                  << "\n\n  Please ensure your string does not have any spaces, numbers or special characters: ";
        std::cin >> updatedInput;
        std::cout << std::endl; 
    } 

    return updatedInput;
}