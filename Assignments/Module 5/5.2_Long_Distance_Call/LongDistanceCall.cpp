/**
 * LongDistanceCall-V1.0 - Determines the cost of a long-distance call
 * given the day of the week, time, and length of the call. 
 * Name: Jay Gupta
 * Date: 2/28/2020
 * Inputs: Day of the week, Start time of the call, Length of the call
 * Output: Cost of the call 
*/ 

#include <iostream> // for cin and cout 
#include <cstring> // for toupper()
#include <iomanip> // 2 digits past the decimal 
using namespace std; 

int main() { 
    // variables and constants
    char dayFirstLetter, daySecondLetter;
    char repeat; 
    bool isWeekend;  

    // time
    int hour; 
    char colon; 
    int minutes; 
    double timeStarted; 

    // rates
    double rate;
    const double WEEKEND_RATE = 0.15; 
    const double DAYTIME_RATE = 0.40; 
    const double NIGHTTIME_RATE = 0.25; 

    int lengthOfCall; 

    double costOfCall; 

    do {
        cout << endl << "Please enter the day of the week that the call started (Su, Mo, Tu, We, Th, Fr, Sa): "; 
        cin >> dayFirstLetter >> daySecondLetter;

        // convert both to uppercase  
        dayFirstLetter = toupper(dayFirstLetter);
        daySecondLetter = toupper(daySecondLetter);

        // is the day on a weekend or weekday? 
        if (dayFirstLetter == 'S' && (daySecondLetter == 'A' || daySecondLetter == 'U')) { 
            // weekend 
            isWeekend = true; 
        } else {
            isWeekend = false;  
        }

        // set the rate 
        if (isWeekend) {
            rate = WEEKEND_RATE; 
        } else {
            // was a weekday; find the time the call started
            cout << "What time did the call start? (Please enter time in 24-hour notation, ex) 1:30pm becomes 13:30): "; 
            cin >> hour >> colon >> minutes; 

            // convert hours and minutes into number format 
            timeStarted = hour * 100 + minutes; 

            if (timeStarted >= 800 && timeStarted <= 1800) {
                // call started between 8am and 6pm
                rate = DAYTIME_RATE; 
            } else {
                // call didn't start between 8am and 6pm
                rate = NIGHTTIME_RATE;  
            }
        }

        // length of call 
        cout << "How long was the call? (in minutes): "; 
        cin >> lengthOfCall; 

        // compute cost of the call 
        costOfCall = lengthOfCall * rate; 

        // display cost to user 
        cout << fixed; 
        cout << setprecision(2); 
        cout << endl << "The cost of your call is $" << costOfCall << "." << endl << endl; 

        // repeat the loop? 
        cout << "Again? (Y/N): "; 
        cin >> repeat; 
        repeat = toupper(repeat);   
    } while (repeat == 'Y'); 

    cout << endl << "Thanks for using the Long Distance Call calculator! See you later!" << endl << endl; 
    return 0; 
} // end of main 