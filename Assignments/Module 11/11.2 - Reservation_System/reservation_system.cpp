/**
 * Name: Jay Gupta
 * Date: 4/25/2020
 * Class: CIS 054 C/C++ Programming
 * File Name: reservation_system.cpp (V1.0)
 * Code Editor: VS Code
 * Platform: PC 
*/

#include <iostream>
#include <string> 
using namespace std;

// function declarations 
char **createArrayOfSeats(int rowQuantity, int seatQuantity); 
void initializeSeats(char **arrayOfSeats, int rowQuantity, int seatQuantity);
void displayArrayOfSeats(char **arrayOfSeats, int rowQuantity, int seatQuantity); 
void memoryCleanup(char **arrayOfSeats, int rowQuantity, int seatQuantity); 

// ** before arrayOfSeats is used to say "address of"

int main() {
    // variable declarations
    char **arrayOfSeats; // pointer to dimensional array  
    int numberOfRows, numberOfSeats, totalNumberOfSeats, occupiedSeats; 
    char answer; // Do you want another seat (y/n)?
    char userRow;
    char userColumn; 
    bool isValid = false; 

    // get array dimensions 
    // get array dimensions 
    cout << "Please enter the number of rows: "; 
    cin >> numberOfRows; 
    while (cin.fail() || numberOfRows <= 0) {
        cout << "ERROR: A number greater than 0 must be entered: "; 
        cin.clear(); 
        cin.ignore(123, '\n'); 
        cin >> numberOfRows; 
    }

    cout << "Please enter the number of seats in each row: "; 
    cin >> numberOfSeats;
    while (cin.fail() || numberOfSeats <= 0) {
        cout << "ERROR: A number greater than 0 must be entered: "; 
        cin.clear(); 
        cin.ignore(123, '\n'); 
        cin >> numberOfSeats; 
    }

    // calculate total number of seats, set occupiedSeats to 0
    totalNumberOfSeats = numberOfRows * numberOfSeats; 
    occupiedSeats = 0; 
    
    // display initial arrayOfSeats, and total number of seats + occupied 
    arrayOfSeats = createArrayOfSeats(numberOfRows, numberOfSeats); 
    initializeSeats(arrayOfSeats, numberOfRows, numberOfSeats); 
    displayArrayOfSeats(arrayOfSeats, numberOfRows, numberOfSeats); 
    cout << "Total number of seats: " << totalNumberOfSeats << endl;
    cout << "Total seats occupied: " << occupiedSeats << endl; 

    // get seat requests 
    do {
        // get seat selection from the user
        do {
            cout << "Enter a seat selection (example 2C), 00 to quit: "; 
            cin >> userRow;
            cin >> userColumn;
            if (userRow == '0' && userColumn == '0') {
                break; 
            } 
            userRow = userRow - '1'; 
            userColumn = toupper(userColumn) - 'A';  
            if (userRow < 0 || userRow >= numberOfRows || userColumn >= numberOfSeats) {
                isValid = false; 
            } else {
                if (arrayOfSeats[userRow][userColumn] == '-') {
                    cout << "The requested seat is already taken." << endl; 
                    continue; 
                } else {
                    arrayOfSeats[userRow][userColumn] = '-'; 
                    occupiedSeats++;
                    displayArrayOfSeats(arrayOfSeats, numberOfRows, numberOfSeats); 
                    cout << "Total number of seats: " << totalNumberOfSeats << endl;
                    cout << "Occupied Seats: " << occupiedSeats << endl;  
                    isValid = true; 
                }
            }
        } while (!isValid); 

        if (userRow == '0' && userColumn == '0') {
            break; 
        }

        // check if all seats are occupied 
        if (totalNumberOfSeats == occupiedSeats) {
            cout << endl << "All seats are occupied!" << endl << endl; 
            break; 
        }

        // ask user if they want another seat
        cout << "Do you want to select another seat (y/n)? "; 
        cin >> answer; 
        answer = toupper(answer); 
    } while (answer == 'Y'); 

    memoryCleanup(arrayOfSeats, numberOfRows, numberOfSeats); 
    return 0; 
}

char **createArrayOfSeats(int rowQuantity, int seatQuantity) {
    /*
    dynamically creating double-dimensional array requires an array of 
    pointers, with each pointer being an array of characters 
    */

    char **arrayOfSeats; // declare dimensional array
    // initializing the array to be a certain number of rows 
    arrayOfSeats = new char*[rowQuantity]; // each row contains an array of pointers 
    for (int r = 0; r < rowQuantity; r++) {
        arrayOfSeats[r] = new char[seatQuantity]; // each row is an array of characters 
    }
    return arrayOfSeats; 
}

void initializeSeats(char **arrayOfSeats, int rowQuantity, int seatQuantity) {
    // first for loop: a specific row 
    for (int r = 0; r < rowQuantity; r++) {
        for (int s = 0; s < seatQuantity; s++) {
            // the '+ s' allows the A to change to B, C, D, etc. 
            arrayOfSeats[r][s] = 'A' + s; 
        }
    }
}

void displayArrayOfSeats(char **arrayOfSeats, int rowQuantity, int seatQuantity) {
    // for each row 
    for (int r = 0; r < rowQuantity; r++) {
        cout.width(2); // adds two empty spaces before anything is shown 
        cout << r + 1 << ' '; // display row numbers starting from 1, followed by a space
        for (int s = 0; s < seatQuantity; s++) {
            cout << arrayOfSeats[r][s] << ' '; // display A, B, C, etc. for each seat, and space 
        }
        cout << endl; // new line after every row 
    }
}

void memoryCleanup(char **arrayOfSeats, int rowQuantity, int seatQuantity) {
    // delete each row individually
    // each row contains a character array  
    for (int r = 0; r < rowQuantity; r++) {
        delete [] arrayOfSeats[r]; 
    }
    // arrayOfSeats is now just an array of pointers
    delete [] arrayOfSeats;  // delete it 
}