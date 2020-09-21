#include <iostream>
using namespace std; 

#include <cmath>

void nLines(int n) {
    if (n > 0) {
        cout << endl; 
        nLines(n - 1); 
    }
}

int main() {
    cout << "First Line" << endl; 
    nLines(10); 
    cout << "Tenth Line"; 
}