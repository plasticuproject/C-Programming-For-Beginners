/*
 * Author: plasticuproject
 * Purpose: Module 7 challenge, guess the
 *          number program.
 * Date: July 6, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define BUFFERSSIZE 8
#define GUESS_COUNT 5
#define LOW_RANGE 0
#define HIGH_RANGE 20


// Main function
int main(void) {

    /*
     * Create a guess the number program.
     *
     * Program will generate a random number from 0 to 20
     *  * User should only be able to enter numbers from 1-20
     *
     * The program will indicate to the user if the guess is too high or low
     * The play wins the game if they can guess the number in 5 tries
     *
     * Output should look as follows:
     *
     *  * This is a guessing game.
     *  * I have chosen a number between 0 and 20 which you must guess.
     *  *
     *  * You have 5 tries left.
     *  * Enter a guess: 12
     *  * Sorry, 12 is wrong. My number is less than that.
     *  *
     *  * ...
     *  *
     *  * You have 2 tries left.
     *  * Enter a guess: 2
     *  *
     *  * Congratulations. You guessed it!
    */


    // Generate random number seed via time (code provided from challenge)
    time_t t;
    srand((unsigned)time(&t));

    // Introduction
    printf("\nThis is a guessing game.\n");
    printf("I have chosen a number between %d and %d which you must guess.\n", LOW_RANGE, HIGH_RANGE);

    // Initialize random number
    int randomNumber = rand() % (HIGH_RANGE + 1);

    // Declare and/or initialize remaining local variables needed
    char buffer[BUFFERSSIZE];
    int maxLength = 1;
    int userGuess;
    int guessCount = GUESS_COUNT;

    // Determine number of digits in HIGH_RANGE to avoid overflow
    for(int n = HIGH_RANGE; n != 0; n /= 10) { maxLength++; }

    // Main loop logic
    while(guessCount > 0) {    // keeps track the number of user guesses

        // Give user how many tries remaining and prompt for input
        printf("\nYou have %d tries left.\n", guessCount);
        printf("Enter a guess: ");
        fgets(buffer, BUFFERSSIZE, stdin);
        userGuess = atoi(buffer);

        // Make sure input length is in bounds
        if(strlen(buffer) > maxLength) {
            printf("Invaild guess, stay in range %d - %d.\n", LOW_RANGE, HIGH_RANGE);
            continue;
        }

        // Check user input is in range, if so do:
        if((userGuess >= LOW_RANGE) && (userGuess <= HIGH_RANGE)) {
            guessCount--;    // decrement guessCount only if input is in range

            // If user guesses correctly, break out of loop
            if(userGuess == randomNumber) {
                printf("\nCongratulations. You guessed it!\n");
                break;
            }

            // If user guess is higher than randomNumber, do:
            else if(userGuess > randomNumber) {
                printf("Sorry, %d is wrong. My number is less than that.\n", userGuess);
            }

            // If user guess is lower than randomNumber, do:
            else if(userGuess < randomNumber) {
                printf("Sorry, %d is wrong. My number is more than that.\n", userGuess);
            }
        }

        // If user input is out of range, print this and restart iteration
        else {
            printf("Invaild guess, stay in range %d - %d.\n", LOW_RANGE, HIGH_RANGE);
            continue;
        }
    }

    // if user guessed incorrect HIGH_RANGE times, tell them they lost and quit
    if((guessCount == 0) && (userGuess != randomNumber)) {
        printf("\nSorry, you loose. The number was %d\n", randomNumber);
    }


    return 0;
}
