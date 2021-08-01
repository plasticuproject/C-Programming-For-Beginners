/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 10,
 *          Character Strings.
 * Date: July 17, 2021
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>               // islower(), isupper(), isalpha(), isdigit()

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
    //   *  #define MONTHS 12  // preprocessor directive, subbed at/before compile time
    //   *  const int MONTHS = 12;  // symbolic constant (C90)
    //   * ENUMS are a constant as well

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

    char *userInput = "\0";
    while (strncmp(userInput, "quit", 4)) {
        if (strcmp(userInput, "\0") != 0) { free(userInput); userInput = NULL; }
        printf("Type 'quit' to stop: ");
        userInput = s_get_ahead();
    }
    free(userInput);
    userInput = NULL;

    // Searching, Tokenizing, and Analyzing
      // Searching

      // * strchr(), search string for character, returns NULL if not found
    char *thing = NULL;
    const char searchThis[] = "Search for A character";
    const char searchChar = 'A';

    thing = strchr(searchThis, searchChar);
    if (thing != NULL) {
        printf("'%c' is found in '%s'\n", thing[0], searchThis);
        printf("The string from the match is '%s'\n", thing);
    }
    else { printf("'%c' Not found in '%s'\n", searchChar, searchThis); }

      // * strstr(), like strchr(), but searches for an entire string/substring
    char searchSubstring[] = "for";
    thing = NULL;
    thing = strstr(searchThis, searchSubstring);
    if (thing != NULL) { printf("'%s' found in '%s'\n", searchSubstring, searchThis); }

      // Tokenizing
      // * strtok(), suppy string to be tokenized, and a string with all delimiters
    char name[] = "Hello how are you--my name is-plastic";
    const char s[2] = "-";
    char *token = NULL;

    token = strtok(name, s);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

      // Analyzing; There are a lot more than listed here
    char up = 'A';
    char low = 'a';
    char alp = 'B';
    char dig = '1';

      // * islower()
    printf("islower('A') = %d\n", islower(up));
    printf("islower('a') = %d\n", islower(low));
    printf("islower('B') = %d\n", islower(alp));
    printf("islower('1') = %d\n", islower(dig));
      // * isupper()
    printf("\nisupper('A') = %d\n", isupper(up));
    printf("isupper('a') = %d\n", isupper(low));
    printf("isupper('B') = %d\n", isupper(alp));
    printf("isupper('1') = %d\n", isupper(dig));
      // * isalpha()
    printf("\nisalpha('A') = %d\n", isalpha(up));
    printf("isalpha('a') = %d\n", isalpha(low));
    printf("isalpha('B') = %d\n", isalpha(alp));
    printf("isalpha('1') = %d\n", isalpha(dig));
      // * isdigit()
    printf("\nisdigit('A') = %d\n", isdigit(up));
    printf("isdigit('a') = %d\n", isdigit(low));
    printf("isdigit('B') = %d\n", isdigit(alp));
    printf("isdigit('1') = %d\n", isdigit(dig));

    // Converting Strings
    // * toupper()
    char lowString[] = "here is some text";
    char upString[strlen(lowString) + 1];
    for (int i = 0; (upString[i] = ((char)toupper(lowString[i]))) != '\0'; i++);
    printf("\n%s\n", upString);

    // * tolower()
    for (int i = 0; (lowString[i] = ((char)tolower(upString[i]))) != '\0'; i++);
    printf("\n%s\n", lowString);

    for (int i = 0; i < strlen(lowString); i++) {
        if (i == 0) { printf("\n%c", (char)toupper(lowString[i])); }
        else { printf("%c", lowString[i]); }
    }
    printf(".\n");

    // * atof(), atoi(), atol(), atoll(), (stdlib?)
    // * strtod(), strtof(), strtold(), (C99??)



    return 0;
}
