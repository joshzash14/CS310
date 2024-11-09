/*
    Student Name: Joshua Betancourt
    File Name: Ch13Exercise17.cpp
    Date: 11/08/2024
    Description: This program uses C++11 Random Number Generator to generate 25 random numbers
                 and them output to the terminal.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout,
#include <random>               // used for random number generation pg. 971 of text

int main()
{
    int ARRAY_LENGTH = 25;

    // Displaying intro to application.
    std::cout << "\n\n  Welcome to my program."
              << "\n\n  In this program I will generate 25 random numbers and output them to the terminal."
              << std::endl;

    // setting up random number generator - from pg.971 of text
    std::random_device rdevice{};
    std::default_random_engine num{ rdevice() };
    std::uniform_int_distribution<unsigned int> randomNum{10, 100};

    // declaring dynamically sized arrays based on user input.
    int* numberArray = new int[25];

    // filling array with randomly generated numbers
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        numberArray[i] = randomNum(num);
    }
    
    // outputting random numbers that were generated
    std::cout << "\n  These are the numbers I have generated: ";
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        std::cout << numberArray[i] << " ";   
    }
    

    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}
