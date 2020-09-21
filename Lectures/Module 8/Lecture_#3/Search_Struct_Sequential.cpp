#include <iostream>
#include <cstring>	// used for _stricmp()
using namespace std;

typedef struct S_STATE_LIST {
    char StateName[15]; 
    char Abbreviation[3]; 
} States; 

States StateList [] = {
    {"Alabama", "AL"}, {"Alaska", "AK"}, {"Arizona", "AZ"}, {"Arkansas", "AR"},
    {"California", "CA"}, {"Colorado", "CO"}, {"Connecticut", "CN"}, {"Delaware", "DE"},
    {"Florida", "FL"}, {"Georgia", "GA"}, {"Hawaii", "HI"}, {"Idaho", "ID"},
    {"Illinois", "IL"}, {"Indiana", "IN"}, {"Iowa", "IA"}, {"Kansas", "KS"},
    {"Kentucky", "KY"}, {"Louisiana", "LA"}, {"Maine", "ME"}, {"Maryland", "MD"},
    {"Massachusetts", "MA"}, {"Michigan", "MI"}, {"Minnesota", "MN"},
    {"Mississippi", "MS"}, {"Missouri", "MO"}, {"Montana", "MT"}, {"Nebraska", "NE"},
    {"Nevada", "NV"}, {"New Hampshire", "NH"}, {"New Jersey", "NJ"}, {"New Mexico", "NM"},
    {"New York", "NY"}, {"North Carolina", "NC"}, {"North Dakota", "ND"}, {"Ohio", "OH"},
    {"Oklahoma", "OK"}, {"Oregon", "OR"}, {"Pennsylvania", "PA"}, {"Rhode Island", "RI"},
    {"South Carolina", "SC"}, {"South Dakota", "SD"}, {"Tennessee", "TN"}, {"Texas", "TX"},
    {"Utah", "UT"}, {"Vermont", "VT"}, {"Virginia", "VA"}, {"Washington", "WA"},
    {"West Virginia", "WV"}, {"Wisconsin", "WI"}, {"Wyoming", "WY"}
}; 

int main(int argc, char* argv[]) {
    int i; 
    int length = 50; 

    char Selection[10]; 
    cout << "Enter the state abbreviation: "; 
    cin >> Selection; 

    // Sequential Search
    for (i = 0; i < length; i++) {
        if ( _stricmp(Selection, StateList[i].Abbreviation) == 0) {
            cout << StateList[i].StateName << endl;  
            break; 
        }
    }

    if (i == length) {
        cout << "Not Found" << endl; 
    }

    return 0; 
}

