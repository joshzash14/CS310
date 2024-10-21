/*
    Student Name: Joshua Betancourt
    File Name: Discussion_Maksymilian_Debugged.cpp
    Date: 10/20/2024
    Description: This program is the debugged version of the original file
*/

#include <iostream>
using namespace std;

class swimmingPool {  //creating the required class
private:
    double length, width, depth;  // declaring variables for pool dimension 
    double fillingRate, drainingRate;  // variables for draining and filling 
    double currentWater;    //variable for how much water is in the pool

    
    double volume() const {  // function to calculate pool volume in gallons
        return length * width * depth * 7.48; //calculation comes from the fact that one cubic ft holds 
    }

public:
    // constructor to initialize the pool properties
    swimmingPool(double l = 0, double w = 0, double d = 0, double fr = 0, double dr = 0, double cw = 0) 
        : length(l), width(w), depth(d), fillingRate(fr), drainingRate(dr), currentWater(cw){}

    // function for filling the pool for a given time in minutes
    void fill(double time) {
        currentWater += fillingRate * time; 
        
        if (currentWater > volume()) 
            currentWater = volume();
       
        cout << "Filled for " << time << " minutes. Current water: " << currentWater << " gallons.\n";
    }

    // function for draining water of the pool for a specfic ammount of minutes
    void drain(double time) {
        currentWater -= drainingRate * time;
       
        if (currentWater < 0) 
            currentWater = 0;
        
        cout << "Drained for " << time << " minutes. Current water:" << currentWater << " gallons.\n";
    }

    double waterNeeded() const {  // calculating how much wate ris needed to fill the pool
        return volume() - currentWater; 
    }
    
    double toFill() const { // calculating how mch time is needed to fill pool
        return waterNeeded() / fillingRate;
    }
    
    double toDrain() const { // calculate time needed to completely drain the pool
        return currentWater / drainingRate;
    }

    
    void display() const {  //the current fill status f pool
        cout << "Pool size: " << length << " x " << width << "x " << depth << " feet\n";
        cout << "Current water level: " << currentWater << " gallons\n";
        cout << "Pool limit: " << volume() << " gallons \n";
        cout << "Fill rate:  " << fillingRate << " gallons/min, Drain rate: " << drainingRate << " gallons/min\n";
    }
};

int main() {
    
    swimmingPool pool(45, 25, 8, 40, 26, 450); // creating a instance of class swimmingPool
    
    pool.display(); // pool status

    
    pool.fill(50); // filling pool for 50 min

   
    pool.drain(30); // draining pool for 30min

    // output the time to completely fill the pool
    cout << "Time to completely fill the pool:   " << pool.toFill() << " minutes.\n";

    // out put for time to drain
    cout << "Time to completely drain the pool:   " << pool.toDrain() << " minutes.\n";

    return 0;
}