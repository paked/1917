// danish.c
// Use for loops to print out the danish flags
// by Harrison Shoebridge, 24/3/15

#include <stdio.h>
#include <stdlib.h>

#define FLAG_WIDTH 12
#define FLAG_HEIGHT 5

void showDanish(void);

int main(int argc, char * argv[]) {
    showDanish();

    return EXIT_SUCCESS;
}

void showDanish(void) {
    int col = 0;
    while(col < FLAG_HEIGHT) {
        int row = 0;
        while(row < FLAG_WIDTH) {
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
