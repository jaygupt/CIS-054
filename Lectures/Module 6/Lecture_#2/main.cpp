#include <iostream>
using namespace std; 

double sum_of_numbers(double num1, double num2, double num3); 

int main() {
    double x = 7.5, y = 6.5, z = 7.5; 

    double sum = sum_of_numbers(x, y, z); 

    cout << "Sum of Numbers = " << sum; 

    return 0; 
}

double sum_of_numbers(double num1, double num2, double num3) {
    return num1 + num2 + num3; 
}