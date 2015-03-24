// wondrous.c
// Contains a function to print out the "wondrous"
// seqence of numbers
// by Harrison Shoebridge, 24/3/15

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int printWondrous(int start);

int main(int argc, char * argv[]) {
    assert(printWondrous(3) == 8);
    assert(printWondrous(1) == 1);

    return EXIT_SUCCESS;
}

int printWondrous(int start) {
    int number = start;
    int cycles = 1;

    printf("%d ", number);
    while(number != 1) {
        if (number % 2 == 0) {
            // the number is even
            number = number / 2;
        }else {
            // odd
            number = (number * 3) + 1;
        }

        printf("%d ", number);
        cycles++;
    }

    printf("\n");

    return cycles;
}
