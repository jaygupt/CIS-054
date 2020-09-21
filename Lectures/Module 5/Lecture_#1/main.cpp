#include <iostream>
using namespace std; 

double Square(double x) {
    return x * x; 
}

int main(int argc, char* argv[]) {
    double n1; 
    double n2; 
    cout << "Enter a number: "; 
    cin >> n1; 
    n2 = Square(n1); 
    cout << n1 << " squared is: " << n2 << endl; 
    return 0; 
}