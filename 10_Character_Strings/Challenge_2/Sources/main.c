/*
 * Author: plasticuproject
 * Purpose: Module 10 Challenge 2, Utilizing
 *          common string functions.
 * Date: August 2, 2021
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>            // isdigit(int c)

#include "s_new_from_stdin.c" // s_get_ahead(), s_get_exact()
                              // s_new_from_stdin(int beExact, size_t *len, size_t *size)


#define MAXSTRINGLEN 501      // Max length allowed for stringSort() arrays


// Function prototypes
char menu(void);
void stringReverse(char *arr, size_t len);
void stringSort(char arr[][MAXSTRINGLEN], int len);
void reverseProgram(void);
void sortProgram(void);


// main function
int main(void) {

    /*
     * Write a program that displays a string in reverse order
     *  * Should read input from the keyboard
     *  * Need to use the strlen() function
     *
     * Write a program that sorts the strings of an array using a bubble sort
     *  * Need to use the strcmp() and strcpy() functions
     *  * Input/Output should look at follows:
     *
     *    * Input number of strings: 3
     *    * Input string 3:
     *    * zero
     *    * one
     *    * two
     *
     *    * The strings appears after sorting:
     *    * one
     *    * two
     *    * zero
    */

    // Main program loop
    char menuChoice = '\0';

    do {
        menuChoice = menu();
        switch(menuChoice) {
            case ('1'): {
                printf("\nThis program will reverse the order of a user supplied string.\n");
                reverseProgram();
                menuChoice = '\0';
                break;
            }
            case ('2'): {
                printf("\nThis program will sort a user supplied list of strings, each up to 500 characters long.\n");
                sortProgram();
                menuChoice = '\0';
                break;
            }
            default: {
                printf("\nINVALID CHOICE\n");
                break;
            }
        }
    } while (menuChoice != '\0');

    return 0;
}


// Menu function
char menu(void) {

    char *buff;
    char choice;
    size_t buffLen = 0;

    printf("\nChoose program to run.\n\n[1] STRING REVERSE\n[2] STRING SORT\n");
    printf("\nEnter '1' or '2': ");
    buff = s_new_from_stdin(1, &buffLen, NULL);
    if (buffLen > 1) { choice = '3'; }
    else { choice = buff[0]; }
    free(buff);
    buff = NULL;

    return choice;
}


// Program to run stringReverse()
void reverseProgram(void) {

    char *buff;
    size_t stringLength;

    printf("\nEnter string to reverse: ");
    buff = s_new_from_stdin(1, &stringLength, NULL);
    stringReverse(buff, stringLength);
    printf("\nREVERSED: %s\n", buff);
    free(buff);
    buff = NULL;
}


// Program to run stringSort()
void sortProgram(void) {

    int stringNumber;
    size_t buffStringLen = 0;
    char *buff;

    while (1) {
        printf("\nEnter number of strings(1-100): ");
        buff = s_get_exact();
        if (isdigit(*buff) && (atoi(buff) > 0) && (atoi(buff) < 101)) {
            stringNumber = atoi(buff);
            free(buff);
            buff = NULL;
            char stringsToSort[stringNumber][MAXSTRINGLEN];
            for (int i = 0; i < stringNumber; i++) {
                printf("Input  String %d: ", (i + 1));
                buff = s_new_from_stdin(1, &buffStringLen, NULL);
                if (buffStringLen < MAXSTRINGLEN) {
                    strncpy(stringsToSort[i], buff, (buffStringLen + 1));
                }
                else {
                    printf("\nINVALID INPUT: Your string is too long.\n\n");
                    i--;
                }
                free(buff);
                buff = NULL;
            }
            stringSort(stringsToSort, stringNumber);
            printf("\nSORTED:");
            for (int i = 0; i < stringNumber; i++) {
                printf("\nOutput String %d: %s", (i + 1), stringsToSort[i]);
            }
            break;
        }
        else { printf("\nINVALID INPUT\n"); }
    }
    printf("\n");
}


// Function to reverse string
void stringReverse(char *arr, size_t len) {

    int count = 0;
    char buff[len + 1];

    for (int i = (len - 1); i >= 0; i--) {
        buff[count] = arr[i];
        count++;
    }
    for (int i = 0; i < len; i++) {
        arr[i] = buff[i];
    }
}


// Function to bubble sort strings
void stringSort(char arr[][MAXSTRINGLEN], int len) {

    char buffer[MAXSTRINGLEN];

    for (int j = 0; j < (len - 1); j++) {
        for (int i = 0; i < (len - 1); i++) {
            if (strcmp(arr[i], arr[i +1]) > 0) {
                strncpy(buffer, arr[i + 1], strlen(arr[i + 1]));
                memset(arr[i + 1], '\0', strlen(arr[i + 1]));
                strncpy(arr[i + 1], arr[1], strlen(arr[1]));
                memset(arr[1], '\0', strlen(arr[1]));
                strncpy(arr[1], buffer, strlen(buffer));
                memset(buffer, '\0', strlen(buffer));
            }
        }
    }
}
