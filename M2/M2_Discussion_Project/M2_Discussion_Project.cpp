/*
    Student Name: Joshua Betancourt
    File Name: M2_Discussion_Project.cpp
    Date: 09/02/2024
    Description: This program is used convert dog years to human years so you can tell if your little Doggo is older than you!
*/

#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    // creating the local variables for the program
    int dogAge;
    int humanAge;

    // Displaying the name of the application as well as prompting the user for information.
    cout << "\n\n  Welcome to the Doggo Year Converter!!!"
         << "\n  Have you ever wondered if your Doggo was older than you??!!!!";
         << "\n  Enter the age of your Doggo in years: "; 

    cin >> dogAge;
    cout << endl;

    Sleep(750);
    cout << "  Did you know that although slightly outdated that most people believe that 1 dog year is equal to 7 human years?\n"
         << "  That's what we are using for our conversion today!\n";
    cout << endl;

    humanAge = dogAge * 7;
    Sleep(1250);

    cout << "  Your dog is " << humanAge << " in human years! ";
    cout << endl;

    Sleep(750);
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return;  // exit code
}


