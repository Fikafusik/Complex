
#include <cstdio>
#include "mathematic.hpp"

void mathematic_test();

int main() {
    mathematic_test();
}

void mathematic_test() {
    printf("-> Hello, I'm mathematic_test!\n");
    
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
    
    printf("-> \n");
}