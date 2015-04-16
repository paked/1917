#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverseString(char string[], int n);

int main(int argc, char *argv[]) {
    char str[3] = "abc";
    reverseString(str, 3);
    
    printf("%s\n", str);
    return EXIT_SUCCESS;
}

void reverseString(char string[], int n) {
    printf("%s vs ", string);
    n = n - 1;
    int i = 0;
    char c;
    while (i < (n / 2)) {
        c = string[i];
        string[i] = string[n - i];
        string[n - i] = c;

        i++;
    }

    printf("%s\n", string);
}
