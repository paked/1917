// rot13.c - encodes a character in ROT13
// James Ye and Harrison Shoebridge ;)
// 25-03-2015
 
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
 
#define ROT_CYCLE 13
 
char encode(char letter);
void testEncode(void);
 
int main(int argc, char *argv[]) {
    testEncode();
    return EXIT_SUCCESS;
}
 
char encode(char letter) {
    if (letter >= 'A' && letter <= 'M') {\
        // A-M to N-Z
        letter += ROT_CYCLE;
    } else if (letter >= 'N' && letter <= 'Z') {
        // N-Z to A-M
        letter -= ROT_CYCLE;
    }
     
    if (letter >= 'a' && letter <= 'm') {
        // a-m to n-z
        letter += ROT_CYCLE;
    } else if (letter >= 'n' && letter <= 'z') {
        // n-z to a-m
        letter -= ROT_CYCLE;
    }
     
    return letter;
}
 
void testEncode(void) {
    printf("Testing upper case.\n");
    assert(encode('A') == 'N');
    assert(encode('N') == 'A');
    assert(encode('H') == 'U');
    assert(encode('U') == 'H');
    assert(encode('Z') == 'M');
    assert(encode('M') == 'Z');
     
    printf("Testing lower case.\n");
    assert(encode('a') == 'n');
    assert(encode('n') == 'a');
    assert(encode('h') == 'u');
    assert(encode('u') == 'h');
    assert(encode('z') == 'm');
    assert(encode('m') == 'z');
     
    printf("Testing numbers.\n");
    assert(encode('0') == '0');
    assert(encode('9') == '9');
    assert(encode('5') == '5');
    printf("Testing other stuff.\n");
    assert(encode('@') == '@');
    assert(encode('[') == '[');
    assert(encode('`') == '`');
    assert(encode('{') == '{');
    assert(encode('~') == '~');
    assert(encode('\255') == '\255');
    assert(encode('\0') == '\0');
    assert(encode('\n') == '\n');
    assert(encode('\r') == '\r');
    assert(encode(-1) == -1);
     
    printf("Testing awesomeness.\n");
    printf("Awesomeness granted.\n");
} 
