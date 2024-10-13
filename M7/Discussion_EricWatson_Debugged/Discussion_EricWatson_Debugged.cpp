/*
    Student Name: Joshua Betancourt
    File Name: Discussion_EricWatson_Debugged.cpp
    Date: 10/13/2024
    Description: This program is the working solution for Eric Watson's Discussion submission.
*/

#include <iostream>

using namespace std;

void main() {
    int arr[] = {rand(),
                 rand(),
                 rand(),
                 rand(),
                 rand(),
                 rand()};

    for(int i = 0; i < 6; i++) {
        cout << arr[i];
    }
}
