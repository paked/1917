// extract.c
// funtions and types used to extract x,y,z values from a
// string containing a url of the form
// "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp"
// initially by richard buckland
// 13 April 2014
// implemented by Harrison Shoebridge
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"
 
 
int main (int argc, char *argv[]) {
	char *message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5.bmp";
 
	triordinate dat = extract (message);
 
	printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
 
	assert (dat.x == 3.14);
	assert (dat.y == -0.141);
	assert (dat.z == 5);
 
    testMyAtoL();
    testMyAtoD();
    printf("Passed tests! You are awesome!\n");
	return EXIT_SUCCESS;
}

// 20
long myAtoL(char *message) {
    long num = 0;
    int place = 1;
    int n = strlen(message) - 1;

    int i = 0;
    while (i < (n + 1)) {
        char c = message[n - i];
        long n = c - '0';

        num += n * place;
        i += 1;
        place *= 10;
    }

    return num;
}

double myAtoD(char *message) {
    double num = 0;
    int place = 1;
    int decimalAt = 1;
    int usingDecimal = 1;
    int n = strlen(message) - 1;

    int i = 0;
    while (i < (n + 1)) {
        char c = message[n - i];
        if (c == '.') {
            decimalAt = place; 
        } else { 
            double n = c - '0';
            num += n * place;
            place *= 10;
        }

        i += 1;
    }

    num /= decimalAt;
    return num;
}

triordinate extract(char *string) {
    triordinate t;
    sscanf(string, "http://almondbread.cse.unsw.edu.au:7191/tile_x%lf_y%lf_z%d.bmp", &t.x, &t.y, &t.z);

    return t;
}

void testMyAtoL(void) {
    assert(myAtoL("100") == 100);
    assert(myAtoL("") == 0);
    assert(myAtoL("65") == 65);
}

void testMyAtoD(void) {
    assert(myAtoD("10.101") == 10.1010);
    assert(myAtoD("") == 0);
}
