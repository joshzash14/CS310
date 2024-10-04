/*
    Student Name: Joshua Betancourt
    File Name: M6_Discussion_JoshB.cpp
    Date: 10/03/2024
    Description: This program simulates taking damage in a game from an ogre.
*/

#include <conio.h>              // needed for getch()
#include <iostream>             // needed for cout, cin
#include <string>               // would be needed for string input/input validation
#include <cstdlib>              // library to help with random number generation found at https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

// creating enum for health status'
enum ("Death" = 0, "Low" = 25, "Medium" = 70, "High" = 99, "Full" = 100) playerHealth;

// declaring functions used in this code
std::string calculateHealthStatusMessage(int providedHealth);
int calculateDamage();

int main()
{  
    // initializing variables used with main function
    int playerHealth = 100;
    int numberOfHits;
    std::string healthStatusMessage = calculateHealthStatusMessage(playerHealth);

    // welcoming user to game and capturing input
    std::cout << "\n\n  Welcome, lets simulate your luck when being attacked by an Ogre." 
         << "\n  You are starting the game at " 
         << healthStatusMessage << " You have " << playerHealth << " health."
         << "\n  How many attacked would you like to take? ";
    std::cin >> numberOfHits;
    std::cout << std::endl;

    // loop to reduce player health
    for (int hits = 0; hits < numberOfHits; hits++)
    {
        playerHealth -= calculateDamage(); 
    };

    // determining the players health status
    healthStatusMessage = calculateHealthStatusMessage(playerHealth);

    // informing user of the results of the simulated attack
    std::cout << "\n  After taking " 
         << numberOfHits 
         << " hits from the Ogre... " 
         << healthStatusMessage;

    if (playerHealth > 0) {
        std::cout << "\n  You are currently at " << playerHealth << " health." << std::endl;
    }
    
    // Display THE closing messageS for non Visual Studio IDEs
    std::cout << "\n  Thanks for using my program!" << std::endl;
    std::cout << "\n\n  Press any key to continue ..." << std::endl;

    _getch();  // halt processing 

    return 0;  // exit code
}

std::string calculateHealthStatusMessage(int providedHealth ) {
    // variable for health status
    std::string healthStatusMessage;

    // logic to determine current health status message
    if (providedHealth < death) {
        healthStatusMessage = "Well.... Sorry you died!";
    } else if (providedHealth < Low ) {
        healthStatusMessage =  "you are at low health!";
    } else if (providedHealth < Medium) {
        healthStatusMessage =  "you are at medium health!";
    } else if (providedHealth < High) {
        healthStatusMessage =  "you are at high health!";
    } else if (providedHealth == Full) {
        healthStatusMessage =  "you are at full health.";
    };

    return healthStatusMessage;
}

void calculateDamage() {
    // used to create seed/starting point for random number generator (rand() function call later in code)
    srand(time(0)); 

    // determine random damage from 0-99
    float damageTaken = rand() % 100;

    return damageTaken;
}

