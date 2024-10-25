/*
    Student Name: Joshua Betancourt
    File Name: M9_Discussion_JoshB.cpp
    Date: 10/24/2024
    Description: This program outputs the results of making a fictional car and fictional truck 
    built off a base vehicle class to the console.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout,
#include <iomanip>              // needed for setw 
#include <string>               // needed for string data type

// creating base class
class Vehicle
{
private:
    std::string manufacturer, model;
    int year;

public:

    // class constructor
    Vehicle(std::string man, std::string mod, int yr)
        : manufacturer(man), model(mod), year(yr)
        {
        }

    // initiating  get/set class functions
    void setManufacturer(std::string givenManufacturer);
    void setModel(std::string givenModel);
    void setYear(int givenYear);
    std::string getManufacturer();
    std::string getModel();
    int getYear();
    ~Vehicle();
};

// defining Vehicle class functions
void Vehicle::setManufacturer(std::string givenManufacturer)
{
    manufacturer = givenManufacturer;
}
void Vehicle::setModel(std::string givenModel)
{
    model = givenModel;
}
void Vehicle::setYear(int givenYear)
{
    year = givenYear;
}
std::string Vehicle::getManufacturer()
{
    return manufacturer;
}
std::string Vehicle::getModel()
{
    return model;
}
int Vehicle::getYear()
{
    return year;
}
Vehicle::~Vehicle()
{
}

// creating sports car class
class SportsCar : public Vehicle
{
private:
    int horsepower;
    double zeroToSixtyTime;
public:

    // class constructor
    SportsCar(std::string man, std::string mod, int yr, int power, double zToSixty)
        : Vehicle(man, mod, yr), horsepower(power), zeroToSixtyTime(zToSixty)
        {
        }

    void setHorsepower(int givenPower);
    void setZeroToSixty(double givenTime);
    int getHorsePower();
    double getZeroToSixty();
    ~SportsCar();
};

// defining SportsCar class functions
void SportsCar::setHorsepower(int givenPower)
{
    horsepower = givenPower;
}
void SportsCar::setZeroToSixty(double givenTime)
{
    zeroToSixtyTime = givenTime;
}
int SportsCar::getHorsePower()
{
    return horsepower;
}
double SportsCar::getZeroToSixty()
{
    return zeroToSixtyTime;
}
SportsCar::~SportsCar()
{
}


// creating truck class
class Truck : public Vehicle
{
private:
    int towingCapacity, weight;
public:

    // class constructor
    Truck(std::string man, std::string mod, int yr, int capacity, int wght)
        : Vehicle(man, mod, yr), towingCapacity(capacity), weight(wght)
        {
        }

    void setTowingCapacity(int givencapacity);
    void setWeight(int givenTime);
    int getTowingCapacity();
    int getWeight();
    ~Truck();
};

// defining Truck class functions
void Truck::setTowingCapacity(int givenCapacity)
{
    towingCapacity = givenCapacity;
}
void Truck::setWeight(int givenWeight)
{
    weight = givenWeight;
}
int Truck::getTowingCapacity()
{
    return towingCapacity;
}
int Truck::getWeight()
{
    return weight;
}
Truck::~Truck()
{
}

int main()
{
    // introduction to the program and what is does
    std::cout << "\n\n  Welcome to my program."
              << "\n  We'll be outputting the results of making a fictional car and fictional truck built off a base vehicle class. \n";
    
    // creating car and truck
    SportsCar coolCar("Gibli", "Gobsterer", 2017, 325, 4.2);
    Truck workingTruck("Monster", "Road Mover", 2020, 25000, 8400);

    // outputting vehicle information
    std::cout << "\n  The car created is a " << coolCar.getYear() 
              << " " << coolCar.getManufacturer() 
              << " " << coolCar.getModel() << ". \n  It has " << coolCar.getHorsePower() 
              << " horsepower and goes 0-60 in " << coolCar.getZeroToSixty() << " seconds!"
              << std::endl;
    
    std::cout << "\n  The truck created is a " << workingTruck.getYear() 
           << " " << workingTruck.getManufacturer() 
           << " " << workingTruck.getModel() << ". \n  It has a towing capacity of " << workingTruck.getTowingCapacity() 
           << " lbs and weighs a whopping " << workingTruck.getWeight() << " pounds!"
           << std::endl; 

;
    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;
}

