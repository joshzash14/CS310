/*
    Student Name: Joshua Betancourt
    File Name: M2_Discussion_Solution_Aidan_Jacoby_Project.cpp 
    Date: 09/02/2024
    Description: This program is an edited version of Aidan's discussion post which corrects the build errors that it originally had.
*/


#include <iostream>;
#include <conio.h>; 

using namespace std;

int main()
{
    // creating local variable
    string name;

        cout << "\n\n  Welcome to the Discussion Input/Output App!" << endl;

        cout << "\n  Please Enter Your Name: ";

        cin >> name;

        cout << "\n\n  Your name is " << name << "!" << endl;

        cout << "\n  Thanks for using my program!" << endl;
        cout << "\n\n  Press any key to continue ..." << endl;
        _getch();  // halt processing 

     return 0;
}
