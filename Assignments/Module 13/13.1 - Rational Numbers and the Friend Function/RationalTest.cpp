// Jay Gupta
// Date: 5/10/2020
// Rational.cpp : Defines the entry point for the console application. (V1.0)
// Create a Rational class defination
//    Rational(numerator, denominator)
//
#include "Rational.h"   // double quotes = find file in project folder
#include <iostream>     // angle brackets = find file in compiler folder
#include <iomanip>
using namespace std;

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (Rational, Rational, Rational, const char *);

int main(int argc, char* argv[])
{
//  class    object
//    |        |
//    V        V
    Rational n1;
    Rational n2;  
    Rational n3;      

    // Title at the top of the display
    cout << "    n1     n2   n3\n  ==================\n" << endl;

    // Display values of n1, n2, n3 before each test
    initializeNumbers (n1, n2, n3);
    displayNumbers(n1, n2, n3, "Values of n1, n2 and n3 before each test");

    // Test operator+
    n1 = n2.operator+(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers(n1, n2, n3, "n1 = n2 + n3 (n1 should be 17/12)");

    // Test operator+=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator+=(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 += n3 (n1 and n2 should be 17/12)");

    // Test operator-
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator-(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 - n3 (n1 should be 1/12)");

    // Test operator-=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator-=(n3);
    displayNumbers(n1, n2, n3, "n1 = n2 -= n3 (n1 and n2 should be 1/12)");

    // Test operator*
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator*(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 * n3 (n1 should be 1/2)");

    // Test operator*=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator*=(n3);
    displayNumbers(n1, n2, n3, "n1 = n2 *= n3 (n1 and n2 should be 1/2)");

    // Test operator/
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator/(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 / n3 (n1 should be 9/8)");

    // Test operator/=
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator/=(n3);
    displayNumbers(n1, n2, n3, "n1 = n2 /= n3 (n1 and n2 should be 9/8)");

    // Test operator= this is a copy operator
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator=(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 = n3 (n1, n2, and n3 should be 2/3)");
    
    // Test operator==  this should return a TRUE if both numbers are the same, otherwise FALSE
    initializeNumbers (n1, n2, n3); // reset the values before each test
    n1 = n2.operator==(n3); 
    displayNumbers(n1, n2, n3, "n1 = n2 == n3 (n1 should be 0/1) (FALSE)");

    // Test operator double
    cout << endl << endl << "**** Rational number to double. 1/12 displays as 0.0833333" << endl;
    cout << "double(n2) = " << double(n2) << endl;
	cout << endl;
    return 0;
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3)
{
    n1 = Rational ();     //    0  no arguments
    n2 = Rational (3,4);  //   3/4
    n3 = Rational (2,3);  //   2/3
}

// Display each of the rational numbers using the friend function <<
void displayNumbers (Rational n1, Rational n2, Rational n3, const char *msg)
{
    cout << setw(4) << n1 << setw(4) <<  n2 << setw(4)  << n3 << "\t" << msg << endl;
}