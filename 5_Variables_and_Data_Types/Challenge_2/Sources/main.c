/*
 * Author: plasticuproject
 * Purpose: Module 5 Challenge, create C program that
 *          defines and displays enum type variables.
 * Date: June 29, 2021
 */


#include <stdio.h>


int main(void) {

    /* Program should create an enum type named Company
     *   # Valid values for this type are GOOGLE, FACEBOOK,
     *       XEROX, YAHOO, EBAY and MICROSOFT
     *
     * Program should create three variables of the above
     *   enum type that are asigned values: XEROX, GOOGLE,
     *   and EBAY.
     *
     * Program should display as output, the values of the
     *   three variables with each variable seperated by a
     *   newline
     *     # Correct output would be if XEROX, GOOGLE, and
     *         EBAY variables are printed in that order:
     *         * 2
     *         * 0
     *         * 4
    */

    // Define enum type and values
    enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };

    // Declare and initalize variables
    enum Company xerox = XEROX, google = GOOGLE, ebay = EBAY;

    // Print data
    printf("\nThe value of XEROX is: %d\n", xerox);
    printf("The value of GOOGLE is: %d\n", google);
    printf("The value of EBAY is: %d\n", ebay);


    return 0;
}
