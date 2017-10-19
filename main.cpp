
#include <cstdio>
#include "mathematics.hpp"

void mathematics_test();

int main() {
    mathematics_test();
}

void mathematics_test() {
    printf("-> Hello, I'm mathematics_test()!\n");
    
    const double    a = 1.01;
    const int       n = 1000;
    
    double npr = native_power_resursion(a, n);
    double npi = native_power_iterative(a, n);
    double bpr = binary_power_recursion(a, n);
    double bpi = binary_power_iterative(a, n);
    
    printf("%f\t%f\t%f\t%f\n", npr, npi, bpr, bpi);
    
    const double    b = 1000000;
    const int       m = 12;

    double r = root(b, m);
    double s = sqrt(b);
    double c = cbrt(b);

    printf("%f\t%f\t%f\n\n", r, s, c);

    const double pi = 3.14159265358979323846;

    double a1 = 0;
    double a2 = pi / 6;
    double a3 = pi / 4;
    double a4 = pi / 3;
    double a5 = pi / 2;

    printf("%f\n%f\n%f\n%f\n%f\n", sin(a1), sin(a2), sin(a3), sin(a4), sin(a5));

    printf("-> \n");
}