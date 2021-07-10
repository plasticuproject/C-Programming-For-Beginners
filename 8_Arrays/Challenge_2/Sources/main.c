/*
 * Author: plasticuproject
 * Purpose: Module 8 challenge 2, create a
 *          simple weather program.
 * Date: July 9, 2021
*/


#include <stdio.h>


int main(void) {

    /*
     * Create a program that uses a two-dimensional array in a weather program.
     * Program will find the total rainfall for each year, the average yearly
     *   rainfall, and the average rainfall for each month.
     * Input will be a 2D array with hard-coded values for rainfall amounts for
     *   the past 5 years.
     *  * The array should have 5 rows and 12 columns.
     *  * Rainfall amounts can be floating point numbers.
     *
     * Output Example:
     *  * YEAR    RAINFALL (inches)
     *  * 2010       32.4
     *  * 2011       37.9
     *  * 2012       49.8
     *  * 2013       44.0
     *  * 2014       32.9
     *  *
     *  * The yearly average is 39.4 inches.
     *  *
     *  * MONTHLY AVERAGES:
     *  *
     *  * Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
     *  * 7.3 7.3 4.9 3.0 2.3 0.6 1.2 0.3 0.5 1.7 3.6 6.7
     *
     * Initialize your 2D array with hard-coded rainfall amounts.
     * Remember to iterate through a 2D array you will need a nested loop.
     * The key to this solution will be to visualize a 2D array and understand
     *   how to iterate through one, via a nested loop.
     * As you are iterating, you can keep a running total (outer loop iterate by
     *   year, inner loop iterate by month) to get the total rainfall for all years.
     * To get the average monthly rainfalls, iterate through the 2D array by having
     *   the outer loop go through each month and the inner loop go through each year.
    */


    // Declare and initialize data using random numbers using python
    // python3 -c 'from random import randint;[print(randint(0, 99)) for i in range(12)]'
    float rainData[5][12] = {
        { 9.3, 9.6, 5.4, 2.0, 3.8, 9.9, 7.7, 5.4, 6.1, 7.5, 1.9, 0.0 },
        { 9.1, 1.6, 6.9, 2.9, 3.4, 1.3, 9.0, 2.6, 1.9, 9.1, 4.5, 1.4 },
        { 8.6, 7.2, 9.9, 0.7, 7.9, 4.2, 9.4, 0.9, 5.1, 3.3, 6.1, 6.6 },
        { 9.5, 6.7, 6.6, 3.2, 2.8, 2.4, 8.5, 5.7, 2.3, 2.2, 9.5, 6.9 },
        { 1.5, 4.1, 0.7, 2.2, 1.3, 5.4, 6.4, 9.3, 3.2, 9.1, 2.4, 4.5 },
    };

    // Declare and initialize array for month names
    char *months[12] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec"
    };

    // Declare and initialize local variables
    int years = 2010;
    float yearSum = 0.0;
    float totalYearsSum = 0.0;
    float monthlyTotals[12] = { 0.0 };

    // Calculate and print yearly amounts and averages
    printf("\n\nYEAR\tRAINFALL (inches)\n");
    for(int year = 0; year < 5; year++) {                    // Iterate through years
        for(int month = 0; month < 12; month++) {            // Iterate through months
            yearSum += rainData[year][month];                // Monthly totals for year
            monthlyTotals[month] += rainData[year][month];   // Monthly totals for years
        }
        printf("%d\t  %.1f\n", years, yearSum);              // Print yearly total
        totalYearsSum += yearSum;                            // Add yearly totals
        yearSum = 0.0;                                       // Reset for new year
        years += 1;                                          // Increment years number
    }

    // Print yearly totals divided by number of years
    printf("\nThe yearly average is %.1f inches.\n", (totalYearsSum / 5));

    // Print monthly averages
    printf("\nMONTHLY AVERAGES:\n\n");
    for(int month = 0; month < 12; month++) {
        printf("%s ", months[month]);
    }
    printf("\n");                                      // For display formatting
    for(int month = 0; month < 12; month++) {
        printf("%.1f ", (monthlyTotals[month] / 5));   // Monthly total divided by years
    }
    printf("\n\n\n");                                  // For display formatting


    return 0;
}
