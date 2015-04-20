// frequency_analysis.c - a program to analyse frequency of character
// by Harrison Shoebridge

#include <stdlib.h>
#include <stdio.h>

#define ALPHABET_SIZE 26

int indexOf(char c);

int upperCaseChars = 0; 
int lowerCaseChars = 0;
int lfChars = 0;
int spaceChars = 0;

int main(int argc, char *argv[]) {
    int frequency[ALPHABET_SIZE];
    int i = 0;
    while (i < (ALPHABET_SIZE)) {
        frequency[i] = 0;
        i += 1;
    }
    
    int charactersRead = 0;
    int lettersRead = 0;

    char c = '\0';
    while (c != EOF) {
        c = getchar();
        charactersRead += 1;
        if (c == 10) {
            lfChars += 1;
        }

        if (c == 32) {
            spaceChars += 1;
        }

        int i = indexOf(c);
        if (i != -1) {
            lettersRead += 1;
            frequency[i] += 1;
        }
    }
    
    printf("Number of characters read %d\n", charactersRead);
    printf("Number of letters read %d\n", lettersRead);
    printf("Number of LF chars %d\n", lfChars);
    printf("Number of lowercase letters read: %d\n", lowerCaseChars);
    printf("Number of uppercase letters read: %d\n", upperCaseChars);
    printf("Number of spaces read: %d\n", spaceChars);

    i = 0;
    while (i < (ALPHABET_SIZE)) {
        char c = (char)(i + (int)'A');
        printf("%c has a frequency of %d\n", c, frequency[i]);
        i++;
    }

    return EXIT_SUCCESS;
}

int indexOf(char c) {
    if (c >= 'A' && c <= 'Z') {
        upperCaseChars += 1; 
        return (int)c - (int)'A';
    }

    if (c >= 'a' && c <= 'z') {
        lowerCaseChars += 1;
        return (int)c - (int)'a'; 
    }

    return -1;
}
