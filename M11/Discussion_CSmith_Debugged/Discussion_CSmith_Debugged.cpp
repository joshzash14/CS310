/*
    Student Name: Joshua Betancourt
    File Name: Discussion_CSmith_Debugged.cpp 
    Date: 11/08/2024
    Description: This program is the debugged version of this student's code.
                 This program creates a template class that is a simple calculator
*/

#include <iostream>
#include <string>
using namespace std;

// Template class
template <class T>
class Calculator {

private:
  T num1;
  T num2;

public:
    Calculator(T n1, T n2) : num1(n1), num2(n2) {}
    //constructor
      T add() {
        return num1 + num2;
      }
      T subtract() {
        return num1 - num2;
      }
      T multiply() {
        return num1 * num2;
      }
      T divide() {
        if (num2 != 0) //check for dividing by zero
        return num1 / num2;
        else {
          cout << "Error: Division by zero" << endl;
          return 0;
        }
      }
};

int main() {
  
  //get input from user
  double num1, num2;
  cout << "Enter two integers: ";
  cin >> num1 >> num2;
  
  //create an instance of the Calculator class
  Calculator<double> calc(num1, num2);
  
  //perform calculations and display results
  cout << "Addition: " << calc.add() << endl;
  cout << "Subtraction: " << calc.subtract() << endl;
  cout << "Multiplication: " << calc.multiply() << endl;
  cout << "Division: " << calc.divide() << endl;
  
  return 0;
}

