/**
 * Name: Jay Gupta
 * StudentID: 0961979
 * Date: 3/19/2020
 * Program Name: C++LengthOfLine.cpp (V1.0)
 * CIS054 C/C++ Programming
 * 
 * Inputs: (X1, Y1) and (X2, Y2) 
 * Outputs: Distance between the two points
*/

#include <iostream> // for cin and cout 
#include <cmath> // for sqrt
#include <iomanip> // digits past the decimal 
using namespace std; 

double lengthOfLine(double x1, double y1, double x2, double y2); 

int main() {
    double x1, y1, x2, y2, length; // declaring variables

    cout << endl << "Enter x1, y1, x2, y2 separated by spaces: "; 
    cin >> x1 >> y1 >> x2 >> y2; 
    length = lengthOfLine(x1, y1, x2, y2); 

    cout << fixed; 
    cout << setprecision(4); 
    cout << endl << "The length of the line is: " << length << endl << endl; 

    return 0; 
}

double lengthOfLine(double x1, double y1, double x2, double y2) {
    // find distance between two values: absolute value of their difference

    double xDistance = abs(x1 - x2); 
    double yDistance = abs(y1 - y2); 

    double lineLength = sqrt(xDistance * xDistance + yDistance * yDistance); 

    return lineLength;  
}

