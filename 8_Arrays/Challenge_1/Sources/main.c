/*
 * Author: plasticuproject
 * Purpose: Module 8 challenge 1, generate
 *          prime numbers.
 * Date: July 9, 2021
*/


#include <stdio.h>


int main(void) {

    /*
     * Create a program that will fine all the primes from 3-100
     * No input to the program
     * Output will be each prime number seperated by a space on a single line
     * Need to create an array that will store each prime number as generated
     * Can hard code the first two primes (2 and 3) in the array
     * Utilize loops to only find prime numbers up to 100 and a loop to print
     *   out the primes array
     *
    */


    // Declare primes array and initialize first two primes
    int primes[50] = { 2, 3 };

    // Declare and initialize our prime array index to 2, since we hard coded
    //   the first 2 elements
    int primeIndex = 2;

    // Declare boolean variable for our number candidate
    _Bool isPrime;

    // Prime finding algo
    for(int p = 5; p <= 100; p += 2) {    // Starting with 5, skip even numbers
        isPrime = 1;                      // Set prime boolean to TRUE

        // If candidate remains true and is not larger than the square root
        //   of current number in array
        for(int i = 1; isPrime && ((p / primes[i]) >= primes[i]); i++) {

            // if canditate divded by current number in array, set boolean to FALSE
            if(p % primes[i] == 0) { isPrime = 0; }
        }
        if(isPrime) {                    // If boolean remains TRUE after array loop
            primes[primeIndex] = p;      // Add candidate to primes array at index
            primeIndex++;                // Increase primeIndex by 1
        }
    }

    // Loop through primes array and print each element
    for(int i = 0; i < 50; i++) {
        if(primes[i] != 0) { printf("%d ", primes[i]); }
    }
    printf("\n");                        // Print newline for cleaner output


    return 0;
}
