/*
 * Author: plasticuproject
 * Purpose: This program prints out my name to the screen.
 * Date: June 23, 2021
*/

#include <stdio.h>

int main(void) {
    // this code is displaying my name 
    char name[100];
    int number;
    printf("What is your name and number: ");
    scanf("%s %d", name, &number);
    printf("\nHello %s, number: %d\n", name, number);
    return 0;
}
