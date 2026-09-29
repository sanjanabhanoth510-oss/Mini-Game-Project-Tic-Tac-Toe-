// Tic-Tac-Toe Game
// A two-player console game in C++ using a 2D array, loops and conditions.

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;

// Reads one line of input. Exits cleanly if the input stream ends.
string readLine(const string &prompt) {
    string line;
    cout << prompt;
    if (!getline(cin, line)) {
        cout << "\nInput ended. Exiting game.\n";
        exit(0);
    }
    return line;
}

// Fills the board with the numbers '1' to '9' so players can see the positions.
void initializeBoard(char board[SIZE][SIZE]) {
    char number = '1';
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = number;
            number++;
        }
    }
}

// Prints the current board.
void displayBoard(char board[SIZE][SIZE]) {
    cout << "\n";
    for (int row = 0; row < SIZE; row++) {
        cout << "  " << board[row][0] << " | " << board[row][1] << " | "
             << board[row][2] << "\n";
        if (row < SIZE - 1) {
            cout << " ---+---+---\n";
        }
    }
    cout << "\n";
}

// Keeps asking until the player enters a single digit from 1 to 9.
int readPosition(char player) {
    while (true) {
        string input = readLine(string("Player ") + player + ", enter position (1-9): ");
        if (input.length() == 1 && input[0] >= '1' && input[0] <= '9') {
            return input[0] - '0';
        }
        cout << "Invalid input. Please enter a number from 1 to 9.\n";
    }
}

// Places the player's symbol on the board.
// Returns false if the position is already taken.
bool makeMove(char board[SIZE][SIZE], int position, char player) {
    int row = (position - 1) / SIZE;
    int col = (position - 1) % SIZE;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    board[row][col] = player;
    return true;
}

// Returns true if the given player has three in a row, column or diagonal.
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check all rows and all columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check both diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Returns true if every position is filled (no numbers left on the board).
bool checkDraw(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Plays one full game of Tic-Tac-Toe.
void playGame() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';

    initializeBoard(board);

    while (true) {
        displayBoard(board);
        int position = readPosition(currentPlayer);

        if (!makeMove(board, position, currentPlayer)) {
            cout << "That position is already taken. Try again.\n";
            continue;  // same player plays again
        }

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            return;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            return;
        }

        // Switch to the other player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
}

// Asks whether the players want another game. Keeps asking until y or n.
bool askReplay() {
    while (true) {
        string answer = readLine("\nDo you want to play again? (y/n): ");
        if (answer == "y" || answer == "Y") {
            return true;
        }
        if (answer == "n" || answer == "N") {
            return false;
        }
        cout << "Invalid input. Please enter y or n.\n";
    }
}

int main() {
    bool playAgain = true;

    while (playAgain) {
        cout << "\n========================================\n";
        cout << "            TIC-TAC-TOE GAME\n";
        cout << "========================================\n";
        cout << "Player 1: X\n";
        cout << "Player 2: O\n";

        playGame();
        playAgain = askReplay();
    }

    cout << "\nThanks for playing!\n";
    return 0;
}
