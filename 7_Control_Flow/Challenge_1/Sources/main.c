/*
 * Author: plasticuproject
 * Purpose: Module 7 challenge, determine
 *          amount of pay.
 * Date: July 3, 2021
*/


#include <stdio.h>
#include <stdlib.h>


#define BUFFERSIZE        16
#define PAY_RATE          12.00
#define REG_HOURS         40
#define OT_RATE_MUL       1.50
#define LOW_TAX_RATE      0.15
#define LOW_TAX_CUTOFF    300
#define MID_TAX_RATE      0.20
#define MID_TAX_CUTOFF    450
#define HIGH_TAX_RATE     0.25


int main(void) {

    /*
     * Program should calculate weekly pay.
     *
     * Should display as output the gross pay, the taxes,
     *  and the net pay.
     *
     * The following assumptions should be made:
     *  * Basic pay rate = $12.00/hr
     *  * Overtime (in excess of 40 hours) = time and a half
     *  * Tax rate:
     *   * 15% of the first $300
     *   * 20% of the next $150
     *   * 25% of the rest
     *
     * Need to utilize if/else statements
    */


    // Declare local variables
    double hours, overtime, gross, net;
    double low_tax, mid_tax = 0, high_tax = 0, total_tax;
    char buffer[BUFFERSIZE];
    char *inputHours;

    // Get user input for number of hours worked
    printf("\nEnter number of hours worked: ");
    inputHours = fgets(buffer, BUFFERSIZE, stdin);
    hours = atof(inputHours);

    // Calculate gross pay
    if (hours > REG_HOURS) {
        overtime = (hours - REG_HOURS);
        gross = (REG_HOURS * PAY_RATE) + (overtime * (PAY_RATE * OT_RATE_MUL));
    }
    else { gross = (hours * PAY_RATE); }

    // Calculate taxes
    if (gross <= LOW_TAX_CUTOFF) { low_tax = (gross * LOW_TAX_RATE); }
    else if ((gross > LOW_TAX_CUTOFF) && (gross <= MID_TAX_CUTOFF)) {
            low_tax = (LOW_TAX_CUTOFF * LOW_TAX_RATE);
            mid_tax = ((gross - LOW_TAX_CUTOFF) * MID_TAX_RATE);
    }
    else {
        low_tax = (LOW_TAX_CUTOFF * LOW_TAX_RATE);
        mid_tax = ((MID_TAX_CUTOFF - LOW_TAX_CUTOFF) * MID_TAX_RATE);
        high_tax = ((gross - MID_TAX_CUTOFF) * HIGH_TAX_RATE);
    }
    total_tax = (low_tax + mid_tax + high_tax);

    // Calculate net pay
    net = (gross - total_tax);

    // Print output
    printf("\nGROSS PAY  : $%.2f\n", gross);
    printf("TOTAL TAXES: $%.2f\n", total_tax);
    printf("NET PAY    : $%.2f\n", net);


    return 0;
}
