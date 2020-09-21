/**
 * LongDistanceCall-V1.0 - Determines the cost of a long-distance call
 * given the day of the week, time, and length of the call. 
 * Name: Jay Gupta
 * Date: 2/28/2020
 * Inputs: Day of the week, Start time of the call, Length of the call
 * Output: Cost of the call 
*/ 

#include <iostream>
#include <cstring> // for toupper()
using namespace std; 

int main() { 
    // variables and constants
    char dayFirstLetter, daySecondLetter;
    char repeat; 
    bool isWeekend; 
    double rate; 

    // time
    int hour; 
    char colon; 
    int minutes; 
    int timeStarted; 

    do {
        cout << "What time did the call start? (Please enter time in 24-hour notation, ex) 1:30pm becomes 13:30): "; 
        cin >> hour >> colon >> minutes; 

        // convert hours and minutes into int format 
        timeStarted = hour * 100 + minutes; 
        cout << timeStarted << endl; 

        if (timeStarted >= 800 && timeStarted <= 1800) {
            // call is during day
            cout << "The call is during the day!" << endl; 
        } else {
            // call is during night 
            cout << "The call is during the night!" << endl; 
        }

        // repeat the loop? 
        cout << "Again? (Y/N): "; 
        cin >> repeat; 
        repeat = toupper(repeat);   
    } while (repeat == 'Y'); 
}