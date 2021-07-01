/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 6,
 *          Operators.
 * Date: June 29, 2021
*/


#include <stdio.h>


int main(void) {

    // EzPz math operators
     //   + - * / % ++ --
    int a = 33, b = 15, c;
    c = a + b;
    printf("\nc is: %d\n", c);

     // Postfix vs Prefix increment
    printf("a is: %d\n", a++);  // a is not incremented until next statement (postfix)
    printf("a is now incremented by 1: %d\n", a);
    printf("a is incremented by 1 again: %d\n", ++a);  // a is incremented in same statement (prefix)

    // Logical operators
     // && (AND), || (OR), ! (NOT)
    _Bool d = 1, e = 1, f;
    f = d && e;
    if (f == 1) { printf("f is: TRUE\n"); }
    if (f == 0) { printf("f is: FALSE\n"); }

    // Assignment Operators
     // = += -= *= /= %= <<= >>= &= ^= !=

    // Relational Operators
     // == != > < >= <=

    // Bitwise and shift operators
     // & (AND), | (OR), ^ (XOR), ~ (ONES COMP), << >> (LEFT and RIGHT SHIFT)
    unsigned int g = 60;  // 0011 1100
    unsigned int h = 13;  // 0000 1101
    int i = g & h;  // 0000 1100
    printf("i is: %d\n", i);  // 12

    // cast (Type Conversions) and sizeof
     // Type cast operator has highest priorety other than ++ and --
    int j = (int)21.51 + (int)26.99;
    printf("int: 21.51 (21) + int: 26.99 (26) = %d\n", j);  // should equal 47

     // sizeof returns how many bytes are occupied in memory by a given type
      // it is evaluated at compile time and not runtime unless a variable-length
      // array is used in it's argument
    printf("Size of a: %d is: %lu bytes\n", a, sizeof(a));
    printf("Size of i: %d is: %lu bytes\n", i, sizeof(i));

    // Other operators
     // * represents a pointer to a variable when used to the left of a variable
     // ?: is the ternary operator and is used for comparisons:
      // if Condition is true ? then value X: otherwise value Y


    return 0;
}
