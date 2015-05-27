#include <stdlib.h>

#include "complex.h"

typedef struct _complex {
    double x;
    double y;
} comp;

Complex add(Complex a, Complex b) {
    comp *c = newComplex(0, 0);
    c->x = real(a) + real(b);
    c->y = imag(a) + imag(b);

    return c;
}

Complex multiply(Complex a, Complex b) {
    comp *c = newComplex(0, 0);

    c->x = real(a)*real(b) - imag(a)*imag(b);
    c->y = imag(a)*real(b) + real(a)*imag(b);

    return c;
}

double real(Complex c) {
    return c->x;
}

double imag(Complex c) {
    return c->y;
}

Complex newComplex(double x, double y) {
    comp *c = malloc(sizeof(comp));
    c->x = x;
    c->y = y;

    return c;
}

void freeComplex(Complex c) {
    free(c);
}
