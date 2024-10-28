/*
    Student Name: Joshua Betancourt
    File Name: Ch11Exercise13.cpp
    Date: 10/20/2024
    Description: This program creates a bankAccount class and then creates a checking and saving account class that is built
                 upon the base bankAccount class. In the main function it then creates and instance of both the checking and
                 savings account classes and does some data manipulation using those instances.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // needed for string

#include <iostream>

// bank account class creation
class bankAccount
{
private:
    int accountNumber;
    double accountBalance;
public:
    // class constructor
    bankAccount(int acctNum, double balance)
        : accountNumber(acctNum), accountBalance(balance) {
    }


    // initiating  get/set class functions
    void setAccountNumber(int number);
    void setAccountBalance(double balance);
    int getAccountNumber();
    double getAccountBalance();

    // initiating feature functions
    void withdrawMoney(double amount);
    void depositMoney(double amount);
    void printAccountInformation();
    ~bankAccount();
};

// defining bank class functions
void bankAccount::setAccountNumber(int number)
{
    accountNumber = number;
}
void bankAccount::setAccountBalance(double balance)
{
    accountBalance = balance;
}
int bankAccount::getAccountNumber()
{
    return accountNumber;
}
double bankAccount::getAccountBalance()
{
    return accountBalance;
}
void bankAccount::withdrawMoney(double amount)
{
    accountBalance -= amount;
}
void bankAccount::depositMoney(double amount)
{
    accountBalance += amount;
}
void bankAccount::printAccountInformation()
{
    std::cout << "\n  Account " << accountNumber 
              << " currently has a balance of " << accountBalance
              << std::endl;
}
bankAccount::~bankAccount()
{
}

class checkingAccount : public bankAccount
{
private:
    double interestRate, minimumBalance, serviceCharge;
public:

    // class constructor
    checkingAccount(int acctNum, double balance, double rate, double minBal, double servChar)
        : bankAccount(acctNum, balance), interestRate(rate), minimumBalance(minBal), serviceCharge(servChar) 
        {
        }

    // initiating  get/set class functions
    void setInterestRate(double rate);
    void setMinimumBalance(double balance);
    void setServiceCharge(double charge);
    double getInterestRate();
    double getMinimumBalance();
    double getServiceCharge();

    // initiating feature functions
    double calculateYearlyInterestAccrued(double balance, double interestRate);
    void postInterest();
    bool balanceBelowMinimum();
    void writeCheck(std::string recipientName, int recipientAccountNumber, int checkAmount);
    void withdrawMoney(double withdrawalAmount);
    void applyServiceCharge();
    void printAccountInformation();

    ~checkingAccount();
};

// defining class functions
void checkingAccount::setMinimumBalance(double bal)
{
    minimumBalance = bal;
}
void checkingAccount::setServiceCharge(double charge)
{
    serviceCharge = charge;
}
void checkingAccount::setInterestRate(double rate)
{
    interestRate = rate;
}
double checkingAccount::getMinimumBalance()
{
    return minimumBalance;
}
double checkingAccount::getServiceCharge()
{
    return serviceCharge;
}
double checkingAccount::getInterestRate()
{
    return interestRate;
}
double checkingAccount::calculateYearlyInterestAccrued(double balance, double interestRate)
{
    return balance * interestRate;
}
void checkingAccount::postInterest()
{
    double currentBalance = getAccountBalance();
    double interest = calculateYearlyInterestAccrued(currentBalance, interestRate);
    currentBalance += interest;
    setAccountBalance(currentBalance);
}
bool checkingAccount::balanceBelowMinimum()
{
    bool belowMin = false;
    if (getAccountBalance() < minimumBalance) {
        belowMin = true;
    }
    return belowMin;
};
void checkingAccount::writeCheck(std::string recipientName, int recipientAccountNumber, int checkAmount)
{   
    double currentBalance = getAccountBalance();
    currentBalance -= checkAmount;
    setAccountBalance(currentBalance);
    std::cout << "\n  A check has been created for " << recipientName 
              << " for the account number " << recipientAccountNumber 
              << " in the amount of $" << checkAmount
              << ".\n  Your balance after this check is $" << currentBalance << "."
              << std::endl;
};
void checkingAccount::withdrawMoney(double withdrawalAmount)
{
    double currentBalance = getAccountBalance();
    currentBalance -= withdrawalAmount;
    setAccountBalance(currentBalance);
};
void checkingAccount::applyServiceCharge()
{
    bool applyCharge = balanceBelowMinimum();
    if (applyCharge) {
        double currentBalance = getAccountBalance();
        currentBalance -= serviceCharge;
        setAccountBalance(currentBalance);
    }   

}
void checkingAccount::printAccountInformation()
{
    std::cout << "\n  Checking Account " << getAccountNumber() 
              << " currently has a balance of $" << getAccountBalance()
              << ". \n  This account must have a minimum balance of $" << minimumBalance
              << " otherwise it is subject to a service fee of $" << serviceCharge
              << ". \n  Money is this account has a yearly interest rate of " << interestRate * 100
              << "% applied to the balance on hand."
              << std::endl;
}
checkingAccount::~checkingAccount()
{
}


// defining savings account class
class savingsAccount : public bankAccount
{
private:
    double interestRate, minimumBalance, serviceCharge;
public:

    // class constructor
    savingsAccount(int acctNum, double balance, double rate)
        : bankAccount(acctNum, balance), interestRate(rate) 
        {
        }


    // initiating  get/set class functions
    void setInterestRate(double rate);
    double getInterestRate();

    // initiating feature functions
    double calculateYearlyInterestAccrued(double balance, double interestRate);
    void postInterest();
    void withdrawMoney(double withdrawalAmount);
    void printAccountInformation();
    ~savingsAccount();
};

// defining class functions
void savingsAccount::setInterestRate(double rate)
{
    interestRate = rate;
}
double savingsAccount::getInterestRate()
{
    return interestRate;
}
double savingsAccount::calculateYearlyInterestAccrued(double balance, double interestRate)
{
    return balance * interestRate;
}
void savingsAccount::postInterest()
{
    double currentBalance = getAccountBalance();
    double interest = calculateYearlyInterestAccrued(currentBalance, interestRate);
    currentBalance += interest;
    setAccountBalance(currentBalance);
}
void savingsAccount::withdrawMoney(double withdrawalAmount)
{
    double currentBalance = getAccountBalance();
    currentBalance -= withdrawalAmount;
    setAccountBalance(currentBalance);
};
void savingsAccount::printAccountInformation()
{
    std::cout << "\n  Savings Account " << getAccountNumber() 
              << " currently has a balance of $" << getAccountBalance()
              << ". \n  Money is this account has a yearly interest rate of " << interestRate * 100
              << "% applied to the balance on hand."
              << std::endl;
}
savingsAccount::~savingsAccount()
{
}


int main()
{
    // creating savings and checking accounts using appropriate classes
    checkingAccount myChecking(355694004, 5075, 0.02, 500, 35.25);
    savingsAccount mySavings(355474647, 5075, 0.05);

    // introduction to the program and what is does
    std::cout << "\n\n  Welcome to my program."
              << "\n  I'll be outputting information about a savings and checking account that I have created \n";

    myChecking.printAccountInformation();
    mySavings.printAccountInformation();

    std::cout << "\n\n  I'll now make edits to each of the accounts."
              << "\n  Starting with the savings account we are going to add a deposit of $5000"
              << "\n  and the add the yearly interest accrued to the account."
              << std::endl;
    
    mySavings.depositMoney(5000);
    mySavings.postInterest();

    std::cout << "\n  The following is the updated account information." << std::endl;
    mySavings.printAccountInformation();

    std::cout << "\n  For the checking account we will write a check for $4800"
              << "\n  and then check see that a service charge is then applied "
              << "\n  to the account due to being under the minimum balance."
              << std::endl;

    myChecking.writeCheck("David", 654987311, 4800);
    myChecking.applyServiceCharge();
    
    std::cout << "\n  The following is the updated account information. \n" << std::endl;
    myChecking.printAccountInformation();

    
    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;
}



