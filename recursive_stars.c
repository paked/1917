// recursive_stars.c - one of Olivers practice thing... recursive
// by Harrison Shoebridge

#include <stdlib.h>
#include <stdio.h>

void stars(int start);

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    stars(n);
    return EXIT_SUCCESS;
}

void stars(int start) {
    if (start <= 0) {
        return;
    }

    int i = 0;
    while (i < start) {
        printf("*");
        i += 1;
    }

    printf("\n");
    stars(start - 1);
}
