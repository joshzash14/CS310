
/*
    Student Name: Joshua Betancourt
    File Name: Ch06Exercise14.cpp.cpp
    Date: 09/30/2024
    Description: This program is used to

    During the tax season, every Friday, the J&J accounting firm provides assistance to people who prepare their own tax returns. 
    Their charges are as follows:
    If a person has low income (<= 25,000) and the consulting time is less than or equal to 30 minutes, there are no charges; 
    otherwise, the service charges are 40% of the regular hourly rate for the time over 30 minutes.
    
    For others, if the consulting time is less than or equal to 20 minutes, there are no service charges; 
    otherwise, service charges are 70% of the regular hourly rate for the time over 20 minutes.
    
    (For example, suppose that a person has low income and spent 1 hour and 15 minutes, 
    and the hourly rate is $70.00. Then the billing amount is 70.00 x 40 x (45/60) = $21.00.)
    Write a program that prompts the user to enter the hourly rate, the total consulting time, 
    and whether the person has low income. 
    
    The program should output the billing amount. 
    
    Your program must contain a function that takes as input the hourly rate, 
    the total consulting time, 
    and a value indicating whether the person has low income. 
    The function should return the billing amount. 
    
    Your program may prompt the user to enter the consulting time in minutes.
*/

#include <conio.h>
#include <iostream>
using namespace std;


float calculateBillingAmount (float hourlyRate, int consultingTime, char lowIncome);

int main()
{
    // creating local variables for program
    float hourlyRate;
    int consultingTime;
    char lowIncome;
    float consultingFee;

    // Welcome user to program and then  begin prompting them for needed information
    cout << "\n\n  Welcome, let us calculate the cost to file this customer's return!" << endl;

    cout << "\n  Please indicate if the customer is a low income earner: "
         << "\n    (Y) If earned income for this year is at or under $25,000"
         << "\n    (N) If earned income for this year is at or above $25,001"
         << "\n  Answer: ";
    cin >> lowIncome;
    cout << endl; 

    cout << "\n  Please provide the consulting time provided today in whole minutes: ";
    cin >> consultingTime;
    cout << endl;

    cout << "\n  Please provide your hourly rate: ";
    cin >> hourlyRate;
    cout << endl;

    consultingFee = calculateBillingAmount(hourlyRate, consultingTime, lowIncome);

    cout << "\n  The charge for today's service is: $" << consultingFee << ".";


    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}


float calculateBillingAmount (float hourlyRate, int consultingTime, char lowIncome) {
    float consultingFee = 0.00;

    if (lowIncome && (consultingTime > 30)) {
        cout << "in cacle";
        int chargedTime = consultingTime - 30;
        consultingFee = (hourlyRate * 0.40) * (chargedTime / 60);
    } else if (!lowIncome && consultingTime > 20) {
        int chargedTime = consultingTime - 20;
        consultingFee = (hourlyRate * 0.70) * (chargedTime / 60); 
    }

    return consultingFee;
};