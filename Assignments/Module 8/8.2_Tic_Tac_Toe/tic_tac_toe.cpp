// Program Name: tic_tac_toe.cpp
// Name: Jay Gupta
// Class: CIS 054 C/C++ Programming
// Date: 3/24/2020
// Version: 1.0

#include <iostream> // cin and cout 
#include <ctime> // time function 
using namespace std; 

void displayTicTacToe(char board[3][3]); 
char checkForWinningGame(char board[3][3]);

int main() {
    char board[3][3] = {
        {'1', '2', '3'}, 
        {'4', '5', '6'}, 
        {'7', '8', '9'}
    }; 

    int squareCounter = 0; // count how many squares are used; to determine a tie
    char gameWinner = '-'; // winner of the game ('X', 'O', or none)
    char inputCharacter; // input from the user (from '1' to '9')
    int choice; // input converted to integer from 0 to 8, as an array starts at 0
    char player; // current player, 'X' or 'O'

    // select starting player 
    srand((unsigned int) time(NULL)); // seed random number generator  
    if (rand() % 2 == 1) {
        player = 'X'; 
    } else {
        player = 'O'; 
    }

    // starting instructions 
    cout << "Enter a number from 1 to 9 to select a square." << endl; 

    // ask for 1-9 until all squares are filled, or there is a winner
    while (squareCounter < 9 && gameWinner != 'X' && gameWinner != 'O') {
        cout << "--------------------------------" << endl;
        displayTicTacToe(board); 
        cout << "Player " << player << ", enter a number (1-9): "; 
        cin >> inputCharacter; 

        // convert inputCharacter to integer from 0 to 8
        choice = inputCharacter - '1'; 
        int row = choice / 3; 
        int col = choice % 3; 

        if (choice < 0 || choice > 8) {
            cout << "Illegal value, try again." << endl; 
        } else if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "This space has already been used, try again." << endl; 
        } else {
            board[row][col] = player; // put player's character at the specified spot 
            squareCounter++; 

            // select the next player 
            if (player == 'X') {
                player = 'O'; 
            } else {
                player = 'X'; 
            }
        }
        gameWinner = checkForWinningGame(board); 
    }

    // someone has won or there has been a tie
    displayTicTacToe(board); 
    cout << endl;  
    if (gameWinner == 'X' || gameWinner == 'O') {
        cout << "Congratulations player " << gameWinner << ". You win the game." << endl << endl;  
    } else {
        cout << "Tie game." << endl << endl; 
    }

    return 0; 
}

// displays the current board 
void displayTicTacToe(char board[3][3]) {
    cout << endl; 
    cout << "-----------------" << endl; 
    cout << "-----------------" << endl;  
    cout << "   TIC TAC TOE   " << endl; 
    cout << "-----------------" << endl; 
    cout << "-----------------" << endl;
    cout << endl; 
    
    cout << "     |     |     " << endl; 
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (col == 1) {
                cout << " |  " << board[row][col] << "  |";
            } else {
                cout << "  " << board[row][col] << " ";
            }
        }
        if (row == 0 || row == 1) {
            cout << endl << "     |     |     "; 
            cout << endl << "-----|-----|-----";
            cout << endl << "     |     |     "; 
        }

        cout << endl; 
    }
    cout << "     |     |     " << endl;

    cout << endl; 
}

// returns 'X' or 'O' for winner 
// or '-' for no winner 
char checkForWinningGame(char board[3][3]) {
    char player; 

    // across top row 
    player = board[0][0]; 
    if (board[0][1] == player && board[0][2] == player) {
        return player; 
    }

    // across middle row 
    player = board[1][0]; 
    if (board[1][1] == player && board[1][2] == player) {
        return player; 
    }

    // across bottom row 
    player = board[2][0]; 
    if (board[2][1] == player && board[2][2] == player) {
        return player; 
    }

    // down first column 
    player = board[0][0]; 
    if (board[1][0] == player && board[2][0] == player) {
        return player; 
    }

    // down second column 
    player = board[0][1]; 
    if (board[1][1] == player && board[2][1] == player) {
        return player; 
    }

    // down third column 
    player = board[0][2]; 
    if (board[1][2] == player && board[2][2] == player) {
        return player; 
    }

    // left diagonal (\)
    player = board[0][0]; 
    if (board[1][1] == player && board[2][2] == player) {
        return player; 
    } 

    // right diagonal (/)
    player = board[0][2]; 
    if (board[1][1] == player && board[2][0] == player) {
        return player; 
    }

    // if there's no winner
    return '-'; 
}