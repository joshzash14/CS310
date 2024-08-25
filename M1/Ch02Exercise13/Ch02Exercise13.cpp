/*
    Student Name: Joshua Betancourt
    File Name: Ch02Exercise13.cpp
    Date: 08/25/2024
    Description: This program is used to calculate the price a store will list an item for as well as the final price of
                 that item after taxes. The user is asked to provide the original price of the item, how much they would
                 like to mark up the item by, and the sales tax rate that should be applied to the item. The mark up and 
                 tax rate are assumed to be entered as follows: 6.25% is entered as 6.25 and then converted as needed for 
                 calculating the outputted figures.
*/

#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    // Setting the output precision for all numbers
    cout << fixed << setprecision(2);

    // creating the local variables for the program
    float finalPrice;
    float providedOriginalPrice;
    float providedMarkUpPercentage;
    float providedSalesTaxRate;
    float markUp;
    float salesTax;
    float storePrice;

    // Displaying the name of the application as well as prompting the user for information.
    cout << "\n\n  Welcome to my Store Pricing App!"
         << "\n  We wll be calculating the list price for an item in our store."
         << "\n  Please provide the original price of the item: "; 
    cin >> providedOriginalPrice;
    cout << endl;

    cout << "  Please provide the mark up percentage you would like to apply: ";
    cin >> providedMarkUpPercentage;
    cout << endl;

    cout << "  Please provide the sales tax rate to apply: ";
    cin >> providedSalesTaxRate;
    cout << endl;

    /* 
        Calculating the following values for the item:
            - mark up on item 
            - price store will list the item for
            - sales tax on the item
            - the final price of the item with tax
    */
    markUp = providedOriginalPrice * (providedMarkUpPercentage / 100);
    storePrice = providedOriginalPrice + markUp;
    salesTax = storePrice * (providedSalesTaxRate / 100);
    finalPrice = storePrice + salesTax;

    // Display the results based on the user's inputs.
    cout << "  Here is the information on your item: " 
         << "\n  Original Price: $" << providedOriginalPrice
         << "\n  Mark Up: " << providedMarkUpPercentage << "%"
         << "\n  Selling Price: $" << storePrice
         << "\n  Sales Tax Rate: " << providedSalesTaxRate << "%"
         << "\n  Sales Tax on item: $" << salesTax
         << "\n  Final Price: $" << finalPrice
         << endl;  

    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

