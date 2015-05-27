#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "complex.h"

int main(int argc, char *argv[]) {
    printf("TESTING...\n");
    printf("ADDITION\n");
    Complex c = newComplex(10, 20);
    assert(real(c) == 10);
    assert(imag(c) == 20);

    Complex b = newComplex(-100.5, -20.5);
    assert(real(b) == -100.5);
    assert(imag(b) == -20.5);

    Complex a = add(c, b);
    assert(real(a) == -90.5);
    assert(imag(a) == -0.5);

    printf("MULTIPLICATION\n");
    Complex p = newComplex(2, 1);
    Complex t = newComplex(2, 4);
    Complex r = multiply(p, t);
    assert(real(r) == 0);
    assert(imag(r) == 10);
    
    printf("FREEING\n");
    freeComplex(c);
    freeComplex(b);
    freeComplex(a);
    freeComplex(p);
    freeComplex(t);
    freeComplex(r);

    printf("OK!\n");
    
    return EXIT_SUCCESS;
}

