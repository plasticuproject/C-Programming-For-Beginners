/*
 * Author: plasticuproject
 * Purpose: Examples and notes for Module 7,
 *          Control Flow.
 * Date: July 2, 2021
*/


#include <stdio.h>
#include <stdlib.h>


#define BUFFERSIZE 8


int main(void) {

    // IF statements
    int score = 95, big = 90;

     // simple statement no brackets
    if (score > big)
        printf("\nJackpot!\n");

     // compound statement
    if (score > big) {
        score++;
        printf("\nYou win\n");
    }

     // IF, ELSE and TERNARY
    int number_to_test, remainder;
    char buffer[BUFFERSIZE];
    char* your_status = NULL;

    printf("\nEnter your number to be tested: ");
    fgets(buffer, BUFFERSIZE, stdin);

    number_to_test = atoi(buffer);
    remainder = number_to_test % 2;

    if (remainder == 0) { printf("The number is even.\n"); }
        if (atoi(buffer) == 2) { printf("And that's my favorite number!\n"); }
    else if (atoi(buffer) == 13) { printf("That's an unlucky number!\n"); }
    else { printf("The number is odd.\n"); }

      // Ternary min/max 2 variables
    your_status = atoi(buffer) == 2 ? "You are awesome!" : "You suck.";
    printf("\n%s\n", your_status);

    // SWITCH/CASE/DEFAULT
     // When the value of a variable is successively compared against differnt values
    enum Weekend {Friday, Saturday, Sunday};
    enum Weekend today = Saturday;

    switch (today) {
        case Saturday:
            printf("\nToday is Saturday.\n");
            break;
        case Sunday:
            printf("\nToday is Sunday.\n");
            break;
        default:
            printf("\nMeh.\n");
            break;
    }

    // For loops
     // Counter controlled
    for(int index = 0; index < 10; index++) { printf("%d\n", index); }

    for(int i = 1, j = 2; i <= 5; i++, j += 2) { printf(" %5d", i * j); }

    unsigned long long sum = 0LL;
    unsigned int count = 20;
    for(unsigned int i = 1; i <= count; sum += i++);
    printf("\nTotal of the first %u numbers is %llu\n", count, sum);

    // While and Do-While
    int while_count = 1;
    while(while_count <= 5) { 
        printf("%d\n", while_count);
        while_count++;
    }
     // do-while (post-test/exit controlled loop)
      // body is executed for the first time unconditionally
      // always guarenteed to run at least once
      // condition is at the bottom
    int number = 4;
    do {
        printf("%d\n", number);
        number++;
    } while(number < 4);

    // Nested loops/loop control, break and continue
    for(int k = 1, loop_sum, loop_count = 5; k <= loop_count; k++) {
        loop_sum = 0;
        for(int l = 1; l <= k; l++) { // or "int l = 1; while(l < k); loop_sum += j++;"
            loop_sum += l;
        }
        printf("\n%d\t%d", k, loop_sum);
    }
     // Continue statement
    enum Day { Monday, Tuesday, Wednesday, Thursday };
    for(enum Day day = Tuesday; day <= Thursday; day++) {
        if(day == Tuesday) { continue; }
        printf("\nIt's not Tuesday.\n");

    }
     // continue with break
    int p = 10, q;
    while(p > 0) {
        printf("p = %d\nEnter q: ", p);
        fgets(buffer, BUFFERSIZE, stdin);
        q = atoi(buffer);
        while(q > 0) {
            printf("p x q = %d\n", p * q);
            if(q > 100) { break; }
            printf("Enter q: ");
            fgets(buffer, BUFFERSIZE, stdin);
            q = atoi(buffer);
        }
        if(q > 100) { break; }
        printf("Enter p: ");    // when q is 0 or null, get a new p
        fgets(buffer, BUFFERSIZE, stdin);
        p = atoi(buffer);
    }


    return 0;
}
