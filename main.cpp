
#include <cstdio>
#include "mathematic.hpp"

const double    a = 1.01;
const int       n = 1000;
const double    b = 1000000;
const int       m = 12;

int main() {
    double npr = native_power_resursion(a, n);
    double npi = native_power_iterative(a, n);
    double bpr = binary_power_recursion(a, n);
    double bpi = binary_power_iterative(a, n);
    
    double r = root(b, m);
    double s = sqrt(b);
    double c = cbrt(b);

    printf("\n%f\t%f\t%f\t%f\n%f\t%f\t%f\n\n", npr, npi, bpr, bpi, r, s, c);

    return 0;
}