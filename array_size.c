#include <stdlib.h>

#define ARRAY_SIZE 11

int main(int argc, char * argv[]) {
    int numbers [ARRAY_SIZE];
    int n;
    int i;

    n = 0;
    i = 0;
    while (i < ARRAY_SIZE) {
        numbers[i] = n;
        n = n + (2 * i) + 1;
        i++;
    }

    i = 0;
    while(i < ARRAY_SIZE) {
        printf("%d ", numbers[i]);
        i++;
    }

    printf("\n");

    return EXIT_SUCCESS;
}
