#include <iostream>
using namespace std; 

void greetings(); 
int get_number(); 
float average(const float val1, const float val); 

int main() {
    float bob, sue, the_average; 
    greetings(); 
    bob = get_number(); 
    sue = get_number(); 
    the_average = average (bob, sue); 
    cout << the_average; 
    return 0; 
}

float average (const float val1, const float val2) {
    return (val1 + val2) / 2; 
}

int get_number() {
    int value; 
    cout << "Enter an integer: "; 
    cin >> value; 
    return value; 
}

void greetings() {
    cout << "Hello to my world!" << endl; 
    return; 
}