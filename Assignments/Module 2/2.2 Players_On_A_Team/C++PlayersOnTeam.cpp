// C++PlayersOnTeam.cpp
/*
MaxPlayers - this program determines if there are
not enough, too many, or just the right amount of
players on the team
*/
// Jay Gupta
// 2/8/2020 
// CIS 054 C/C++ Programming

#include <iostream>
using namespace std;

int main()
{
    // declare the variables
    int teamSize;
    int playersOnTeam;
    int morePlayersNeeded; 
    int playersToBeCut; 

    // get input; ideal # of players, and how many in reality 
    cout << "How many players should be on the team? ";
    cin >> teamSize;
    if (cin.fail()) {
        cout << "Illegal entry for team size." << endl;
        return 1;
    } else if (teamSize < 0) {
        cout << "Negative values aren't allowed." << endl;
        return 1;
    }

    cout << "How many players are actually on the team? ";
    cin >> playersOnTeam;
    if (cin.fail()) {
        cout << "Illegal entry for players on the team." << endl;
        return 1;
    } else if (playersOnTeam < 0) {
        cout << "Negative values aren't allowed." << endl;
        return 1;
    }
    
    // are the # of players less than, greater than, or equal to the ideal?
    // compute and display the respective output 
    if (playersOnTeam < teamSize) {
        cout << "There are not enough players." << endl; 
        morePlayersNeeded = teamSize - playersOnTeam; 
        cout << morePlayersNeeded << " players are needed." << endl;  
    } else if (playersOnTeam > teamSize) {
        cout << "There are too many players." << endl; 
        playersToBeCut = playersOnTeam - teamSize; 
        cout << playersToBeCut << " players need to be cut from the team." << endl; 
    } else {
        cout << "The amount of players is just right!" << endl; 
    }
    return 0;
}
