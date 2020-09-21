/*
 * RockPaperScissors-V1.0 - Determines the game winner from Rock-Paper-Scissors
 * C++ version
 * Name: Jay Gupta
 * Date: 2/14/2020
 * Inputs: player1 and player2 as (R)ock, (P)aper, or (S)cissors
 * Output: the winner of the round
*/

#include <iostream>
using namespace std;

int main()
{
    char player1, player2;
    char playAgain = 'y';
    cout << endl << "Welcome to Rock, Paper, Scissors!!!" << endl; 
    cout << "---------------------------------------------------" << endl; 
    cout << "The rules are simple: paper beats rock, rock beats scissors, and scissors beats paper." << endl; 
    cout << "If both players throw the same thing, its a tie." << endl; 

    cout << endl << "Enter R for rock, P for paper, or S for scissors." << endl << endl;
    do {
        do {
            cout << "Player 1 (R, P, or S): ";
            cin >> player1;
            player1 = toupper(player1);
            if (player1 != 'R' && player1 != 'S' && player1 != 'P') {
                cout << endl << "Illegal selection, Player 1. Try again." << endl << endl;
            }
        } while (player1 != 'R' && player1 != 'S' && player1 != 'P');

        do {
            cout << "Player 2 (R, P, or S): ";
            cin >> player2;
            player2 = toupper(player2);
            if (player2 != 'R' && player2 != 'S' && player2 != 'P') {
                cout << endl << "Illegal selection, Player 2. Try again." << endl << endl;
            }
        } while (player2 != 'R' && player2 != 'S' && player2 != 'P');

        if (player1 == player2) {
            cout << endl << "Tie game, nobody wins." << endl;
        } else if (player1 == 'P') {
            if (player2 == 'R') {
                cout << endl << "Player 1 wins, paper beats rock." << endl;
            } else if (player2 == 'S') {
                cout << endl << "Player 2 wins, scissors beats paper." << endl;
            }
        } else if (player1 == 'R') {
            if (player2 == 'P') {
                cout << endl << "Player 2 wins, paper beats rock." << endl;
            } else if (player2 == 'S') {
                cout << endl << "Player 1 wins, rock beats scissors." << endl;
            }
        } else { // player1 is scissors
            if (player2 == 'R') {
                cout << endl << "Player 2 wins, rock beats scissors." << endl;
            } else if (player2 == 'P') {
                cout << endl << "Player 1 wins, scissors beats paper." << endl;
            }
        }

        cout << endl << "Do you want to play again? (Y)es or (any other key) for No: ";
        cin >> playAgain;
        playAgain = toupper(playAgain);
        cout << endl; // blank line between games
    } while (playAgain == 'Y');

    cout << "Thanks for playing. See you later!" << endl << endl;

    return 0;
}
