/*
    Student Name: Joshua Betancourt
    File Name: M11_Discussion_JoshB.cpp
    Date: 11/08/2024
    Description: This program uses a template and has errors within it for our weekly discussion post.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <iomanip>              // needed for setw 
#include <string>               // needed for string input/input validation
#include <regex>                // needed to use regex for validation

#include <iostream>

template <class elemType>
class Items
{
    private:
        int maxLength;
        int length;
        elemType *itemArray;
    public:
        void addItem(elemType providedItem);
        void printItems();
        ~Items();
        Items(int arrayLength = 5) : maxLength(arrayLength), length(0)
        {
            itemArray = new elemType[maxLength];
        }
};
template <class elemType>
void Items<elemType>::addItem(elemType providedItem)
{   
    itemArray[length] = providedItem;
    length++;
}
template <class elemType>
void Items<elemType>::printItems()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << itemArray[i] << " ";   
    }
    
}
template <class elemType>
Items<elemType>::~Items()
{
    delete[] itemArray;
}


int main()
{
    // Displaying intro to application.
    std::cout << "\n\n  Welcome to my program."
              << "\n  I am going to use a template to make a color array and number array"
              << "\n  Once created I will output the items in my array"
              << std::endl;

    Items <std::string> colors;
    Items <int> numbers(3);

    colors.addItem("blue");
    colors.addItem("yellow");
    colors.addItem("silver");
    colors.addItem("orange");
    colors.addItem("pINk");

    numbers.addItem(4);
    numbers.addItem(15);

    std::cout << "\n  The colors I have stored are: ";
    colors.printItems();

    std::cout << "\n  The numbers I have stored are: ";
    numbers.printItems();


    // Display the closing messages for non Visual Studio IDEs
    std::cout << "\n\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}


