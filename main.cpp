
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

    printf("%f\t%f\t%f\n", r, s, c);

    const double pi = 3.14159265358979323846;

    double a1 = pi / 2;
    double a2 = pi / 3;
    double a3 = pi / 6;

    printf("%f\t%f\t%f\n", sin(a1), sin(a2), sin(a3));
    printf("%f\t%f\t%f\n", cos(a1), cos(a2), cos(a3));
    printf("%f\t%f\t%f\n", tan(a1), tan(a2), tan(a3));
    printf("%f\t%f\t%f\n", cot(a1), cot(a2), cot(a3));

    printf("-> \n");
}