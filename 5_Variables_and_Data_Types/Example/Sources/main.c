/*
 * Author: plasticuproject
 * Purpose: Basic data types example
 * Date: June 25, 2021
 */

#include <stdio.h>
#include <stdbool.h> // C99 bool type

#define BUFFERSIZE 10

// argc is the argument count
// argv is the vector, an array of character pointers (strings)
int main(int argc, char* argv[]) {


    // Playing with commandline arguments
    int numberOfArguments = argc;
    char* programName = argv[0];

    printf("\nNumber of Aruguments: %d\n", numberOfArguments);
    printf("Program Name: %s\n", programName);

    for (int index = 1; index < argc; index++) {
        char* argumentForPrint = argv[index];
        printf("Argument %d: %s\n", index, argumentForPrint);
    }


    // Storing some basic data types
    signed int integerVar = 100;
    signed short int shortIntegerVar = 100;
    unsigned int unsignedIntegerVar = 100;
    unsigned short int unsignedShortIntegerVar = 100;
    float floatingVar = 331.79f;
    double doubleVar = 8.44e+11;
    _Bool boolVar = 0;
    bool c99BoolVar = true;


    // Printing the data
    printf("\nInteger: %d | Size: %lu bytes\n", integerVar, sizeof(integerVar));
    printf("Short Integer: %d | Size: %lu bytes\n", shortIntegerVar, sizeof(shortIntegerVar));
    printf("Unsigned Integer: %d | Size: %lu bytes\n", unsignedIntegerVar, sizeof(unsignedIntegerVar));
    printf("Unsigned Short Integer: %d | Size: %lu bytes\n", unsignedShortIntegerVar, sizeof(unsignedShortIntegerVar));
    printf("Float: %.2f | Size: %lu bytes\n", floatingVar, sizeof(floatingVar));
    printf("Double: %e | Size: %lu bytes\n", doubleVar, sizeof(doubleVar));
    printf("Double: %g | Size: %lu bytes\n", doubleVar, sizeof(doubleVar));
    printf("Boolean: %d | Size: %lu bytes\n", boolVar, sizeof(boolVar));
    printf("C99 Boolean: %d | Size: %lu bytes\n", c99BoolVar, sizeof(c99BoolVar));


    // Playing with Enum
    enum speed { none, slow = 2, medium = 5, fast = 10 };
    enum speed stopped, walking, jogging, running;
    stopped = none, walking = slow, jogging = medium, running = fast;

    int mySpeed = stopped;
    mySpeed = walking + jogging + running;

    printf("\nMy Speed: %d | Size: %lu bytes\n", mySpeed, sizeof(mySpeed));

    // Playing with Char
    char broiled = 'T';

    printf("Here is a char: %c | Size: %lu bytes\n", broiled, sizeof(broiled));


    // Playing with fgets and standard input
    char buffer[BUFFERSIZE];
    char *userInput;
    printf("Enter a string: ");
    userInput = fgets(buffer, BUFFERSIZE, stdin);
    printf("This is the string you entered: %s\n", userInput);


    return 0;
}
