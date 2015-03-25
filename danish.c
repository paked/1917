// danish.c
// Use for loops to print out the danish flags
// by Harrison Shoebridge, 24/3/15

#include <stdio.h>
#include <stdlib.h>

void showDanish(void);

int main(int argc, char * argv[]) {
    showDanish();

    return EXIT_SUCCESS;
}

void showDanish(void) {
    int segments = 0;
    while(segments < 2) {
        int lines = 0;
        while (lines < 2) {
            printf("** *********\n");
            lines += 1;
        }

        if (segments == 0) {
            printf("\n");
        }

        segments += 1;
    }   

    printf("\n\n");

    segments = 0;
    int col = 0;
    while(col < 5) {
        int row = 0;
        while(row < 12) {
            if (row == 2 || col == 2) {
                printf(" ");
            }else {
                printf("*"); 
            }
            row++;
        }
        printf("\n");
        col++;
    }
}
