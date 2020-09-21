/*
Name: Jay Gupta
Student ID: 0961979
Platform: PC
Development System: Visual Studio Code 
Date: 1/28/2020

Program Name: Paycheck.cpp v1.0 Lab
Inputs: Hours, Pay Rate
Outputs: Gross Pay, Net Pay 
*/

/*

*/

#include <iostream>
#include <iomanip>
using namespace std; 

// defining the constants; variables that won't change 
const double OVERTIME_RATE = 1.5; 
const double TAX_RATE = 0.17; // 17% 

int main() 
{
    // define the variables 
    double hours, payRate;
    double regularHours, overtimeHours; 
    double taxes; 
    double regularPay, overtimePay, grossPay, netPay;

    cout << "\nHello, and welcome to the Paycheck Calculator! \n" << endl; 

    // get hours and payRate from the user 
    cout << "Enter the hours worked: ";
    cin >> hours;   

    cout << "Enter the pay rate: "; 
    cin >> payRate; 

    // if hours is less than or equal to 40, then there is no overtime 
    if (hours <= 40) {
        regularHours = hours; 
        overtimeHours = 0; 
    } else {
        regularHours = 40; 
        overtimeHours = hours - 40; 
    }

    // computation
    regularPay = regularHours * payRate; 
    overtimePay = overtimeHours * payRate * OVERTIME_RATE; 
    grossPay = regularPay + overtimePay; 
    taxes = grossPay * TAX_RATE; 
    netPay = grossPay - taxes; 

    // display the data to the user

    cout << fixed; 
    cout << setprecision(2); 
    cout << "\nYour gross pay is $" << grossPay << endl; 
    cout << "Your taxes are $" << taxes << endl; 
    cout << "Your net pay (what you take home) is $" << netPay << endl << endl;

    return 0; 
}