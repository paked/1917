#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main(int argc, char *argv[]) {
    Stack c = newStack();

    push(c, 10);
    assert(top(c) == 10);

    push(c, 5);
    assert(top(c) == 5);

    pop(c);
    assert(top(c) == 10);

    printf("Awesome!\n");
    return EXIT_SUCCESS;
}
