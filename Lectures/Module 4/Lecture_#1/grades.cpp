#include <string>
#include <iostream>
using namespace std; 

int main() {
    double score; 
    char grade; 
    string message; 

    // read score from keyboard
    cout << "Please enter your score: "; // prompt
    cin >> score; // read the keyboard

    score += 0.5; // being generous 

    if (score >= 90) {
        grade = 'A'; 
        message = "Outstanding"; 
    } else if (score >= 80) {
        grade = 'B'; 
        message = "Exceeds Expectations"; 
    } else if (score >= 70) {
        grade = 'C'; 
        message = "Average"; 
    } else if (score >= 60) {
        grade = 'D'; 
        message = "Poor"; 
    } else if (score >= 0) {
        grade = 'F'; 
        message = "Dreadful"; 
    } else {
        grade = '?'; 
        message = "Unknown"; 
    } 

    // display results
    cout << "Your grade is: " << grade << ", which is " << message << endl; 

    return 0; 
}