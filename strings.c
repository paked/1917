// strings.c - a file to play with C strings!
// by Harrison Shoebridge at some point in early 2015!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    char *str = "hello";
    int i = 0;
    while (i < strlen(str)) {
        printf("char: %c\n", str[i]);
        i += 1;
    }
    return EXIT_SUCCESS;
}
