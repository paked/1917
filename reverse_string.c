#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

char *reverse(char *message);
void testReverse(void);

int main(int argc, char *argv[]) {
    char *reversed = reverse("Hello");

    printf("%s\n", reversed);
    free(reversed);
    
    testReverse();
    printf("Are you *actually* awesome...\n");
    printf("Tests say yes.");

    return EXIT_SUCCESS;
}

char *reverse(char *message) {
    int n = strlen(message);
    char *reversed = malloc(sizeof(char) * n + 1);
    n = n;

    int i = 0;
    while (i < n) {
        reversed[i] = message[n - i -1];
        i += 1;
    }
    reversed[i] = 0;

    printf("str is: %s\n", reversed);

    return reversed;
}

void testReverse(void) {
    char *str1 = "Hello";
    char *str2 = "Hello";
    assert(strcmp(reverse(str1), str2));
}
