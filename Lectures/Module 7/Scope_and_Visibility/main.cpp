#include <iostream>
using namespace std; 

double add(double num1, double num2); 

int main() {
    cout << add(78, 5.23) << endl; 
    return 0; 
}

double add(double num1, double num2) {
    double answer = num1 + num2; 

    return answer; 
}