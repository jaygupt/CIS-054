/*
Name: Jay Gupta
Student ID: 0961979
Date: 2/22/2020
Program Name: C++_Computation_of_PI.cpp (V1.0)
CIS054 C/C++ Programming

Input: Number of terms 
Output: Computed PI, PI Constant value, Difference between the two 
*/

#include <iostream> // cin and cout 
#include <iomanip> // to set decimal places
#include <cmath> /// math functions, constants (PI)
using namespace std; 

const double PI_VALUE = 3.14159265358979; 

int main() {
    // variables (for input) 
    int terms; 

    // variables (for processing)
    int loopCount = 1; 
    double pi = 0; 

    double numerator = 4; 
    double denominator = 1; 
    double fraction; 

    double difference; 

    // input: how many terms does the user want?
    cout << endl << "How many terms do you want to compute PI to? "; 
    cin >> terms; 

    if (terms < 0) {
        cout << "The number of terms can't be negative." << endl << endl; 
        return 1; 
    } else if (cin.fail()) {
        cout << "Illegal entry for terms: enter an integer greater than or equal to 0." << endl << endl; 
        return 1; 
    }

    // processing
    while (loopCount <= terms) {
        // compute term to be added
        fraction = numerator / denominator; 

        if (loopCount % 2 == 1) {
            pi += fraction; 
        } else {
            // term number is even 
            pi -= fraction; 
        }
        denominator += 2;  
        loopCount += 1; 
    } 

    difference = fabs(PI_VALUE - pi); 

    cout << endl; // blank line before output 

    cout << fixed << setprecision(10); 
    cout << "PI Constant = " << PI_VALUE << endl; 
    cout << "Computed PI = " << pi << endl; 
    cout << "Difference  = " << difference << endl << endl;

    return 0;  
}