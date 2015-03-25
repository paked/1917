// swap.c - function to swap integers
// James Ye and Harrison Shoebridge
// 25-03-2015
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *second);
void testSwap(void);

int main(int argc, char *argv[]) {
    testSwap();
    return EXIT_SUCCESS;
}
void swap(int *first, int *second) {
    int swap = *first;
    *first = *second;
    *second = swap;
    return;
}
void testSwap(void) {
    int num1;
    int num2;
    int *test1 = &num1;
    int *test2 = &num2;

    *test1 = 1;
    *test2 = 2;
    swap(test1, test2);
    assert((*test1 == 2) && (*test2 == 1));

    *test1 = 5000;
    *test2 = 0;
    swap(test1, test2);
    assert((*test1 == 0) && (*test2 == 5000));

    *test1 = -10;
    *test2 = 9001;
    swap(test1, test2);
    assert((*test1 == 9001) && (*test2 == -10));

    *test1 = 0;
    *test2 = 0;
    swap(test1, test2);
    assert((*test1 == 0) && (*test2 == 0));

    printf("[You watch as your awesomeness level rises.]\n");
    return;
}

