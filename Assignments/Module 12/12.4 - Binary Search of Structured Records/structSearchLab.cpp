/*
 * Name: Jay Gupta
 * Program: C++structSearchLab.cpp (V1.0)
 * Date: 5/5/2020
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

// define the max number of records in the file
const int LIST_LENGTH = 256;

// define the lengths of each character array
const int NAME_SIZE = 40;
const int NUMBER_SIZE = 13;
const int LINE_SIZE = 80;

typedef struct S_REC {
    char name[NAME_SIZE];
    char number[NUMBER_SIZE];
}PhoneRec;


#define debug_messages 1

int main()
{
    PhoneRec List[LIST_LENGTH];	// [length][width]
    char line[LINE_SIZE];				// line of text from the disk
    char filename[] = "C:\\Users\\jaygu\\School\\SJCC\\C++\\Assignments\\Module 12\\12.4 - Binary Search of Structured Records\\phony.422";
    char *ptr;
    int  searchCounter = 0;
    string phoneOrName; 
    int lowerBound = 1;
    int midPoint = 0;
    int firstOccurredMidpoint = 0; 
    int secondOccurredMidpoint = 0;

    ifstream PhoneFile(filename);

    if (! PhoneFile)
    {
        cerr << "Unable to open " << filename << endl;
        return 1;
    }

    int listsize=0;
    while (!PhoneFile.eof() && listsize < LIST_LENGTH)
    {
        line[0] = 0;                            // clear the line
        PhoneFile.getline(line, LINE_SIZE);     // read a line from the disk
        if (strlen(line) > 1)
        {

        // pick a version of strtok and strcpy that works with your compiler

        // VERSION-1
        // These 5 lines work for Microsoft Visual Studio. Comment them out if using Version-2
           char *nextToken = NULL;                             // used only by strtok_s
           ptr = strtok_s(line, ".", &nextToken);              // find name, separated by '.' character
           strcpy_s (List[listsize].name, NAME_SIZE, ptr);     // copy name to array, position listsize
           ptr = strtok_s(NULL, ".\r\n", &nextToken);          // find phone number
           strcpy_s (List[listsize].number, NUMBER_SIZE, ptr); // copy to array, position listsize
           listsize++;
        }
    }

    int upperBound = listsize;

#if debug_messages == 1		
    cout << endl << "There are " << listsize << " lines in the file." << endl;
#endif

    /////////// request a search string, then find it //////////
    char searchString[80];
    while (true) {
        cout << "Would you like to enter a phone number (p), or a name (n)? "; 
        getline(cin, phoneOrName); 
        
        phoneOrName = tolower(phoneOrName[0]); 
        
        if (phoneOrName == "p" || phoneOrName == "n") { 
            break; 
        } else {
            cout << "I don't know what you want to enter! Try again!" << endl; 
            continue; 
        }
    }

    cin.sync(); 
    
    if (phoneOrName == "p") {

        cout << endl << "Enter a phone number: ";
        // cin >> searchString;  // works fine for the phone number, but not the name
        // This is because the names have space characters. cin >> searchString stops
        // reading the input as soon as it sees a space and part of the name is lost
        // Use cin.getline(searchString,80);   instead to read a fill line from the keyboard.
        cin.getline(searchString,80);
        /////////////////////////////////////////////////////
        /////////// sequential search /////////////////////// (for phone number)
        /////////////////////////////////////////////////////
        bool found = false;
        int  index;
    
        for (index=0; index<listsize; index++)
        {
            searchCounter++;
            if (strstr(List[index].number, searchString)) // if found 
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Customer name: " << List[index].name << endl;
            cout << endl << searchCounter << " tests were made" << endl;
        }
        else
            cout << "Not found" << endl;

        searchCounter = 0; 
        
        ///////////////////////////////////////////////////
        //////////////// binary search ////////////////////
        ///////////////////////////////////////////////////
        searchCounter = 0; 

        cout << "\n********** Starting the BINARY SEARCH **********\n";
        found = false;
        while (found == false)
        {
            if (upperBound < lowerBound)   // does not exist
                break;      // exit with   found   still set to false

            // setting the midpoint            
            if (midPoint == 2) {
                midPoint = 1; 
            } else if (midPoint == 1) {
                midPoint = 0; 
            } else if (midPoint == (listsize - 2)) {
                midPoint = (listsize - 1); 
            } else {
                midPoint = lowerBound + (upperBound-lowerBound)/2;
            }

            
            if (midPoint == firstOccurredMidpoint || midPoint == secondOccurredMidpoint) {
                // does not exist
                break; 
            }

            searchCounter++;

            cout << searchCounter << " midPoint=" <<  midPoint 
                << "  " << List[midPoint].name << endl;
            

            if (stricmp(List[midPoint].number, searchString) == 0) // if found 
                found = true;
            else if (stricmp(List[midPoint].number, searchString) < 0) {
                lowerBound = midPoint-1;    // getting closer, cutoff the lower half
            }
            else {
                upperBound = midPoint+1;    // getting closer, cutoff the upper half
            }
            if (searchCounter % 2 == 0) {
                firstOccurredMidpoint = midPoint; 
            } else {
                secondOccurredMidpoint = midPoint; 
            }
        }
        if (found) // found
        {
            cout << endl << "Customer name: " << List[midPoint].name << endl;
            cout <<  searchCounter << " tests were made." << endl << endl;
        }
        else
            cout << "Not found in " << searchCounter << " tries." << endl << endl;
    } else if (phoneOrName == "n") {
        cout << endl << "Enter a name: ";
        // cin >> searchString;  // works fine for the phone number, but not the name
        // This is because the names have space characters. cin >> searchString stops
        // reading the input as soon as it sees a space and part of the name is lost
        // Use cin.getline(searchString,80);   instead to read a fill line from the keyboard.
        cin.getline(searchString,80);

        /////////////////////////////////////////////////////
        /////////// sequential search /////////////////////// (for name)
        /////////////////////////////////////////////////////
        bool found = false;
        int  index;
        for (index=0; index<listsize; index++)
        {
            searchCounter++;
            if (strstr(List[index].name, searchString)) // if found 
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "Phone Number: " << List[index].number << endl;
            cout << endl << searchCounter << " tests were made.";
        }
        else
            cout << "Not found.";
        
        ///////////////////////////////////////////////////
        //////////////// binary search ////////////////////
        ///////////////////////////////////////////////////

        searchCounter = 0; 

        cout << "\n\n********** Starting the BINARY SEARCH **********\n";
        found = false;
        while (found == false)
        {
            searchCounter++;

            cout << searchCounter << " midPoint=" <<  midPoint 
                << "  " << List[midPoint].name << endl;

            if (upperBound < lowerBound)   // does not exist
                break;      // exit with   found   still set to false

            // setting the midpoint            
            if (midPoint == 2) {
                midPoint = 1; 
            } else if (midPoint == 1) {
                midPoint = 0; 
            } else if (midPoint == (listsize - 2)) {
                midPoint = (listsize - 1); 
            } else {
                midPoint = lowerBound + (upperBound-lowerBound)/2;
            }

            
            if (midPoint == firstOccurredMidpoint || midPoint == secondOccurredMidpoint) {
                // does not exist
                break; 
            }
            

            if (stricmp(List[midPoint].name, searchString) == 0) // if found 
                found = true;
            else if (stricmp(List[midPoint].name, searchString) < 0) {
                lowerBound = midPoint-1;    // getting closer, cutoff the lower half
            }
            else {
                upperBound = midPoint+1;    // getting closer, cutoff the upper half
            }
            if (searchCounter % 2 == 0) {
                firstOccurredMidpoint = midPoint; 
            } else {
                secondOccurredMidpoint = midPoint; 
            }
        }
        if (found) // found
        {
            cout << endl << "Phone number: " << List[midPoint].number << endl;
            cout <<  searchCounter << " tests were made." << endl << endl;
        }
        else
            cout << "Not found in " << searchCounter << " tries." << endl << endl;
    }
    return 0;
}
