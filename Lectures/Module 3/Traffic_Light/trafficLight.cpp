#include <iostream>
using namespace std; 
 
char light; 

int main() {
    do {
        cout << "Enter R, Y, or G for red, yellow, or green light. Q to quit: "; 
        cin >> light; 
        light = toupper(light); 
        
        switch (light) {
               case 'R': 
                    cout << "STOP" << endl; 
                    break; 
               case 'Y': 
                    cout << "CAUTION" << endl; 
                    break; 
               case 'G': 
                    cout << "GO" << endl; 
                    break; 
               case 'Q': 
                    break; // the 'Q' will be processed by the while statement 
               default:
                    cout << "Illegal selection. Try again." << endl; 
               }
        } while (light != 'Q'); 
    cout << "Bye!" << endl; 
    system("pause"); 
    return 0; 
}
 
