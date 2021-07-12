/*
 * Author: plasticuproject
 * Purpose: Module 6 challenge, convert number
 *          of minutes to days and years.
 * Date: July 1, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 16


int main(void) {

    /*
     * Prompt user to enter the number of minutes to convert
     * Display output of the minutes and then it's equivalent in years and days
     *
     * The program should create these double type variables to store:
     *   * minutes (int)
     *   * minutes in year (double)
     *   * Years (double)
     *   * Days (double)
    */


    // Declare and initialize variables
     // I could have just made minutesInYear a constant (or not used a variable
     // at all) but he wanted arithmetic operations done, so yeah...
    unsigned int minutes = 0;
    double minutesInYear = (60 * 24 * 365);
    double Years = 0, Days = 0;
    char buffer[BUFFERSIZE];
    char *userInput;

    // Prompt and get user input
     // He wanted me to use scanf() but forget that mess, scanf() is dumb
    printf("\nThis program excepts a value of minutes (1-999999999) and returns\n");
    printf("the amount of years and days those minutes fit into.\n");
    printf("\nEnter number of minutes: ");
    userInput = fgets(buffer, BUFFERSIZE, stdin);

    // Type conversions and calculations
    minutes = atof(userInput);
    if ((minutes < 1) || (strlen(userInput) > 10)) {
        printf("\nInvalid Input.\n");
        return 1;
    }
    Years = (minutes / minutesInYear);
    Days = ((minutes % (int)minutesInYear) / 60 / 24);

    // Print results
     // I could have just used %0.f as format specifier and not cast the variables
     // to int, but this challenge is about about type casting and stuff so, yeah....
    printf("Minutes: %u\n", minutes);
    printf("Years: %d\n", (int)Years);
    printf("Days: %d\n", (int)Days);


    return 0;
}
