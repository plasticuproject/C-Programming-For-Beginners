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

     // IF with an ELSE clause
    int number_to_test, remainder;
    char buffer[BUFFERSIZE];

    printf("\nEnter your number to be tested: ");
    fgets(buffer, BUFFERSIZE, stdin);

    number_to_test = atoi(buffer);
    remainder = number_to_test % 2;

    if (remainder == 0) printf("The number is even.\n");
    else printf("The number is odd.\n");


    return 0;
}
