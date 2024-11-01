// M10_Discussion_JoshB.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
    Student Name: Joshua Betancourt
    File Name: M10_Discussion_JoshB.cpp
    Date: 10/31/2024
    Description: This program is using pointers and contains errors needing to be debugged.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // needed for string

struct carType 
{
    std::string make;
    std::string model;
    std::string color;
    int year;
    int mileage;
};

int main()
{
    // introduction to the program and what is does
    std::cout << "\n\n  Welcome to my program."
              << "\n  I'll be outputting information about a car struct I've made using a pointer. \n";

    carType* fancyCar = new carType;

    (*fancyCar).make = "uber fance";
    (*fancyCar).model = "fancy pants";
    (*fancyCar).color = "orange";
    (*fancyCar).year = 2026;
    (*fancyCar).mileage = 26;


    std::cout << "\n  Let's look at my car!"
              << "\n  I have here a " << (*fancyCar).year
              << " " << (*fancyCar).make << " " << (*fancyCar).model
              << "\n  This puppy is brand new and only has " <<  (*fancyCar).mileage 
              << " miles!";

    delete fancyCar;

    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;
}


