/*
    Student Name: Joshua Betancourt
    File Name: Ch04Exercise16.cpp
    Date: 09/15/2024
    Description: This program is used to let an author understand the best royalty for publishing their novel based on 3 fictional
        options for publishing royalty's.
    The values that a user enters are:
        - The net price of each copy of novel
        - The estimated number of copies that will be sold
    The program then outputs:
        - the royalties under each royalty 
        - the best royalty the author could choose.
*/

#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Setting the formatting for all number outputs
    cout << fixed << setprecision(2); // for setting the decimal precision
    locale loc(""); // for the thousands separator 
    cout.imbue(loc);

    // creating the local variables for the program
    float novelPrice;
    float royaltyTwoIncome;
    float royaltyThreeIncome;
    float ROYALTY_THREE_RATE_OVER_4000_COPIES_SOLD = 0.14;
    float ROYALTY_THREE_RATE_UNDER_4000_COPIES_SOLD = 0.1;
    float ROYALTY_TWO_RATE = 0.125;
    
    int novelsSold;
    int novelsSoldOver4000;
    int ROYALTY_ONE_INCOME = 25000;

    string bestRoyaltyOption;

    // Displaying the name of the application as well as prompting the user for information.
    // Formatting to support default terminal size readability.
    cout << "\n\n  Welcome, lets find you the best publishing method for your novel!"
         << "\n\n  We have three royalty options to choose from:"
         << "\n    - In the first royalty, you are paid $5,000 upon delivery of the final manuscript" 
         << "\n         and $20,000 when the novel is published."
         << "\n    - In the second royalty, you are paid 12.5% of the net price of the novel for each copy of the novel sold."
         << "\n    - In the third royalty, you are paid 10% of the net price for the first 4,000 copies sold,"
         << "\n         and 14% of the net price for the copies sold over 4,000."
         << "\n\n  Please provide the net price your novel: "; 
    cin >> novelPrice;
    cout << endl;

    cout << "  Please provide the number of copies to expect to be sold: ";
    cin >> novelsSold;
    cout << endl;

    // Calculating the projected income based off 2 publishing royalties that are not fixed
    /*
    In the second royalty, the author is paid 12.5% of the net price of the novel for each copy of the novel sold. 
    In the third royalty, the author is paid 10% of the net price for the first 4,000 copies sold, 
        and 14% of the net price for the copies sold over 4,000. 
    */
    royaltyTwoIncome = novelsSold * (novelPrice * ROYALTY_TWO_RATE);

    if (novelsSold < 4001) {
        royaltyThreeIncome = novelsSold * (novelPrice * ROYALTY_THREE_RATE_UNDER_4000_COPIES_SOLD);
    } else {
        novelsSoldOver4000 = novelsSold - 4000;
        royaltyThreeIncome = (4000 * (novelPrice * ROYALTY_THREE_RATE_UNDER_4000_COPIES_SOLD )) + (novelsSoldOver4000 * (novelPrice * ROYALTY_THREE_RATE_OVER_4000_COPIES_SOLD));
    }
    
    // Determine which publishing royalty is best for the author
    (ROYALTY_ONE_INCOME > royaltyTwoIncome && ROYALTY_ONE_INCOME > royaltyThreeIncome) ? bestRoyaltyOption = "Royalty One" : (
        royaltyTwoIncome > royaltyThreeIncome ? bestRoyaltyOption = "Royalty Two" : bestRoyaltyOption = "Royalty Three"); 

    // Display the results based on the user's inputs.
    cout << "\n  Based on the information you provided these are the projected royalty payouts:"
         << "\n   - Choosing royalty option one will pay out $" << ROYALTY_ONE_INCOME
         << "\n   - Choosing royalty option two will pay out $" << royaltyTwoIncome
         << "\n   - Choosing royalty option three will pay out $" << royaltyThreeIncome
         << "\n\n  Thus, you best publishing option would be choosing " << bestRoyaltyOption << "."
         << endl;

    // Display THE closing messageS for non Visual Studio IDEs
    cout << "\n  Thanks for using my program!" << endl;
    cout << "\n\n  Press any key to continue ..." << endl;

    _getch();  // halt processing 

    return 0;  // exit code
}