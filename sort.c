// sort.c
// A program to sort three integers!
// by Harrison Shoebridge on the 18/3/15
//
// Possible solutions:
// A B C  C B A
// C A B  B A C
// B C A  A C B

#include <stdlib.h>
#include <stdio.h>

void printNums(int a, int b, int c);

int main(int arg, char * argv[]) {
    int a;
    int b;
    int c;

    scanf("%d %d %d", &a, &b, &c);
    
    if (a < b && b < c) {
        printNums(a, b, c);
    }else if (c < b && b < a) {
        printNums(c, b, a); 
    }else if (c < a && a < b) {
        printNums(c, a, b);
    }else if (b < a && a < c) {
        printNums(b, a, c);
    }else if (b < c && c < a) {
        printNums(b, c, a);
    }else if (a < c && c < b) {
        printNums(c, a, b);
    }

    return EXIT_SUCCESS;
}

void printNums(int a, int b, int c) {
    printf("%d %d %d\n", a, b, c);
}


