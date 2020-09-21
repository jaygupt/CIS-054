/**
 * Jay Gupta
 * SJECCD CIS 054
 * 4/12/2020
 * Dan McElroy
 * Module 10
 * C++_Sentence_Formatting.cpp (V1.0)
 * Input: Poorly formatted sentence
 * Ouput: Properly formatted sentence, with modifications from project description. 
*/

#include <iostream>
using namespace std; 

int main() {
    char userInput[200];

    cout << endl << "Please input a phrase to be formatted (include a period): ";
    cin.getline(userInput, 200); 

    // clear all whitespace
    int i = 0; 

    // loop through the whole sentence, until the end 
    while (userInput[i] != '\0') {

        // if the current character and the next character over are spaces
        if (userInput[i] == ' ' && userInput[i + 1] == ' ') {
            // shift the whole remaining sentence 1 to the left, to get rid of the second space 
            for (int j = i; userInput[j]; j++) {
                userInput[j] = userInput[j + 1]; 
            }

            // continue to the next iteration, we don't want i increasing; we want to stay in the same place
            // until all the extra spaces are gone 
            continue; 
        } else if (isspace(userInput[i])) { // also check for tabs and newlines
            if (isspace(userInput[i + 1])) { // if the character after the first is also a newline/tab
                for (int j = i; userInput[j]; j++) { // shift the whole thing to the left, like above
                    userInput[j] = userInput[j + 1]; 
                }
                continue;
            } else {
                userInput[i] = ' '; // if there's only one tab/newline, convert it to a space
            }
        }

        i++; // go on to the next character 
    }

    // ensure that the first letter is capitalized
    userInput[0] = toupper(userInput[0]); 

    // make all other letters lowercase
    for (i = 1; userInput[i]; i++) {
        userInput[i] = tolower(userInput[i]); 
    }

    cout << endl << "User input properly formatted: " << userInput << endl << endl; 

    return 0; 
}