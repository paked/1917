// strlen.c - a custom strlen function... FOR LEARNING!
// by Harrison Shoebridge

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int hstrlen(char * string);
void testStrlen(void);

int main(int argc, char *argv[]) {
    testStrlen();
    return EXIT_SUCCESS;
}

int hstrlen(char *string) {
    int n = 0;
    int i = 0;
    
    char c = 'a';
    while (c != '\0') {
        c = string[i];
        i += 1;
    }
    
    return i - 1;
}

void testStrlen(void) {
    assert(hstrlen("123") == 3);
    assert(hstrlen("") == 0);

    printf("Passed tests! You are awesome!\n");
}
