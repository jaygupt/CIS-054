/* C++ CountingChangeV1.0.c
   Jay Gupta
   CIS054 C/C++ Programming
   Date: 2/9/2020

   Project Description: 
   - Counts change and tells the user how many money, 
   in dollars, he/she has. 
   Inputs: count of: quarters, dimes, nickels, pennies
   Outputs: how much money (in dollars) there is 
*/

#include <iostream> // cin and cout 
#include <iomanip> // 2 digits past the decimal
using namespace std; 

// define the constants 
const double QUARTER_VALUE = 0.25; 
const double DIME_VALUE = 0.10; 
const double NICKEL_VALUE = 0.05; 
const double PENNY_VALUE = 0.01; 

int main() 
{
    // declare the variables 
    
    // coin types 
    int quarters; 
    int dimes; 
    int nickels; 
    int pennies; 

    // total 
    double total;  

    // title 
    cout << endl << "Jay's Coin Counting Program!" << endl << endl;  
    
    // input: # of each type of coin
    cout << "Enter the number of quarters: "; 
    cin >> quarters; 
    cout << "Enter the number of dimes: "; 
    cin >> dimes; 
    cout << "Enter the number of nickels: "; 
    cin >> nickels; 
    cout << "Enter the number of pennies: "; 
    cin >> pennies; 

    total = quarters * QUARTER_VALUE + dimes * DIME_VALUE 
    + nickels * NICKEL_VALUE + pennies * PENNY_VALUE; 
    
    cout << fixed; 
    cout << setprecision(2); 
    cout << endl << "Your total is: $"  << total << endl << endl; 
}