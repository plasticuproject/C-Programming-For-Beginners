/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 10,
 *          Character Strings.
 * Date: July 17, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_new_from_stdin.c"    // s_get_ahead()


// main function
int main(void) {

    // Character/String stuff
    char word[] = "You are a C god.";
    printf("\n%s\n", word);
    printf("%lu\n", strlen(word));    // 16 characters long
    printf("%lu\n", sizeof(word));    // 17 bytes long (includes null byte \0)

    // Constant Strings
    //  * Make sure the variable cannot be changed
    // #define MONTHS 12  // preprocessor directive, subbed at/before compile time
    // const int MONTHS = 12;  // symbolic constant (C90)
    // ENUMS are a constant as well

    // Common String Functions:       // string.h

      // Copying
    char src[100] = "Some stuff.";
    char dest[100];
    size_t len = strlen(src);    // length of string minus null char
    printf("%lu\n", len);
    strcpy(dest, src);   // copy string to existing string, errors if doesnt' fit
        // strncpy() is a safer way to copy strings
    memset(dest, '\0', sizeof(dest));  // sets all 100 locations to null char
    strncpy(dest, src, 10);    // Sets first 10 chars of dest to that of src

      // Cating
    char myString[100];
    memset(myString, '\0', sizeof(myString));
    strncpy(myString, "This plus ", 10);
    printf("%s\n", myString);
    strncat(myString, src, strlen(src));
    printf("%s\n", myString);

      // Compare
    printf("strcmp(\"A\", \"A\") is ");
    printf("%d\n", strcmp("A", "A"));

    printf("strcmp(\"A\", \"B\") is ");
    printf("%d\n", strcmp("A", "B"));

    printf("strcmp(\"B\", \"A\") is ");
    printf("%d\n", strcmp("B", "A"));

    printf("strcmp(\"apples\", \"apple\") is ");
    printf("%d\n", strcmp("apples", "apple"));

    printf("strcmp(\"apple\", \"apples\") is ");
    printf("%d\n", strcmp("apple", "apples"));

    if (strncmp("astronomy", "astro", 5) == 0) { printf("ASTRO\n"); }
    char *userInput;
    userInput = "\0";
    while (strncmp(userInput, "quit", 4)) {    // compare first n values
        if (strcmp(userInput, "\0") == 1) { free(userInput); }
        printf("Type 'quit' to stop: ");
        userInput = s_get_ahead();
    }
    free(userInput);


    return 0;
}
