#include <iostream> 
#include <fstream> 
using namespace std; 

int main() {
    char filename[] = "Balances.txt"; 
    int acct; 
    char name[100] = ""; 
    double bal; 
    double total = 0; // to accumulate sum of ALL balances 
    ifstream infile(filename); 

    if (infile.good() == false) {
        cout << "Unable to open " << filename << endl << endl; 
        system("PAUSE"); 
        return 1; 
    }

    infile >> acct >> name >> bal; // read first record 
    while (!infile.eof()) {
        cout << acct << '\t' << name << '\t' << bal << endl; 
        infile >> acct >> name >> bal; // read next record 
    }
    infile.close(); // close the file when the end is reached

    system("PAUSE"); 
    return 0; // exit the program 
}