/**
 * Jay Gupta
 * Program: FirstNames.cpp (V1.0)
 * Date: 5/14/2020
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std; 

int main() {
    // declare variables
    char searchString[80];
    char currentBoy[80], currentGirl[80]; 
    int currentPosition = 0; 

    int positionOfBoy = 0; 
    int positionOfGirl = 0; 

    char fileName[] = "C:\\Users\\jaygu\\School\\SJCC\\C++\\Assignments\\Module 14\\14.4 - Final\\FirstNames.txt";

    ifstream mainFile (fileName);  

    if (!mainFile) {
        cerr << "Unable to open " << fileName << endl; 
        return 1; 
    } 

    // request a search string 
    cout << endl << "Enter a name to search: "; 
    cin.getline(searchString, 80); 

    while (!mainFile.eof()) { // while not at end of file:
        mainFile >> currentBoy; 
        mainFile >> currentGirl; 

        currentPosition++; // update position for next iteration 

        if (stricmp(searchString, currentBoy) == 0) {
            positionOfBoy = currentPosition; 
        } 
        if (stricmp(searchString, currentGirl) == 0) {
            positionOfGirl = currentPosition; 
        }
    }

    // Results! 
    if (positionOfBoy != 0) {
        // if 0, never found 
        cout << searchString << " is ranked " << positionOfBoy << " for boy names." << endl; 
    } else {
        // is 0, not found for boy names 
        cout << searchString << " was not found for boys." << endl; 
    }
    if (positionOfGirl != 0) {
        cout << searchString << " is ranked " << positionOfGirl << " for girl names." << endl; 
    } else {
        cout << searchString << " was not found for girls." << endl; 
    }

    cout << endl; 

    return 0; 
}