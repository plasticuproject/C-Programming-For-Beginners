/*
 * Author: plasticuproject
 * Purpose: Module 5 Challenge, display
 *          perimiter of a rectangle
 * Date: June 28, 2021
 */


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {

    // Display the perimeter of a rectangle
    /*
     * Program should create 4 variables of type double
     *   one variable to store the width of the rectangle
     *   one variable to store the height of the rectangle
     *   one variable to store the perimeter of the rectangle
     *   one variable to store the area of the rectangle
     *
     * Perimeter = (width + height) * 2
     * Area = width * height
     *
     * Use the printf function and the correct format specifier
     *   to display the width, heigth, perimeter, and area of the
     *   rectangle
    */


    // When no arguments are supplied, prints program details
    if (argc == 1) {
        printf("\nThis program will calculate the perimeter and area of a rectangle.\n");
        printf("Just pass in the width and height of your rectangle as program arguments.\n");

        return 0;
    }

    // Rectangle variables
    double width = atof(argv[1]);
    double heigth = atof(argv[2]);
    double perimeter = ((width + heigth) * 2.0);
    double area = (width * heigth);

    // When improper amount or non-numerical arguments are supplied,
    //   print this string and exit
    if((argc != 3) || (area == 0)) {
        printf("\nPlease provide the width and height of the rectangle only.\n");

        return 1;
    }

    // Print rectangle variables
    printf("\nWIDTH: %f\n", width);
    printf("HEIGTH: %f\n", heigth);
    printf("PERIMETER: %f\n", perimeter);
    printf("AREA: %f\n", area);


    return 0;
}
