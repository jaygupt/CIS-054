#include <iostream>
using namespace std; 

int main() 
{
    enum TrafficEnum {RED, YELLOW, GREEN}; 
    typedef TrafficEnum trafficLight; 

    trafficLight SouthSt; // create a new data type 
    SouthSt = GREEN; // Assign a value to SouthSt

    if (SouthSt == GREEN) 
        cout << "The light is GREEN" << endl; 
    cout << "The numeric value is " << SouthSt << endl; 
    return 0; 
} // end of main