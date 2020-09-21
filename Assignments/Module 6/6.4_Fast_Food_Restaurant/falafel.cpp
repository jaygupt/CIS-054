/**
 * Name: Jay Gupta
 * StudentID: 0961979 
 * Date: 3/7/2020
 * Program Name: falafel.cpp (V1.0)
 * CIS054 C/C++ Programming
 * 
 * Functionality: Given the quantity of each food item, displays the various costs. 
 * Inputs: 'f' for falafels, 's' for sodas, 'x' for extras, 't' for total 
 * Output: Quantity of each food item, subtotal, tax, total
*/ 

#include <iostream> // cin and cout 
#include <cctype> // toupper 
#include <iomanip> // to set decimal places 
using namespace std; 

char displayMenu(); 

// global variables
char selection; 

// constants 
const double TAX_RATE = 0.087;  

int main() {
    double subtotal, tax, total; 
    double price; 

    int falafels = 0; 
    int sodas = 0; 
    int extras = 0; 

    do {
        selection = displayMenu(); 
        if (selection == 'F') {
            falafels +=1; 
        } else if (selection == 'S') {
            sodas += 1; 
        } else if (selection == 'X') {
            extras += 1; 
        }
    } while (selection != 'T'); 

    // Display user's order
    cout << endl; 
    cout << "You have ordered: " << endl; 

    // handle plurals 
    if (falafels == 1) {
        cout << falafels << " falafel" << endl; 
    } else {
        cout << falafels << " falafels" << endl;
    } 
    
    if (sodas == 1) {
        cout << sodas << " soda" << endl;
    } else {
        cout << sodas << " sodas" << endl; 
    } 

    if (extras == 1) {
        cout << extras << " extra" << endl; 
    } else {
        cout << extras << " extras" << endl;
    } 

    // compute & display costs 
    subtotal = (falafels * 5.15) + (sodas * 2.24) + (extras * 1.57); 
    tax = TAX_RATE * subtotal; 
    total = subtotal + tax; 

    cout << fixed << setprecision(2); 
    cout << endl << "The subtotal is: $" << subtotal << endl; 
    cout << "The tax is: $" << tax << endl; 
    cout << "The total is: $" << total << endl << endl; 

    return 0; 
}

char displayMenu() {
    do {
        cout << endl;   // blank line before start of menu
        cout << "F = falafel  $5.15" << endl;
        cout << "S = soda     $2.24" << endl;
        cout << "X = extras   $1.57" << endl;
        cout << "T = total" << endl;
        cout << "Make your selection (FSXT): ";
        cin >> selection;

        selection = toupper(selection); // make selection uppercase 

        // error message 
        if (selection != 'F' && selection != 'S' && selection != 'X' && selection != 'T') {
            cout << endl << "Incorrect Input. Please enter F, S, X, or T." << endl; 
        } 
    } while (selection != 'F' && selection != 'S' && selection != 'X' && selection != 'T'); 
    return selection; 
}