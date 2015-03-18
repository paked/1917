// sizeof.c
// A program to find out how much memory each C type stores!
// by Harrison Shoebridge 18/3/2015

#include <stdlib.h>
#include <stdio.h>
int main(int argc, char * argv[]) {
	char c;
	int i;
	long l;
	float f;
	double d;

	printf("Finding the size of various C types... \n");
	printf("size of char: %ld\n", sizeof(c));
	printf("size of int: %ld\n", sizeof(i));
	printf("size of long: %ld\n", sizeof(l));
	printf("size of float: %ld\n", sizeof(f));
	printf("size of double: %ld\n", sizeof(d));
	return EXIT_SUCCESS;
}
