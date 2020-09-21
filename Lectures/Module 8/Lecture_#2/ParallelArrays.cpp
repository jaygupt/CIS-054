#include <iostream>	// used for cin and cout
#include <cstring>	// used for _stricmp()
using namespace std;

int main(int argc, char* argv[])
{
    char *Abbrev[] = {
	    "AL","AK","AZ","AR","CA","CO","CT","DE","FL","GA","HI","ID","IL","IN",
            "IA","KS","KY","LA","ME","MD","MA","MI","MN","MS","MO","MT","NE","NV",
            "NH","NJ","NM","NY","NC","ND","OH","OK","OR","PA","RI","SC","SD","TN",
            "TX","UT","VT","VA","WA","WV","WI","WY"
	};

    char *States[] = {
	    "Alabama","Alaska","Arizona","Arkansas","California","Colorado",
	    "Connecticut","Delaware","Florida","Georgia","Hawaii","Idaho",
	    "Illinois","Indiana","Iowa","Kansas","Kentucky","Louisiana","Maine",
	    "Maryland","Massachusetts","Michigan","Minnesota","Mississippi",
	    "Missouri","Montana","Nebraska","Nevada","New Hampshire","New Jersey",
	    "New Mexico","New York","North Carolina","North Dakota","Ohio",
	    "Oklahoma","Oregon","Pennsylvania","Rhode Island","South Carolina",
	    "South Dakota","Tennessee","Texas","Utah","Vermont","Virginia",
	    "Washington","West Virginia","Wisconsin","Wyoming"
	};

    char userRequest[10]; 
    int i; 
    int arraySize = sizeof(Abbrev) / sizeof(char *); 
    cout << arraySize << " " << sizeof(States) / sizeof(char *) << endl << endl; 

    // get first user entry 
    cout << "Enter state abbreviation (example CA) or \"Exit\" to quit: "; 
    cin.getline (userRequest, 10); 

    while (_stricmp(userRequest, "Exit") != 0) { // loop until exit is entered 
        for (i = 0; i < arraySize; i++) {
            if (_stricmp(userRequest, Abbrev[i]) == 0) {
                cout << States[i] << endl << endl; 
                break; 
            }
        }
        if (i == arraySize) {
            cout << "Not Found" << endl << endl; 
        }

        // get next user entry 
        cout << "Enter state abbreviation (example CA) or \"Exit\" to quit: "; 
        cin.getline(userRequest, 10); 
    }

    return 0; 
}