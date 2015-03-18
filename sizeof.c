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

	char *pc = &c;
	int *pi = &i;
	long *pl = &l;
	float *pf = &f;
	double *pd = &d;

	printf("Finding the size of various C types... \n");
	printf("size of char: %ld\n", sizeof(c));
	printf("size of int: %ld\n", sizeof(i));
	printf("size of long: %ld\n", sizeof(l));
	printf("size of float: %ld\n", sizeof(f));
	printf("size of double: %ld\n", sizeof(d));

	printf("\nFinding the size to various pointers to C types...\n");
	printf("size of pointer to char: %ld\n", sizeof(pc));
	printf("size of pointer to int: %ld\n", sizeof(pi));
	printf("size of pointer to long: %ld\n", sizeof(pl));
	printf("size of pointer to float: %ld\n", sizeof(pf));
	printf("size of pointer to double: %ld\n", sizeof(pd));
	
	return EXIT_SUCCESS;
}
