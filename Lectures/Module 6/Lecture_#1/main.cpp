#include <iostream>
using namespace std; 

void favoriteNumber(int number); 

int main() {
    favoriteNumber(23); 
    favoriteNumber(100); 
    return 0; 
}

void favoriteNumber(int number) {
    cout << "Jay's favorite number is " << number << endl; 
}