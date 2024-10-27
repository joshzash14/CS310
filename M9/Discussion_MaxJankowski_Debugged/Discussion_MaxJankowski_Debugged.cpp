/*
    Student Name: Joshua Betancourt
    File Name: Discussion_MaxJankowski_Debugged.cpp
    Date: 10/24/2024
    Description: Debugged solution for discussion
*/

#include <iostream>
#include <cmath>  
using namespace std;

//defining Pi here, because for some reason my laptop compiler didn't want to proceed.
//the CLion compiler worked just fine, not sure why. So i didn't include in one of the errors 
#define M_PI 3.14159265358979323846 

//For the conversion of cu ft to liters
const double CUBIC_FEET_TO_LITERS = 28.32;  

class cylinderType {  //class to store cylinder dimensions and calculate surface area and volume
protected:
    double radius;
    double height;

public:
    cylinderType(double r = 0.0, double h = 0.0) { //constructor initilizing the radias and height of the cylinder
        radius = r;
        height = h;
    }

    void setDim(double r, double h) { //function to set the dimensions of the cylinder
        radius = r;
        height = h;
    }

    
    double volume() const {         //Function for volume calculation
        return M_PI * radius * height;
    }

    double surfaceArea() const {        //determing surface area for painting
        return 2 * M_PI * radius * (radius + height);
    }
};

class containerCost : public cylinderType {  //a derived class to figure out shipping 
private:
    double shipCostPerL;
    double paintCostPerSqFoot;

public:
    //constructor to initilize dimensions and cost to ship and paint
    containerCost(double r, double h, double shippingCost, double paintCost)
        : cylinderType(r, h) {  //a call to parent class
        shipCostPerL = shippingCost;
        paintCostPerSqFoot = paintCost;
    }
        //function to determine shipping bases on volume
    double calcShipCost() const {
        double volumeInLiters = volume() * CUBIC_FEET_TO_LITERS;  //volume to liters conversion
        return volumeInLiters / shipCostPerL;  //retrning cost
    }

   //function to find cost to paint cylinder based on area and cost input per
    double calcPaintCost() const {
        double area = surfaceArea();
        return area * paintCostPerSqFoot;
    }
};

int main() {   //this is pretty much boiler plate main function to get input form user and provide output from returns 
    double radius, height, shipCostPerLiter, paintCostPerSqFoot;

    cout << "What is the radius of the base: " << endl;
    cin >> radius;

    cout << "What is the height of the container in feet: " << endl;
    cin >> height;

    cout << "Estimated shipping cost per liter: " << endl;
    cin >> shipCostPerLiter;

    cout << "What is the paint cost per square foot: " << endl;
    cin >> paintCostPerSqFoot;

    containerCost container(radius, height, shipCostPerLiter, paintCostPerSqFoot);
    //creats an 'object' of container cost with input dimensions
    
    cout << "Shipping cost: $" << container.calcShipCost() << endl;

    cout << "Painting cost: $" << container.calcPaintCost() << endl;

    return 0;
}