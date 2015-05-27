typedef struct _complex *Complex;

Complex add(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
double real(Complex c);
double imag(Complex c);

Complex newComplex(double x, double y);
void freeComplex(Complex c);
