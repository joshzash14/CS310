/*
    Student Name: Joshua Betancourt
    File Name: Ch03Exercise7.cpp
    Date: 09/04/2024
    Description: This program is used to calculate the interest on a credit card. It has a user input 5 values to execute the calculation.
    The values that a user enters are:
        - The balance shown in the bill
        - The payment made to the card
         -The number of days in the billing cycle
        - The number of days payment is made before the billing cycle is complete
        - Interest rate on the card

    netBalance: the balance shown in the bill
    payment: the payment made
    d1: the number of days in the billing cycle
    d2:the number of days payment is made before the billing cycle
    interest rate
*/

#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    // Setting the formatting for all number outputs
    cout << fixed << setprecision(2); // for setting the decimal precision
    locale loc(""); // for the thousands separator 
    cout.imbue(loc);

    // creating the local variables for the program
    float averageDailyBalance;
    int daysInCycle;
    int daysPaymentMadeBeforeDueDate;
    float interestAccrued;
    float interestRate;
    float netBalance;
    float payment;

    // Displaying the name of the application as well as prompting the user for information.
    cout << "\n\n  Welcome to my Interest Calculator!"
         << "\n  We wll be calculating the accrued interest on you credit card."
         << "\n  Please provide the net Balance on your card: "; 
    cin >> netBalance;
    cout << endl;

    cout << "  Please provide the payment you are making to the card: ";
    cin >> payment;
    cout << endl;

    cout << "  Please provide the number of days in your billing cycle: ";
    cin >> daysInCycle;
    cout << endl;

    cout << "  Please provide the number of days before the cycle completes that you plan to make a payment: ";
    cin >> daysPaymentMadeBeforeDueDate;
    cout << endl;

    cout << "  Please provide the interest rate on you card: ";
    cin >> daysInCycle;
    cout << endl;

    // Calculating the interest accrued based on the users inputs
    averageDailyBalance = (netBalance * daysInCycle - payment * daysPaymentMadeBeforeDueDate) / daysInCycle;
    interestAccrued = averageDailyBalance * 0.0152;

    // Display the results based on the user's inputs.
    cout << "  Based on the information you provided the interest you accrued is $" << interestAccrued << "." << endl;

    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}