/*
 * Author: plasticuproject
 * Purpose: Module 10 Challenge 1, Understanding
 *          char arrays.
 * Date: July 31, 2021
*/


#include <stdio.h>


int strCount(char arr[]);
void strCat(char result[], const char str1[], const char str2[]);
_Bool strCmp(const char str1[], const char str2[]);
void printBool(const char str1[], const char str2[]);


// main function
int main(void) {

    /*
     * Write a function to count the number of characters in a string
     *  * Cannot use the strlen() function
     *  * Should take a character array as a parameter
     *  * Should return an int (length)
     *
     * Write a function to concatenate two character strings
     *  * Cannot use the strcat() fuction
     *  * Should take 3 parameters
     *   * char result[]
     *   * const char str1[]
     *   * const char str2[]
     *   * can return void
     *
     * Write a function that determines if two strings are equal
     *  * Cannot use strcmp() function
     *  * Should take two const char arrays as parameters
     *  * Return a Boolean of true if they are equal or false otherwise
    */


    // Test strCount()
    char myName[] = "plasticuproject";

    printf("\nThe length of %s is %d.\n", myName, strCount(myName));


    // Test strCat()
    const char cat[] = "cat";
    const char dog[] = "dog";
    char catdog[strCount((char *)cat) + strCount((char *)dog) + 2];
                            /* This is fucked. Since a constraint is that the
                             *   first param of strCat() must be an array
                             *   and not a pointer, and that is our param
                             *   where our result is returned, this array
                             *   must be declared/initialized with enough
                             *   space to hold the concatenated strings
                             *   or else it will stop short. */

    strCat(catdog, cat, dog);
    printf("\n'%s' + '%s' = '%s'\n\n", cat, dog, catdog);


    // Test strCmp()
    printBool(cat, dog);
    printBool("dog", "cat");
    printBool("cat", "cat");
    printBool("cattt", "cat");
    printBool("cat", "cattttt");


    return 0;
}


// Count the number of characters in a string array
int strCount(char arr[]) {

    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        count++;
    }

    return count;
}


// Concatanate two string arrays
void strCat(char result[], const char str1[], const char str2[]) {

    size_t buffLen = strCount((char *)str1) + strCount((char *)str2) + 1;
    char buff[buffLen];
    int count = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        buff[i] = str1[i];
        count = i;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        count += 1;
        buff[count] = str2[i];
    }
    for (int i = 0; result[i] != '\0'; i++) { result[i] = buff[i]; }
}


// Compare two string arrays
_Bool strCmp(const char str1[], const char str2[]) {

    _Bool boolVar = 1;

    for (int i = 0; str1[i] != '\0'; i++) {
        if ((str1[i] != str2[i]) || str2[i] == '\0') {
            boolVar = 0;
            break;
        }
    }
    if (strCount((char *)str1) != strCount((char *)str2)) { boolVar = 0; }

    return boolVar;
}


// Wrapper to print strCmp() result
void printBool(const char str1[], const char str2[]) {

    char *boolean[6];

    if (strCmp(str1, str2) != 1) { *boolean = "FALSE"; }
    else { *boolean = "TRUE"; }
    printf("%s = %s is %s.\n",str1, str2, *boolean);
}
