#include <iostream>
using namespace std; 

int main() {
    double averageScore, totalScore; 
    int participants; 
    
    cout << "Enter the total score: "; 
    cin >> totalScore; 
    
    cout << "Enter the number of participants: "; 
    cin >> participants; 
    cout << endl; 
    
    try {
        if (participants < 1) {
           throw 0; 
        }
        averageScore = totalScore / participants; 
        cout << "The average score is: " << averageScore << endl; 
    }
    catch (int errID) {
          cerr << "Error: " << errID << endl; 
          cerr << "The number of participants can't be less than 1." << endl; 
    }
    system("pause"); 
    return 0; 
}
   
