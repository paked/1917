/*
 *  reads in a permutation of the alphabet then encodes
 *  lower case letters using that permutation
 *
 *  Created by Julian Saknussemm on 11/09/1752
 *  Updated by Julian Tu         on 1/4/2015
 *  Licensed under Creative Commons BY 3.0.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#define STOP -1
#define ALPHABET_SIZE 26
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
 
char encode(int plainChar, char *permuation);
int indexOf(char letter, char *searchString);
void testEncode(void);
void testIndexOf(void);
 
int main(int argc, char *argv[]) {
    testIndexOf();
    testEncode();
 
    char permutation[ALPHABET_SIZE];
    scanf("%s", permutation);
 
    // getchar() reads and returns one character from the keyboard
    // returns -1 when the input is finished / end-of-file is reached
    // signal this from the keyboard by pressing ^D in linux/^Z windows
    char plainCharacter = getchar();
    while (plainCharacter != STOP) {
        char encodedCharacter = encode(plainCharacter, permutation);
        printf ("%c", encodedCharacter);
        plainCharacter = getchar();
    }
    return EXIT_SUCCESS;
}
 
 
char encode(int plainChar, char *permuation) {
    int letterNum = indexOf(plainChar, ALPHABET);
    char encoded;
    if (letterNum != -1) {
        encoded = permuation[letterNum];
    } else {
        encoded = plainChar;
    }
    return encoded;
}
 
int indexOf(char letter, char *searchString) {
    // Returns the index of the last occurence of letter in the string
    // Returns -1 if it's not in the string
    int i = 0;
    int found = -1;
    while (searchString[i] != 0) {
        if (letter == searchString[i]) {
            found = i;
        }
        i++;
    }
    return found;
}
 
void testEncode(void) {
    assert(encode('A', "abcdefghijklmnopqrstuvwxyz") == 'A');
    assert(encode('?', "abcdefghijklmnopqrstuvwxyz") == '?');
    assert(encode(' ', "abcdefghijklmnopqrstuvwxyz") == ' ');
    assert(encode('\n', "abcdefghijklmnopqrstuvwxyz") == '\n');
 
    assert(encode('a', "abcdefghijklmnopqrstuvwxyz") == 'a');
    assert(encode('m', "abcdefghijklmnopqrstuvwxyz") == 'm');
    assert(encode('z', "abcdefghijklmnopqrstuvwxyz") == 'z');
 
    assert(encode('a', "bcdefghijklmnopqrstuvwxyza") == 'b');
    assert(encode('m', "bcdefghijklmnopqrstuvwxyza") == 'n');
    assert(encode('z', "bcdefghijklmnopqrstuvwxyza") == 'a');
 
    assert(encode('a', "qwertyuiopasdfghjklzxcvbnm") == 'q');
    assert(encode('b', "qwertyuiopasdfghjklzxcvbnm") == 'w');
    assert(encode('z', "qwertyuiopasdfghjklzxcvbnm") == 'm');
}
 
void testIndexOf(void) {
    assert(indexOf('a', "abcd") == 0);
    assert(indexOf('b', "abcd") == 1);
    assert(indexOf('c', "abcd") == 2);
    assert(indexOf('d', "abcd") == 3);
    assert(indexOf('z', "abcd") == -1);
}
