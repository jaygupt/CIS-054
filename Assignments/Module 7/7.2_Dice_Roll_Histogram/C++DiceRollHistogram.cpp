/**
 * Name: Jay Gupta
 * StudentID: 0961979
 * Date: 3/19/2020
 * Program Name: C++DiceRollHistogram.cpp (V1.0)
 * CIS054 C/C++ Programming
 * 
 * Inputs: None 
 * Outputs: How many times each value from 2 to 12 were rolled 
*/

#include <iostream> // for cin and cout 
#include <ctime> // for time function
using namespace std; 

int roll(); 
int roll2Dice(); 

int main() {
    int numberOfRolls = 0; 
    int rolledValue = 0; 

    int counter[11] = {}; 

    while (numberOfRolls < 1000) { // roll the dice 1000 times
        rolledValue = roll2Dice(); 
        counter[rolledValue - 2]++; 
        numberOfRolls++; 
    }

    size_t n = sizeof(counter) / sizeof(counter[0]); 

    int firstValue = 2; 
    for (size_t i = 0; i < n; i++) {
        cout << firstValue << " was rolled " << counter[i] << " times." << endl; 
        firstValue++; 
    }

    return 0; 
}

// returns a random integer from 1 to 6 (inclusive)
// (one dice)
int roll() {
    // static variables - keep same memory location until program ends
    static bool randomInitialized = false; 

    int points; 

    if (!randomInitialized) {
        srand((unsigned int) time(NULL)); // initialize random 
        randomInitialized = true; // don't do it again 
    }

    // rand returns value from 0 to largest possible integer 
    points = (rand() % 6) + 1; // points is from 1 to 6
    return points; 

    return 0; 
}

int roll2Dice() {
    int die1 = roll(); 
    int die2 = roll(); 

    int total = die1 + die2; 

    return total; 
}