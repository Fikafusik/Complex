
#include <cstdio>
#include "mathematics.hpp"
#include "algorithms.hpp"

void mathematics_test();
void algorithms_test();

int main() {
    mathematics_test();
    algorithms_test();
}

void mathematics_test() {
    printf("-> Hello, I'm mathematics_test()!\n");

    const double a = 1.01;
    const int n = 1000;

    double npr = native_power_resursion(a, n);
    double npi = native_power_iterative(a, n);
    double bpr = binary_power_recursion(a, n);
    double bpi = binary_power_iterative(a, n);

    printf("%f\t%f\t%f\t%f\n", npr, npi, bpr, bpi);

    const double b = 1000000;
    const int m = 12;

    double r = root(b, m);
    double s = sqrt(b);
    double c = cbrt(b);

    printf("%f\t%f\t%f\n\n", r, s, c);

    double a1 =      0;
    double a2 = pi / 6;
    double a3 = pi / 4;
    double a4 = pi / 3;
    double a5 = pi / 2;

    printf("%f\n%f\n%f\n%f\n%f\n", sin(a1), sin(a2), sin(a3), sin(a4), sin(a5));
    
    printf("-> \n");
}

void algorithms_test() {
    printf("-> Hello, I'm algorithms_test()!\n");

    int a = 5;
    int b = 10;

    printf("Swap<int>:\n");
    printf("%d\t%d\n", a, b);
    swap(a, b);
    printf("%d\t%d\n", a, b);

    double c = 3.14;
    double d = 5.26;

    printf("\nSwap<double>:\n");
    printf("%f\t%f\n", c, d);
    swap(c, d);
    printf("%f\t%f\n\n", c, d);

    printf("Max(%d, %d) = %d\n", a, b, max(a, b));
    printf("Min(%d, %d) = %d\n", a, b, min(a, b));
    printf("Max(%f, %f) = %f\n", c, d, max(c, d));
    printf("Min(%f, %f) = %f\n", c, d, min(c, d));

    printf("-> \n");
}