/*
 * Author: plasticuproject
 * Purpose: Module 9 challenge 1, write
 *          some functions.
 * Date: July 14, 2021
*/


#include <stdio.h>


// Function declarations
int gcd(int u, int v);
float absoluteValue(float x);
float squareRoot(float x);


// main function
int main(void) {

    // gcd function tests
    int result = 0;

    result = gcd(150, 35);
    printf("\nThe gcd of 150 and 35 is %d\n", result);


    // abs function tests
    float f1 = -15.5, f2 = 20.0, f3 = -5.0;
    int i1 = -716;
    float absoluteValueResult = 0.0;

    absoluteValueResult = absoluteValue(f1);
    printf("Result = %.2f\n", absoluteValueResult);

    absoluteValueResult = absoluteValue(f2);
    printf("Result = %.2f\n", absoluteValueResult);

    absoluteValueResult = absoluteValue(f3);
    printf("Result = %.2f\n", absoluteValueResult);

    absoluteValueResult = absoluteValue((float)i1);
    printf("Result = %.2f\n", absoluteValueResult);

    printf("%.2f\n\n\n\n", absoluteValue(-6.0) / 4);


    // squareRoot funciton tests
    printf("%.2f\n", squareRoot(-3.0));

    printf("%.2f\n", squareRoot(16.0));

    printf("%.2f\n", squareRoot(25.0));

    printf("%.2f\n", squareRoot(9.0));

    printf("%.2f\n", squareRoot(225.0));


    return 0;
}


// Returns greatest common divisor of two integer inputs
int gcd(int u, int v) {

    int temp;
    while (v != 0) {
        u = v;
        temp = u % v;
        v = temp;
    }

    return u;
}


// Returns square root of float input
float squareRoot(float x) {

    const float epsilon = 0.00001;
    float guess = 1.0;
    float returnValue = 0.0;

    if (x < 0) {
        printf("Negative argument to squareRoot.\n");
        returnValue = -1.0;
    }

    else {
        while (absoluteValue(guess * guess - x) >= epsilon) {
            guess = (x / guess + guess) / 2.0;
        }
        returnValue = guess;
    }

    return returnValue;
}


// Returns absolute value of float input
float absoluteValue(float x) {

    if (x < 0) {
        x = -x;
    }

    return x;
}
