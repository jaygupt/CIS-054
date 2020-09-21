#include <iostream>
using namespace std; 

// main: generate some simple output 

int main() 
{
    int score;
    string balanceOnCheckingAccount; 
    string Lab12; 
    cout << "What score did you get on the exam? "; 
    cin >> score;  
    char grade; 

    if (score > 70) {
        grade = 'P'; 
    } else {
        grade = 'F'; 
    }

    cout << grade; 

    return 0; 
} 