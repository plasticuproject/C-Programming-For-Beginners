/*
 * Author: plasticuproject
 * Purpose: Module 6 challenge, display byte sizes of
 *          basic data types.
 * Date: July 1, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BUFFERSIZE 16


int main(void) {

    /*
     * Display byte sizes of basic data types supported in C.
     *
     * Display the bye size of the following types:
     *   * int
     *   * char
     *   * long
     *   * long long
     *   * double
     *   * long double
     *
     * Use the %zd format specifier for each size
     *
     * Use sizeof() operator
     *
     * Test on more than one computer to see the differences
    */


    printf("\nINT type for 1 is: .........%zd bytes\n", sizeof((int)1));
    printf("CHAR type for 'A' is: ......%zd bytes\n", sizeof((char)'A'));
    printf("LONG type for 1 is: ........%zd bytes\n", sizeof((long)1));
    printf("LONG LONG type for 1 is: ...%zd bytes\n", sizeof((long long)1));
    printf("DOUBLE type for 1 is: ......%zd bytes\n", sizeof((double)1));
    printf("LONG DOUBLE type for 1 is: %zd bytes\n", sizeof((long double)1));


    return 0;
}
