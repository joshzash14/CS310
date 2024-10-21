// Ch04Exercise16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
    Student Name: Joshua Betancourt
    File Name: Ch04Exercise16.cpp
    Date: 10/20/2024
    Description: This program creates a bankAccount class and displays how it functions through the console.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>              // needed for setw 
#include <string>               // needed for string input/input validation
#include <regex>                // needed to use regex for validation

#include <iostream>

// class 
class bankAccount
{
private:
    std::string accountHolderName, accountType;
    int accountNumber;
    double accountBalance, interestRate;
public:
    // static variable to track number of accounts throughout creating of future bankAccount instances
    static int numberOfAccounts;

    // class constructor
    bankAccount(std::string name = "", std::string type = "", double balance = 0, double rate = 0)
        : accountHolderName(name), accountType(type), accountBalance(balance), interestRate(rate) {
        numberOfAccounts += 1;
        setAccountNumber(numberOfAccounts);
    }

    // starting count for number OfAccounts
    int bankAccount::numberOfAccounts = 0;

    // initiating  get/set class functions
    void setAccountHolderName(std::string name);
    void setAccountNumber(int number);
    void setAccountType(std::string type);
    void setAccountBalance(double balance);
    void setInterestRate(double rate);
    std::string getAccountHolderName();
    int getAccountNumber();
    std::string getAccountType();
    double getAccountBalance();
    double getInterestRate();

    // initiating feature functions
    void reduceAccountBalance();
    void increaseAccountBalance();
    double calculateInterestAccrued(double balance, double interestRate);

    ~bankAccount();
};

// defining bank class functions
void bankAccount::setAccountHolderName(std::string name)
{
    accountHolderName = name;
}
void bankAccount::setAccountNumber(int number)
{
    accountNumber = number;
};
void bankAccount::setAccountType(std::string type)
{
    accountType = type;
};
void bankAccount::setAccountBalance(double balance)
{
    accountBalance = balance;
};
void bankAccount::setInterestRate(double rate)
{
    interestRate = rate;
};
std::string bankAccount::getAccountHolderName()
{
    return accountHolderName;
};
int bankAccount::getAccountNumber()
{
    return accountNumber;
};
std::string bankAccount::getAccountType()
{
    return accountType;
};
double bankAccount::getAccountBalance()
{
    return accountBalance;
};
double bankAccount::getInterestRate()
{
    return interestRate;
};

bankAccount::~bankAccount()
{
}



// still add my utility functions??? for well def program???

// main display
// Also declare an array of 10 components of type bankAccount 
// to process up to 10 customers and write a program to illustrate how to use your class.
int main()
{
    // creating local arrays to hold data used for initial account population
    std::string accountHolderNames[9] = {"Alice", "Bob", "Diana", "Edward", "Fiona", "George", "Hannah", "Isaac", "Julia"};
    std::string accountTypes[9] = {"checking", "savings", "checking", "savings", "checking", "checking", "savings", "savings", "checking"};
    double accountBalances[9] = {1500.25, 3200.00, 4500.75, 1200.50, 300.00, 4899.99, 2500.00, 80.10, 0.00};
    double interestRates[9] = {0.05, 0.03, 0.07, 0.12, 0.01, 0.15, 0.10, 0.04, 0.08};
    bankAccount activeAccounts[10];

    // creating local variables to assist with user account creation
    std::string providedName, providedAccountType;
    double providedStartingBalance, providedStartingInterestRate;
    

    // Displaying intro to application.
    std::cout << "\n\n  Welcome to my program."
              << "\n  Let me help you determine the winner of a 5 person election."
              << std::endl;

    // loop to create class defs??


    // loop through accounts and display some information right?? - maybe allow creation and loop through information existed

     // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;
}


