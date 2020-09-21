/*
Name: Jay Gupta
Student ID: 0961979
Date: 2/23/2020
Program Name: C++SumAverageRange.cpp (V1.0)
CIS054 C/C++ Programming

Inputs: 10 Numbers
Output: sum of: odd #s, even #s, and all #s. Lowest and highest values, 
range, and average
*/

#include <iomanip>
#include <iostream>
using namespace std; 

const int NUMBER_COUNT = 10; // doesn't change 

int main() {
    // variables related to output 
    int sumOfOddNumbers = 0; 
    int sumOfEvenNumbers = 0; 
    double sumOfAllNumbers = 0; 
    int minValue; 
    int maxValue; 
    int range; 
    double average; 

    // variables related to processing 
    int currentNumber;
    int inputCounter = 1; 
    string ordinalIndicator; 

    // blank line before input runs
    cout << endl; 

    while (inputCounter <= NUMBER_COUNT) {
        // ordinal indicator
        if (inputCounter == 1) {
            ordinalIndicator = "st"; 
        } else if (inputCounter == 2) {
            ordinalIndicator = "nd"; 
        } else if (inputCounter == 3) {
            ordinalIndicator = "rd"; 
        } else if (inputCounter >= 4) {
            ordinalIndicator = "th"; 
        } 

        // Input the number 
        cout << "Please enter the " << inputCounter << ordinalIndicator << " number: "; 
        cin >> currentNumber; 

        // input validation
        if (currentNumber < 0) {
            cout << "Negative values aren't allowed." << endl << endl; 
            return 1; 
        } else if (cin.fail()) {
            cout << "Illegal entry for number: it should be an integer, greater than or equal to 0." << endl << endl; 
            return 1; 
        }

        // odd or even: if even, add to even sum. If odd, add to odd sum.
        if (currentNumber % 2 == 0) {
            // if even
            sumOfEvenNumbers += currentNumber; 
        } else {
            // if odd 
            sumOfOddNumbers += currentNumber; 
        }

        // add number to allNumbers
        sumOfAllNumbers += currentNumber; 

        // determine if number is lowest or highest

        // first, initalize min and max
        if (inputCounter == 1) {
            minValue = currentNumber; 
            maxValue = currentNumber; 
        } else {
            // if currentNumber is greater than max, the new max is = to currentNumber
            if (currentNumber > maxValue) {
                maxValue = currentNumber;
            } else if (currentNumber < minValue) {
                // else if currentNumber is less than min, the new min is = to currentNumber
                minValue = currentNumber; 
            }
            // if neither condition is true (currentNumber is in the middle, or equal to min or max) do nothing 
        }

        inputCounter++; 
    } // while loop is over, all values have been calculated

    // End Computations

    // range
    range = maxValue - minValue; 

    // average 
    average = sumOfAllNumbers / NUMBER_COUNT; 

    // OUTPUT: display the results 
    cout << endl; // blank line, for organization
    cout << "The sum of all odd numbers is: " << sumOfOddNumbers << endl; 
    cout << "The sum of all even numbers is: " << sumOfEvenNumbers << endl;
    cout << "The sum of all numbers is: " << sumOfAllNumbers << endl; 
    cout << "The lowest value is: " << minValue << endl; 
    cout << "The highest value is: " << maxValue << endl; 
    cout << "The range is: " << range << endl;
    cout << fixed << setprecision(2); 
    cout << "The average is: " << average << endl << endl; 
}