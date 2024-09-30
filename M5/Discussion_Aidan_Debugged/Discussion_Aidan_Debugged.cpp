/*
    Student Name: Joshua Betancourt
    File Name: Discussion_Aidan_Debugged.cpp
    Date: 09/30/2024
    Description: This program is an updated version of Aidan's discussion submission which corrects the errors that it had.
*/
#include <iostream>

using namespace std;

int add(double valueOne, float valueTwo);
int subtract(double valueOne, float valueTwo);

int main()
{
	// creating variables for program
	double valueOne;
	float valueTwo;

	// Intro to program and prompting user for inputs
	cout << "\n\n  Welcome to my program. We will add the two numbers and then subtract the second number from the first!"
     	 << "\n  ** Note all numbers that you provide should be whole numbers **"
     	 << "\n  Please provide the first number: ";
	cin >> valueOne;
	cout << endl;

	cout << "  Please provide the second number: ";
	cin >> valueTwo;
	cout << endl;

	int sum = add(valueOne, valueTwo);
	int diff = subtract(valueOne, valueTwo);


	cout << "\n  The sum of these two numbers is: "<< sum;
	cout << "\n  After subtracting the second number from the first number we are at: " << diff;

	// Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;
}

// functions used within main
int add(double valueOne, float valueTwo)
{
	float sum = valueOne + valueTwo;
	return sum;
}

int subtract(double valueOne, float valueTwo)
{
	float diff = valueOne - valueTwo;
	return diff;
}