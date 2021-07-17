/*
 * Author: plasticuproject
 * Purpose: Module 9 challenge 2, create
 *          a Tic Tac Toe Game.
 * Date: July 14, 2021
*/


#include <stdio.h>
#include <string.h>            // strlen()

#include "s_new_from_stdin.c"  // s_get_ahead()


// Function declarations
_Bool checkForWin(int turn, _Bool player, char *board);
void drawBoard(char *board);
char markBoard(_Bool player, char *board);
int getPlayerMove(_Bool player);


// Main function
int main(void) {

    /*
     * Write a program that plays tic-tac-toe
     *  * Game is played on a 3x3 grid and by two players who take turns
     *
     * Create an array to represent the board
     *  * can be of type char and consist of 10 elements (do not use zero)
     *  * each element represents a coordinate on the board that the use can select
     *
     * Some functions that you should probably create
     *  * checkForWin - checks to see if a player has won or the game is a draw
     *  * drawBoard   - redraws the board for each player turn
     *  * markBoard   - sets the char array with a selection and check for an invalid
     *                  selection.
     *
     * Example output:
     *
     * *         Tic Tac Toe
     * *
     * * Player 1 (x) - Player 2 (O)
     * *
     * *    |   |
     * *  1 | 2 | 3
     * * ___|___|___
     * *    |   |
     * *  4 | 5 | 6
     * * ___|___|___
     * *    |   |
     * *  7 | 8 | 9
     * *    |   |
     * *
     * * Player 1, enter a number:
     *
    */

    // Initialize board and variables to track board state, players and turn count
    char boardArray[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    _Bool playerTurn = 1;
    int turnCount = 2;

    // Main game loop
    while (checkForWin(turnCount, playerTurn, boardArray)) {
        playerTurn = (playerTurn == 0) ? 1 : 0;
        printf("\e[1;1H\e[2J");    // clear screen
        drawBoard(boardArray);
        *boardArray = markBoard(playerTurn, boardArray);
        turnCount++;
    }

    // Game over
    printf("\e[1;1H\e[2J");    // clear screen
    drawBoard(boardArray);
    if (turnCount == 11) { printf("\n\nIT'S A TIE!!\n\n"); }
    else { printf("\n\nPLAYER %c WINS!!!\n\n", (playerTurn == 0) ? '1' : '2'); }

    return 0;
}


// Draw the playing board
void drawBoard(char *board) {

    printf("\n\tTic Tac Toe\n");
    printf("\nPlayer 1 (X) - Player 2 (O)\n\n");
    printf("   |   |\n");
    printf(" %c | %c | %c\n", board[1] ,board[2] ,board[3]);
    printf("___|___|___\n");
    printf("   |   |\n");
    printf(" %c | %c | %c\n", board[4] ,board[5] ,board[6]);
    printf("___|___|___\n");
    printf("   |   |\n");
    printf(" %c | %c | %c\n", board[7] ,board[8] ,board[9]);
    printf("   |   |\n");

}

// Get user input, run validity checks and return index number for board array
int getPlayerMove(_Bool player) {

    char *move;
    _Bool loopControl = 1, errorControl = 0;
    char validInput[9] = "123456789";
    int moveInteger = 0;
    char playerNumber = player == 0 ? '1' : '2';

    // Loop until valid input char is received, return as int
    do {
        if (errorControl) { printf("\nINVALID INPUT"); }
        printf("\nPlayer %c, enter a number: ", playerNumber);
        move = s_get_ahead();    // get player input safely
        if (strlen(move) < 2) {
            for (int i = 0; i < 9; i++) {
                if (move[0] == validInput[i]) {
                    loopControl = 0;
                    moveInteger = move[0] - '0';
                }
            }
        }
        errorControl = 1;
    } while (loopControl);
    free(move);

    return moveInteger;
}

// Process player input and update board array
char markBoard(_Bool player, char *board) {

    int location = 0;
    _Bool loopControl = 1;
    char mark = (player == 1) ? 'O' : 'X';

    do {
        while (location == 0) {
            location = getPlayerMove(player);
        }
        if ((board[location] == 'X') || (board[location] == 'O')) {
            printf("\nLocation occupied, choose a different location.");
            location = 0;
        }
        else { loopControl = 0; }
    } while (loopControl);
    board[location] = mark;

    return *board;
}

// Checks current board array against possible winning states
_Bool checkForWin(int turn, _Bool player, char *board) {

    _Bool running = 1;
    char playerChar = (player == 0) ? 'X' : 'O';
    int count = 0;
    char boardCopy[10] = { '0' };
    char winningStates[16][10] = {    // Homogenized array of winning board states
        "0XXX000000", "0OOO000000",
        "0000XXX000", "0000OOO000",
        "0000000XXX", "0000000OOO",
        "0X00X00X00", "0O00O00O00",
        "00X00X00X0", "00O00O00O0",
        "000X00X00X", "000O00O00O",
        "0X000X000X", "0O000O000O",
        "000X0X0X00", "000O0O0O00"
    };

    // Copy current board state and homogenize for compairison
    for (int i = 0; i < 10; i++) {
        boardCopy[i] = board[i];
        if (boardCopy[i] != playerChar) {
            boardCopy[i] = '0';
        }
    }

    // Loop through board array and winning states, counting matches
    // If enough matches are found return 0 to stop loop in main funciton
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 10; j++) {
            if ((winningStates[i][j] == boardCopy[j]) && boardCopy[j]  == playerChar) {
                count++;
            }
        }
        if (count > 2) { running = 0; }
        count = 0;
    }
    if (turn == 11) { running = 0; }    // Check for tie game

    return running;
}
