/*
    Student Name: Joshua Betancourt
    File Name: M8_Discussion_JoshB.cpp 
    Date: 10/18/2024
    Description: This program is example of using classes that contains errors
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>              // needed for setw 
#include <string>               // needed for string input/input validation
#include <regex>                // needed to use regex for validation

// Initializing Manufacturer Class
class carManufacturer
{
private:
   std::string manufacturerName;
   std::string manufacturerOrigin;
public:
    void setManufacturerName(std::string providedName);
    void setManufacturerOrigin(std::string providedOrigin);
    std::string getManufacturerName();
    std::string getManufacturerOrigin();
    ~carManufacturer();
};

// Defining carManufacturer functions/methods
void carManufacturer::setManufacturerName(std::string providedName)
{
    manufacturerName = providedName;
};
void carManufacturer::setManufacturerOrigin(std::string providedOrigin)
{
    manufacturerOrigin = providedOrigin;
};
std::string carManufacturer::getManufacturerName()
{
    return manufacturerName;
};
std::string carManufacturer::getManufacturerOrigin()
{
    return manufacturerOrigin;
};
carManufacturer::~carManufacturer(){}

// Initializing carModel class
class carModel
{
private:
    std::string name;
    std::string trim;
    std::string transmissionType;
    std::string drivetrain;
    int mileage;
    double age;

public:
    void setCarName(std::string providedName);
    void setCarTrim(std::string providedTrim);
    void setCarTransmissionType(std::string providedTransmissionType);
    void setCarDrivetrain(std::string providedDrivetrain);
    void setCarMileage(int providedMileage);
    void setCarAge(double providedAge);
    std::string getCarName();
    std::string getCarTrim();
    std::string getCarTransmissionType();
    std::string getCarDrivetrain();
    int getCarMileage();
    double getCarAge();
    ~carModel();
};

// Defining carModel functions/methods
void carModel::setCarName(std::string providedName) 
{
    name = providedName;
}
void carModel::setCarTrim(std::string providedTrim)
{
    trim = providedTrim;
}
void carModel::setCarTransmissionType(std::string providedTransmissionType)
{
    transmissionType = providedTransmissionType;
}
void carModel::setCarDrivetrain(std::string providedDrivetrain)
{
    drivetrain = providedDrivetrain;
}
void carModel::setCarMileage(int providedMileage)
{
    mileage = providedMileage;
}
void carModel::setCarAge(double providedAge)
{
    age = providedAge;
}
std::string carModel::getCarName()
{
    return name;
}
std::string carModel::getCarTrim()
{
    return trim;
}
std::string carModel::getCarTransmissionType()
{
    return transmissionType;
}
std::string carModel::getCarDrivetrain()
{
    return drivetrain;
}
int carModel::getCarMileage()
{
    return mileage;
}
double carModel::getCarAge()
{
    return age;
}
carModel::~carModel(){}

// instantiating function used within main function
std::string captureStringInput();

int main()
{
    // creating local variables for program
    std::string providedManufacturerName;
    std::string providedManufacturerOrigin;

    // instantiating classes
    carManufacturer newManufacturer;
    carModel newCarModel;

    // Displaying intro to application.
    std::cout << "\n\n  Let's create a car company together!"
              << "\n\n  All you need to do is provide a name for your company and its country of origin."
              << "\n  I'll provide you with your first car!"
              << std::endl;

    std::cout << "\n  What would you like to name your car company?";
    providedManufacturerName = captureStringInput();
    std::cout << std::endl;

    newManufacturer.setManufacturerName(providedManufacturerName);

    std::cout << "\n  And where will you company be based out of?";
    providedManufacturerOrigin = captureStringInput();
    std::cout << std::endl;

    newManufacturer.setManufacturerOrigin(providedManufacturerOrigin);

    // creating hypothetical car
    newCarModel.setCarName("Fabuloso");
    newCarModel.setCarTrim("XLT");
    newCarModel.setCarTransmissionType("Manual");
    newCarModel.setCarDrivetrain("AWD");
    newCarModel.setCarAge(0.2);
    newCarModel.setCarMileage(40);


    std::cout << "\n  Great!"
              << "\n\n  Lets look at your new car offering!"
              << "\n\n  " << newManufacturer.getManufacturerName() << "'s car will come from " << newManufacturer.getManufacturerOrigin() << "."
              << "\n  The " << newCarModel.getCarName() << " " << newCarModel.getCarTrim() <<" is a " << newCarModel.getCarTransmissionType()
              << " " << newCarModel.getCarDrivetrain() << " Luxury vehicle."
              << "\n  This baby is " << newCarModel.getCarAge() << " years old and only has " << newCarModel.getCarMileage() << " miles!";
    
    
    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

// used to capture string input from user
std::string captureStringInput() {
    std::string updatedInput;
    bool validInput = false;

    // used for regex generation: https://regex101.com/r/FFKEcq/1
    // /^[A-Za-z]+$/gm  <- will only match if string one word without spaces, numbers or special characters

    const std::regex stringRegex("^[A-Za-z]+$"); // used following resource to learn how to use this: https://en.cppreference.com/w/cpp/regex/regex_match

    std::cout << "\n  Please provide a string without spaces, numbers, or special characters: ";
    std::cin >> updatedInput;

    while (!validInput) {
    if (std::regex_match(updatedInput, stringRegex)) {
        validInput = true;
        break;
    } else
        std::cout << "\n  The provided input was not valid. Please try again."
                  << "\n\n  Please ensure the provided string does not have any spaces, numbers or special characters: ";
        std::cin >> updatedInput;
    } 

    return updatedInput;
}

