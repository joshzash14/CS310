/*
    Student Name: Joshua Betancourt
    File Name: Discussion_MichaelGiuliano_Debugged.cpp
    Date: 10/04/2024
    Description: Updated discussion post correcting errors in this program. This program simulates taking damage in a game from an ogre.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std;

enum GameState { STARTING, PLAYING, QUITTING };

enum PlayerState { DEAD, IDOL, EXPLORING, BATTLING };

void startGameLoop();
void getPlayerName();
void playGame();
void getPlayerInput();
void battle();
string generateEnemyName();
void pause(int millis);
void explore(); // sneaky error as this was not defined, code tried to ref before using it, causing error
 
// Arrays used to generate random enemy names
string enemyAdjectives[] = { "Green", "Red", "Giant", "Devilish", "Rabid" };
string enemyTypes[] = { "Lion", "Skeleton", "Dragon", "Creature", "Minion" };

GameState gameState;
PlayerState playerState;
string playerName;
int playerHealth;

int main() {
    srand(time(NULL));
    gameState = STARTING;
    playerState = IDOL;
    playerHealth = 100;

    startGameLoop();
}

// The main loop of the game
void startGameLoop() {
    bool isRunning = true;

    while (isRunning) {
        switch (gameState) {
        case STARTING:
            cout << "\n\n  Welcome to my dungeon crawler!";
            getPlayerName();
            break;
        case PLAYING:
            playGame();
            break;
        case QUITTING: // errors on each expression must have class type but it has type "GameState", remove gameState.. as switch is already ref enum
            cout << endl << "  Fare thee well!" << endl << endl;
            isRunning = false;
            break;
        }
    }
}

// Asks the user to provide a name for their player
void getPlayerName() {
    cout << endl << "\n  Enter a name for you player: ";
    cin >> playerName;
    gameState = PLAYING;
}

// Performs actions based on the player's state
void playGame() {
    switch (playerState) {
    case DEAD:
        gameState = QUITTING;
        break;
    case IDOL:
        getPlayerInput();
        break;
    case EXPLORING:
        explore();
        break;
    case BATTLING:
        battle();
        break;
    }
}

// Gets input from the user as to what action to take
void getPlayerInput() {
    char option;
    bool invalidOption = false;

    do {
        invalidOption = false;

        cout << endl
            << "  ACTIONS" << endl
            << "  ------------" << endl
            << "  1) Explore" << endl
            << "  2) Quit game" << endl
            << "  >> "; // missing semi-colon, sneaky as left cin indented at the same as cout lines
        cin >> option;

        if (option == '1')
            playerState = EXPLORING;
        else if (option == '2')
            gameState = QUITTING;
        else {
            cout << endl << "  I don't know how to do that. Try again." << endl;
            invalidOption = true;
        }

    } while (invalidOption); // missing semi colon, expected semi colon error
}

// The player explores the dungeon and can either find gold, nothing, or encounter an enemy 
void explore() {
    int value = rand() % 100 + 1;

    if (value % 7 == 0) {  // Found gold
        int amount = rand() % 50 + 1;
        cout << endl << "  You found " << amount << " gold piece(s)." << endl;
        playerState = IDOL;
    }
    else if (value % 3 == 0) { // Encounter enemy
        playerState = BATTLING;
    }
    else {
        cout << endl << "  You walk through the dungeon and find nothing." << endl;
        playerState = IDOL;
    }
}

// Battle sequence between the player and an enemy
void battle() {
    string enemyName = generateEnemyName();
    int enemyHealth = rand() % 30 + 10;
    bool isBattling = true;
    bool isPlayersTurn = true;
    string option;

    cout << endl << "  You encounter a " << enemyName << "! Prepare for battle!" << endl << endl;

    pause(2000);

    while (isBattling) {
        if (isPlayersTurn) {
            cout << endl
                << "  ------------------------------------------------------------" << endl
                << "  " <<playerName << ": " << playerHealth << "     " << enemyName << ": " << enemyHealth << endl
                << "  ------------------------------------------------------------" << endl
                << endl
                << "  1) Attack" << endl
                << "  2) Flee" << endl
                << "  >> ";
            cin >> option;

            if (option == "1") {
                int damage = rand() % 15;
                enemyHealth -= damage;
                if (enemyHealth <= 0) {
                    cout << endl << "  You attack and kill the " << enemyName << "." << endl;
                    playerState = IDOL;
                    isBattling = false;
                }
                else {
                    cout << endl << "  You attack the " << enemyName << " and cause " << damage << " damage." << endl;
                    isPlayersTurn = false;
                }
            }
            else if (option == "2") {
                bool canFlee = (rand() % 5) == 0;

                if (canFlee) {
                    cout << endl << "  You have successfully fled the battle." << endl;
                    playerState = IDOL;
                    isBattling = false;
                }
                else {
                    cout << endl << "  You try to flee but the " << enemyName << " catches you." << endl;
                    isPlayersTurn = false;
                }
            }
            else {
                cout << endl << "  You stumble." << endl;
                isPlayersTurn = false;
            }
        }
        else {  // Enemy's turn
            int damage = rand() % 15;
            playerHealth -= damage;
            if (playerHealth <= 0) {
                cout << endl << "  The " << enemyName << " attacked and killed you." << endl;
                playerState = DEAD;
                isBattling = false;
            }
            else {
                cout << endl << "  The " << enemyName << " attacks you and causes " << damage << " damage." << endl;
                isPlayersTurn = true;
            }
        }

        pause(1250);
    }
}

// Generates a random enemy name
string generateEnemyName() {
    string name1 = enemyAdjectives[rand() % 5];
    string name2 = enemyTypes[rand() % 5];

    return name1.append(" ").append(name2);
}

// Pauses the application thread for the provided number of milliseconds
void pause(int millis) {
    this_thread::sleep_for(chrono::milliseconds(millis));
}