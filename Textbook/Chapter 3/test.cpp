#include <iostream>
using namespace std; 

void printTime(int hour, int minute) {
    cout << hour; 
    cout << ":"; 
    cout << minute; 
}

int main() {
    int hour; 
    int minutes;

    cout << "What is the hour? ";
    cin >> hour;   
    
    cout << "What is the minutes? "; 
    cin >> minutes; 

    cout << "The time is: "; 
    printTime(hour, minutes); 

    return 0;  
}