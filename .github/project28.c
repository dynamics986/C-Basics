#include <stdio.h>
#include <math.h>
#include <complex.h>

int main(void){
    double complex n = -1-I;
    double complex x = log(cabs(n)) + I*(carg(n));
    double complex y = clog(n);
    printf("%f%+fi\n", creal(x), cimag(x));
    printf("%f%+fi\n", creal(y), cimag(y));
    return 0;
}