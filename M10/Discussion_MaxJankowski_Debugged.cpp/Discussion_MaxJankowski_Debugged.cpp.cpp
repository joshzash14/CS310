/*
    Student Name: Joshua Betancourt
    File Name: Discussion_MaxJankowski_Debugged.cpp
    Date: 11/3/2024
    Description: Debugged version of simple program to generate and manage a character in a roleplaying game provided by Max Jankowski
*/

//Simple program to generate and manage a character in a roleplaying game


#include <iostream>
#include <string>

using namespace std;

//structure to represent player character 
struct Character {
    string name;
    int hitPoints;
    int skill;
};

//Function to assign attributes/ stats
void createCharacter(Character* character, const string& name, int hitPoints, int skill) {
    character->name = name;
    character->hitPoints = hitPoints;
    character->skill = skill;
}

void displayCharacter(const Character* character) { //function to display character info
    cout << "Character Name: " << character->name << endl;
    cout << "Hit Points: " << character->hitPoints << endl;
    cout << "Skill Level: " << character->skill << endl;
}

void takeDamage(Character* character, int damage) { //Simulating damage and subtracting hit points
    character->hitPoints = damage;
    if (character->hitPoints < 0) character->hitPoints = 0;
    cout << character->name << " took " << damage << " damage! Health now at " << character->hitPoints << "." << endl;
}

int main() {
    // allocation of memory for an instance of character
    Character* hero(new Character);

    // creating a character and listing attributes 
    createCharacter(hero, "Tom the Not So Timid", 68, 10);

    // disabling info using displayCharacter function
    cout << "Character Profile:" << endl;
    displayCharacter(hero);
    
    // call to function for taking damage 
    takeDamage(hero, 20);
    
    // displaying updated stats
    cout << "\nUpdated Character Profile:" << endl;
    displayCharacter(hero);
 
    delete hero;

    return 0;
}