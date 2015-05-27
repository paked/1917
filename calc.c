// calc.c - BECAUSE WE CAN CAN CAN
// by Harrison Shoebridge

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "reverse_string.c"

#define TRUE 1
#define FALSE 0

void testCalc(void);
int calc(char *input);
int parseInteger(char *input);
int parseAdd(char *input);
int parseSubtract(char *input);
int parseMultiply(char *input);
int end(char *input);

char look;
int location = 0;
int err = 0;

int main(int argc, char *argv[]) {
    printf("Testing calculator...\n");
    testCalc();
    printf("OK\n");

    return EXIT_SUCCESS;
}

void testCalc(void) {
    err = 0;
    location = 0;
    assert(calc("1") == 1);

    err = 0;
    location = 0;
    calc("a");
    assert(err != 0);

    err = 0;
    location = 0;
    assert(calc("1+1") == 2);
    
    err = 0;
    location = 0;
    assert(calc("1-2") == -1);

    err = 0;
    location = 0;
    assert(calc("9+5+4") == 18);

    err = 0;
    location = 0;
    int res = calc(strrev("9-5-4"));
    printf("got: %d\n\n\n", res);
    assert(res == 0);
}

int calc(char *input) {
    return parseAdd(input);
}

int parseAdd(char *input) {
    int num = parseSubtract(input);
    if (end(input)) {
        return num;
    }

    char c = input[location];
    if (c == '+') {
        location += 1;
        num = num + parseAdd(input);
    }

    return num;
}

int parseSubtract(char *input) {
    int num = parseInteger(input);
    if (end(input)) {
        return num;
    }

    char c = input[location];
    if (c == '-') {
        location += 1;
        int f = parseSubtract(input);
        printf("subtract %d from %d\n", f, num);
        num = num - f;
    }

    return num;
}

int parseInteger(char *input) {
    char c = input[location];
    printf("num: %c\n", input[location]);
    if (c < '0' || c > '9') {
        printf("for input %s, got NaN error\n", input);
        err = 1;
        return 0;
    }

    location += 1;

    return c - '0';
}

int end(char *input) {
    if (location >= strlen(input)-1) {
        return TRUE;
    }

    return FALSE;
}

