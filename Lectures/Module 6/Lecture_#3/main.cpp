#include <iostream>
using namespace std; 

void printNumber(int x) {
    cout << x << endl; 
}

void printNumber(float x) {
    cout << x << endl; 
    return; 
}

void result (int x, int y) {
    int z = x * y; 
    cout << z; 
}

int main() {
    int a = 54; 
    float b = 32.4823; 

    printNumber(a); 
    printNumber(b); 

    return 0; 
}