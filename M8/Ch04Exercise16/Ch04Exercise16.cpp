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

// class creation
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
        accountNumber = numberOfAccounts;
    }


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
    void reduceAccountBalance(double amount);
    void increaseAccountBalance(double amount);
    double calculateYearlyInterestAccrued(double balance, double interestRate);

    ~bankAccount();
};

// starting count for number OfAccounts
int bankAccount::numberOfAccounts = 0;

// defining bank class functions
void bankAccount::setAccountHolderName(std::string name)
{
    accountHolderName = name;
}
void bankAccount::setAccountNumber(int number)
{
    accountNumber = number;
}
void bankAccount::setAccountType(std::string type)
{
    accountType = type;
}
void bankAccount::setAccountBalance(double balance)
{
    accountBalance = balance;
}
void bankAccount::setInterestRate(double rate)
{
    interestRate = rate;
}
std::string bankAccount::getAccountHolderName()
{
    return accountHolderName;
}
int bankAccount::getAccountNumber()
{
    return accountNumber;
}
std::string bankAccount::getAccountType()
{
    return accountType;
}
double bankAccount::getAccountBalance()
{
    return accountBalance;
}
double bankAccount::getInterestRate()
{
    return interestRate;
}
void bankAccount::reduceAccountBalance(double amount)
{
    accountBalance -= amount;
}
void bankAccount::increaseAccountBalance(double amount)
{
    accountBalance += amount;
}
double bankAccount::calculateYearlyInterestAccrued(double balance, double interestRate)
{
    return balance * interestRate;
}

bankAccount::~bankAccount()
{
}



// still add my utility functions??? for well def program???

// main display
// Also declare an array of 10 components of type bankAccount 
// to process up to 10 customers and write a program to illustrate how to use your class.
int main()
{
    std::cout << std::fixed << std::setprecision(2); // for setting the decimal precision
    std::locale loc(""); // for the thousands separator 
    std::cout.imbue(loc);

    // creating local arrays to hold data used for initial account population
    std::string accountHolderNames[10] = {"Alice", "Bob", "Diana", "Edward", "Fiona", "George", "Hannah", "Isaac", "Julia", "Josh"};
    std::string accountTypes[10] = {"Checking", "Savings", "Checking", "Savings", "Checking", "Checking", "Savings", "Savings", "Checking", "Savings"};
    double accountBalances[10] = {1500.25, 3200.00, 4500.75, 1200.50, 300.00, 4899.99, 2500.00, 80.10, 0.00, 50000.00};
    double interestRates[10] = {0.05, 0.03, 0.07, 0.12, 0.01, 0.15, 0.10, 0.04, 0.08, 0.14};
    bankAccount activeAccounts[10];

    // adding accounts to activeAccounts array
    for (int i = 0; i < 10; i++)
    {   
        activeAccounts[i].setAccountHolderName(accountHolderNames[i]);
        activeAccounts[i].setAccountType(accountTypes[i]);
        activeAccounts[i].setAccountBalance(accountBalances[i]);
        activeAccounts[i].setInterestRate(interestRates[i]);
    }

    // introduction to the program and what is does
    std::cout << "\n\n  Welcome to my program."
              << "\n  I'll be outputting 10 bank accounts that were created using a class I made. \n";

    // presenting all the accounts that were created
    std::cout << "\n"
              << std::setw(16) << "Account Number"
              << std::setw(25) << "Account Holder Name"
              << std::setw(16) << "Account Type"
              << std::setw(30) << "Account Balance"
              << std::setw(20) << "Interest Rate"; 

    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n"
                  << std::setw(10) << activeAccounts[i].getAccountNumber()
                  << std::setw(25) << activeAccounts[i].getAccountHolderName()
                  << std::setw(20) << activeAccounts[i].getAccountType()
                  << std::setw(20) << "$" << activeAccounts[i].getAccountBalance()
                  << std::setw(20) << (activeAccounts[i].getInterestRate() * 100) << "%"; // unsure why some of the percentages are not in line. Would love a hint as to what I need to edit
    }

    std::cout << "\n\n  I'll now modify 3 of the accounts balances.";
    // modifying some accounts balances
    activeAccounts[3].increaseAccountBalance(350.21);
    activeAccounts[7].reduceAccountBalance(541.27);
    activeAccounts[9].increaseAccountBalance(7500.00);

    std::cout << "\n\n  Here is the updated account information: \n";

    std::cout << "\n"
              << std::setw(16) << "Account Number"
              << std::setw(25) << "Account Holder Name"
              << std::setw(16) << "Account Type"
              << std::setw(30) << "Account Balance"
              << std::setw(20) << "Interest Rate"; 

    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n"
                  << std::setw(10) << activeAccounts[i].getAccountNumber()
                  << std::setw(25) << activeAccounts[i].getAccountHolderName()
                  << std::setw(20) << activeAccounts[i].getAccountType()
                  << std::setw(20) << "$" << activeAccounts[i].getAccountBalance()
                  << std::setw(20) << (activeAccounts[i].getInterestRate() * 100) << "%"; // unsure why some of the percentages are not in line. Would love a hint as to what I need to edit
    }

    // showing use of interest accrued functionality
    std::cout << "\n\n  Here is how much interest can accrue on Josh's account this year: $" 
              << activeAccounts[9].calculateYearlyInterestAccrued(activeAccounts[9].getAccountBalance(), activeAccounts[9].getInterestRate());

    // loop through accounts and display some information right?? - maybe allow creation and loop through information existed

     // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;
}


