/*
    Student Name: Joshua Betancourt
    File Name: M8_Discussion_JoshB.cpp 
    Date: 10/18/2024
    Description: This program is example of using classes that contains errors
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>
#include <string>

// initializing Manufacturer Class
class Manufacturer
{
private:
   std::string manufacturerName;
   std::string manufacturerOrigin;
public:
    void setManufacturerName(std::string providedName);
    void setManufacturerOrigin(std::string providedOrigin);
    std::string getManufacturerName();
    std::string getManufacturerOrigin();
    ~Manufacturer();
};

void Manufacturer::setManufacturerName(std::string providedName)
{
    manufacturerName = providedName;
};

void Manufacturer::setManufacturerOrigin(std::string providedOrigin)
{
    manufacturerOrigin = providedOrigin;
};

std::string Manufacturer::getManufacturerName()
{
    return manufacturerName;
};

std::string Manufacturer::getManufacturerOrigin()
{
    return manufacturerOrigin;
};

Manufacturer::~Manufacturer(){};

int main()
{
    // creating local variables for program
    bool loopActive = true;
    bool winningTicket;
    char keepPlaying;
    const int NUMBER_OF_ROWS = 5;
    const int NUMBER_OF_COLUMNS = 5;
    int providedWinningNumber;

    // Displaying intro to application.
    std::cout << "\n\n  Lets play the lottery!";
    
    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}
