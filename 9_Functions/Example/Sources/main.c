/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 9,
 *          Funcitons.
 * Date: July 10, 2021
*/


#include <stdio.h>
#include <stdlib.h>


#define BUFFERSIZE 16


// Example global variable
int myGlobal = 0;

// Example function prototype/declaration
void add(void);

// Function prototype/declaration for arguments example
int multiplyTwoNumbers(int, int);

// Function prototype/declaration for global variable example
void myFunction(int);


// main function
int main(void) {

    // Defining a function:
    //  * void printMessage(void) {
    //  *     printf("Programming is weird.\n");
    //  * }
    // If the function body is empty,function MUST return
    //   void type.
    //
    // Function Prototypes are statements that define a function
    //   and are usually found in header files, so that you can easily
    //   use those functions in other files. It enables the compiler to
    //   generate the appropriate instructions at each point where you
    //   call the function. If there is no header file, only a singe source
    //   file, just place them at the top of the file.
    //   * void printMessage(void);    // Same as function header but with semi-colon

    // Example function call with declared prototype

    add();

    // When passing an array as an argument into a function you must also pass an
    //   additional argument specifying the size of the array, as the function
    //   has no means of knowing now many elements there are in the array.

    printf("Result %d\n", multiplyTwoNumbers(10, 20));

    int result = multiplyTwoNumbers(10, 30);
    printf("Result %d\n", result);

    // Global variables:
    //  * Must be declared outside of functions
    //  * Any function can change the value of a global variable
    //  * If there is a local variable declared in a function with the same name, then
    //      within that function the local variable with mask the global variable

    // Example function call with a global variable

    int myLocalMain = 0;    // local variable
    // can access myGlobal and myLocal

    printf("\n%d\n", myLocalMain);
    myFunction(13);


    return 0;
}

// Example function implimentation
void add(void) {
    printf("\nTest example function.\n");
    return;
}

// Arguments example function implimentation
int multiplyTwoNumbers(int x, int y) {
    int result = (x * y);
    printf("\nThe product of %d multiplied by %d is %d\n", x, y, result);
    return result;
}

// Function implimentation for global variable example
void myFunction(int y) {
    int x = y;    // local variable
    // can access myGlobal and x, cannot access myLocal

    printf("\n%d\n", x);
}
