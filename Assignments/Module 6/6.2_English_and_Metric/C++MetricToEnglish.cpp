/**
 * Name: Jay Gupta
 * StudentID: 0961979 
 * Date: 3/7/2020
 * Program Name: C++MetricToEnglish.cpp (V1.0)
 * CIS054 C/C++ Programming
 * 
 * Functionality: Converts values between Metric and English
 * Inputs: (E (English), inches) and (M (Metric), centimeters)
 * Output: Centimeters (from English) or inches (from Metric) 
*/ 

#include <iostream> // for cin and cout 
#include <cctype> // for toupper function
#include <iomanip> // to set decimal places 
using namespace std; 

char menuSelect(); 

int main() {
    double inches, centimeters;
    char selection; 

    cout << fixed << setprecision(1); // 1 digit past decimal for output

    do { 
        try {
            selection = menuSelect();
            if (selection == 'E') {
                // user wants to convert from English to Metric 
                cout << endl << "Enter the number of inches: "; 
                cin >> inches;

                if (cin.fail()) {
                    throw 0; 
                }
                else if (inches < 0) {
                    throw 1; 
                } else {
                    // no errors
                    centimeters = inches * 2.54; 
                    cout << inches << " inches is equal to " << centimeters << " centimeters." << endl;
                }
            } else if (selection == 'M') {
                // user wants to convert from Metric to English
                cout << endl << "Enter the number of centimeters: "; 
                cin >> centimeters; 

                if (cin.fail()) {
                    throw 0; 
                }
                else if (centimeters < 0) {
                    throw 1; 
                } else {
                    // no errors
                    inches = centimeters / 2.54; 
                    cout << centimeters << " centimeters is equal to " << inches << " inches." << endl;
                }
            }
        }
        
        catch (int x) {
            if (x == 0) {
                cout << endl << "Please enter a number, no strings are allowed." << endl; 
                cin.clear(); // clear the error flag​
                cin.ignore(245, '\n'); // ignore remaining input until new-line (Enter) is reached​
            } else if (x == 1) {
                cout << endl << "Negative numbers aren't allowed." << endl;  
            }
        } 
    } while (selection != 'Q'); 

    // sign-off 
    cout << endl << "Thank you for using the Metric to English converter!" << endl;
    cout << "See you next time!" << endl << endl;  
    return 0; 
}

char menuSelect() {
    char userSelection; 
    do {
        cout << endl; // blank line
        cout << "Enter E to convert from English to Metric, M to convert from Metric to English, or Q to Quit: "; 
        cin >> userSelection; 
        userSelection = toupper(userSelection); // convert to uppercase 
    } while (userSelection != 'E' && userSelection != 'M' && userSelection != 'Q'); 
    return userSelection; 
}
