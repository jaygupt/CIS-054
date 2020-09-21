/**
 * MeanAndMedianOfDataFile-V1.0
 * Program Name: MeanAndMedianOfDataFile.cpp
 * Name: Jay Gupta
 * Student ID: 0961979
 * Date: 3/30/2020
 * Inputs: Name of the File
 * Outputs: Number of Records, Total, Mean, Median 
*/

#include <iostream> // cin and cout 
#include <fstream> // (input file stream) 
#include <iomanip> 
using namespace std; 

int main() {
    // variables to control disk files
    ifstream inFile; 
    string startingRoot = "C:\\Users\\jaygu\\School\\SJCC\\C++\\Assignments\\Module 9\\9.2_Mean_&_Median_of_a_Disk_File\\Balance_Files\\"; 
    string textFile;  

    // inFile variables
    int acctNo = 0; 
    string name = ""; 
    
    double acctBal = 0.0; 

    int numOfRecords = 0; // to count number of records

    // mean, median, and mode variables
    double total = 0.0; 
    double mean = 0.0; 
    int recordsToSkip = 0; 
    double median = 0.0; 

    cout << endl << "Enter the name of the data file: "; 
    cin >> textFile; 

    string fullDirectory = startingRoot + textFile; 

    inFile.open(fullDirectory); 
    if (!inFile) {
        cerr << endl << "Unable to open --" << textFile << "--, first pass." << endl << endl; 
        exit(1); 
    } else {
        cerr << endl << "Opened --" << textFile << "-- successfully." << endl << endl; 
    }

    cout << fixed; 
    cout << setprecision(2);

    // Part 1: Count the Number of Records in the File 
    inFile >> acctNo >> name >> acctBal; 
    while (!inFile.eof()) {
        if (name[0] != 0) { // ignore empty records
            total += acctBal; 
            numOfRecords++; 
        }
        name[0] = 0; // initialize to 0 to test for empty records 
        inFile >> acctNo >> name >> acctBal; 
    }
    inFile.close(); 

    cout << "There are " << numOfRecords << " records in " << textFile << "." << endl << endl;

    cout << "The total is: $" << total << "." << endl << endl; 

    mean = total / numOfRecords; 
    cout << "Therefore, the mean is: $" << mean << "." << endl; 

    // Part 2: Determine the number of records to skip 
    bool isOdd = numOfRecords % 2 == 1; 

    if (isOdd) {
        // odd number of records 
        recordsToSkip = numOfRecords / 2; 
    } else {
        // even number of records
        recordsToSkip = (numOfRecords / 2) - 1; 
    }

    // Part 3: Determine the median, given the recordsToSkip
    inFile.open(fullDirectory); 
    if (!inFile) {
        cerr << endl << "Unable to open --" << textFile << "--, first pass" << endl << endl; 
        exit(1); 
    } 

    while (recordsToSkip > 0) {
        // if recordsToSkip is 0, stop 
        inFile >> acctNo >> name >> acctBal; 
        recordsToSkip--; 
    }

    // this is the record we want 
    inFile >> acctNo >> name >> acctBal;
    
    if (isOdd) { 
        // if it's odd, this is all we need 
        median = acctBal; 
    } else {
        // if even, we have to get the next record too
        double firstNum = acctBal; 
        inFile >> acctNo >> name >> acctBal; 
        double secondNum = acctBal; 

        median = (firstNum + secondNum) / 2; 
    }

    cout << endl << "The median is $" << median << "." << endl << endl;
    inFile.close();  

    return 0; 
}