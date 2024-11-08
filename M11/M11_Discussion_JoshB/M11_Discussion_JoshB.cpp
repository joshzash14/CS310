/*
    Student Name: Joshua Betancourt
    File Name: M11_Discussion_JoshB.cpp
    Date: 11/08/2024
    Description: This program uses a template class and has errors within it for our weekly discussion post.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // needed for string input
#include <iostream>

// create Item template class
template <class elemType>
class Items
{
    private:
        int maxLength;
        int length;
        Items *itemArray;
    public:
        // instantiating class methods
        void addItem(std::string providedItem);
        void printItems();
        ~Items();
        // constructor
        Items(int arrayLength = 5) : maxLength(arrayLength), length(0)
        {
            itemArray = new elemType[maxLength];
        }
};
// defining class methods
template <class elemType>
void Items<elemType>::addItem(std::string providedItem)
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

    // creating two instances of my class. One using default constructor value
    Items <std::string> colors();
    Items <int> numbers(3);

    // adding items to my classes
    colors.addItem("blue");
    colors.addItem("yellow");
    colors.addItem("silver");
    colors.addItem("orange");
    colors.addItem("pINk");

    numbers.addItem(4);
    numbers.addItem(15);

    // outputting contents of my classes
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


