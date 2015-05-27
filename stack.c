#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _stack {
    int itemCount;
    int items[STACK_SIZE];
} stack;

Stack newStack(void) {
    Stack c = malloc(sizeof(stack));

    int i = 0;
    while (i < STACK_SIZE) {
        c->items[i] = -1;
        i += 1;
    }

    c->itemCount = 0;
    
    return c;
}

Stack pop(Stack s) {
    s->itemCount -= 1;

    return s;
}

Stack push(Stack s, int i) {
    s->items[s->itemCount] = i;
    s->itemCount += 1;
    
    return s;
}

int top(Stack s) {
    return s->items[s->itemCount-1];
}

