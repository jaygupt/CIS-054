#include <iostream>
#include <math.h>
using namespace std; 

int factorial (int n); 

int main() {
    cout << floor(4.9999) + ceil(2.0); 
}

int factorial (int n) {
    if (n == 0) {
        return 1; 
    } else {
        return n * factorial (n - 1); 
    }
}

int fibonacci (int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); 
    }
}