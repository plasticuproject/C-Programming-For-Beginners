/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 7,
 *          Control Flow.
 * Date: July 2, 2021
*/


#include <stdio.h>
#include <stdlib.h>


#define BUFFERSIZE 8


int main(void) {

    // IF statements
    int score = 95, big = 90;

     // simple statement no brackets
    if (score > big)
        printf("\nJackpot!\n");

     // compound statement
    if (score > big) {
        score++;
        printf("\nYou win\n");
    }

     // IF, ELSE and TERNARY
    int number_to_test, remainder;
    char buffer[BUFFERSIZE];
    char* your_status = NULL;

    printf("\nEnter your number to be tested: ");
    fgets(buffer, BUFFERSIZE, stdin);

    number_to_test = atoi(buffer);
    remainder = number_to_test % 2;

    if (remainder == 0) { printf("The number is even.\n"); }
        if (atoi(buffer) == 2) { printf("And that's my favorite number!\n"); }
    else if (atoi(buffer) == 13) { printf("That's an unlucky number!\n"); }
    else { printf("The number is odd.\n"); }

      // Ternary min/max 2 variables
    your_status = atoi(buffer) == 2 ? "You are awesome!" : "You suck.";
    printf("\n%s\n", your_status);

    // SWITCH/CASE/DEFAULT
     // When the value of a variable is successively compared against differnt values
    enum Weekend {Friday, Saturday, Sunday};
    enum Weekend today = Saturday;

    switch (today) {
        case Saturday:
            printf("\nToday is Saturday.\n");
            break;
        case Sunday:
            printf("\nToday is Sunday.\n");
            break;
        default:
            printf("\nMeh.\n");
            break;
    }


    return 0;
}
