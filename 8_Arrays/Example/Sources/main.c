/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 8,
 *          Arrays.
 * Date: July 8, 2021
*/


#include <stdio.h>
#include <stdlib.h>


#define BUFFERSIZE 8


int main(void){

    // Creating and using arrays
     // An array is a FIXED number of data items of the same type
     // Declare same way as variables but with [] with size of array inside
     // * long numbers[10];    // 10 is element size of the array
     // Store elements by index
     // * numbers[0] = 5;
     // Access the elements by index
     // * long zero = numbers[0];
     // Common to use a loop to access array elements
     // * for(int i = 0; i < 10, i++) {
     // *     printf("Number is %d.\n", numbers[i];)
     // * }

    int grades[10], count = 10;  // Array storing 10 values, number of values to be read
    long sum = 0;                // Sum of the numbers
    float average = 0.0f;        // Average of the numbers
    char buffer[BUFFERSIZE];     // Input char array

    printf("\nEnter the 10 grades: \n");   // Prompt for input

    for(int i = 0; i < count; i++) {       // Read the ten numbers to be averaged
        printf("%2u> ", i + 1);
        fgets(buffer, BUFFERSIZE, stdin);  // Read a grade
        grades[i] = atoi(buffer);          // Convert input to int
        if(grades[i] > 100) {              // Validate input
            printf("\nOnly numbers 1-100 are acceptable.\n");
            break;                         // Kill if bad input detected
        }
        sum += grades[i];                  // Add it to sum
    }

    average = (float)sum / count;                 // Average
    if((grades[9] <= 100) && (average != 0)) {    // Make sure all grades were entered
        printf("\nAverage of the 10 grades is: %.2f\n", average);
    }


    return 0;
}
