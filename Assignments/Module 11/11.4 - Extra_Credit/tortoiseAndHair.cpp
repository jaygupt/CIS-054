/**
 * Name: Jay Gupta
 * Class: CIS 054 C/C++ Programming
 * File & Version: tortoiseAndHair.cpp (V1.0)
 * Extra Credit
 * Inputs: None
 * Outputs: race between tortoise and hair. Who won, or if there is a tie. 
 * Date: 5/3/2020
*/

/*
t and h begin at square 1
square 70 is finish line 
first to reach/pass 70 is winner 
clock that ticks once per second 
    each tick (second), use functions moveTortoise and moveHare 
USE POINTER BASED PASS-BY-REFERENCE to modify positions 
Figure 8.18 shows movement types, percentages, and number of squares
use variables to keep track of positions of animals 
if animal slips left before square 1, move animal back to square 1 
*/

#include <iostream>
#include <ctime>
using namespace std; 

void moveTortoise(int *positionOfTortoise); 
void moveHare(int *positionOfHare);
void displayCurrentStatus(int *harePosition, int *tortoisePosition); 

const int lengthOfRace = 70;

int main() {
    // beginning of the race 
    cout << "BANG !!!!!" << endl;
    cout << "AND THEY'RE OFF !!!!!" << endl;  

    // initial variables
    int tortoisePosition = 1; 
    int harePosition = 1;  
    srand(time(0)); // initialize random seed, for use in random-number generation

    // while no one has won the race...
    while (tortoisePosition < lengthOfRace && harePosition < lengthOfRace) {
        moveHare(&harePosition); 
        moveTortoise(&tortoisePosition);

        if (harePosition < 1) {
            // if hare goes back from starting position:
            harePosition = 1; // set him back
        } else if (harePosition > lengthOfRace)  {
            harePosition = lengthOfRace; 
        }

        if (tortoisePosition < 1) {
            tortoisePosition = 1; 
        } else if (tortoisePosition > lengthOfRace) {
            tortoisePosition = lengthOfRace;  
        }

        // display current status
        displayCurrentStatus(&harePosition, &tortoisePosition); 
    }

    return 0; 
}

void moveTortoise(int *positionOfTortoise) {
    int actualMove = 0; 
    int randomInt = 1 + rand() % 10; // random integer from 1 to 10 

    if (randomInt >= 1 && randomInt <= 5) {
        actualMove = 3; // fast plod
    } else if (randomInt >= 6 && randomInt <= 7) {
        actualMove = -6; // slip 
    } else {
        // randomInt is greater than 7 
        actualMove = 1; // slow plod 
    }

    *positionOfTortoise += actualMove; 
}

void moveHare(int *positionOfHare) {
    int actualMove = 0; 
    int randomInt = 1 + rand() % 10; // random integer from 1 to 10 

    if (randomInt >= 1 && randomInt <= 2) {
        actualMove = 0; // sleep, no move
    } else if (randomInt >= 3 && randomInt <= 4) {
        actualMove = 9; // big hop, 9 squares
    } else if (randomInt == 5) {
        actualMove = -12; // big slip 
    } else if (randomInt >= 6 && randomInt <= 8) {
        actualMove = 1; // small hop 
    } else {
        // randomInt is greater than 8 
        actualMove = -2; 
    }
    *positionOfHare += actualMove; 
}

void displayCurrentStatus(int *harePosition, int *tortoisePosition) {
    bool hareWins = false; 
    bool tortoiseWins = false; 
    bool isTie = false; 
    for (int currentPointer = 0; currentPointer < (lengthOfRace + 1); currentPointer++) {
        char placedChar = '-';
        if (currentPointer == 0) {
            // place a command line > at the beginning of each new line 
            cout << '>';  
        } else if (currentPointer == *harePosition && currentPointer == *tortoisePosition) {
            // this means that the hare and tortoise are in the same place...
            if (currentPointer < lengthOfRace) {
                // ...somewhere in the race: someone's gonna get bitten!
                cout << "OUCH!!!"; 
            } else {
                // ...at the end of the race: it's a tie
                // should we root for the underdog? Nah. 
                isTie = true;  
            }
        } else if (currentPointer == *harePosition) {
            // display hare's position 
            cout << 'H';   
            if (currentPointer == lengthOfRace) {
                // hare has won
                hareWins = true; 
            }
        } else if (currentPointer == *tortoisePosition) {
            // display tortoise's position
            cout << 'T';   
            if (currentPointer == lengthOfRace) {
                // tortoise has won
                tortoiseWins = true; 
            }
        } else {
            if (currentPointer < lengthOfRace) {
                cout << '-'; 
            } else {
                // currentPointer == lengthOfRace
                cout << '|'; 
            }
        }

        if (hareWins) {
            cout << endl << "Hare wins. Yuch."; 
        } else if (tortoiseWins) {
            cout << endl << "TORTOISE WINS!!! YAY!!!"; 
        } else if (isTie) {
            cout << endl << "It's a tie.";
        }
    }

    cout << endl; // next track on next line 
}