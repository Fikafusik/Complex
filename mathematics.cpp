
#include "mathematics.hpp"
#include "algorithms.hpp"

double sqr(double n) {
    return n * n;
}

double native_power_resursion(double a, int n) {
    return (n == 0 ? 1 : a * native_power_resursion(a, n - 1));
}

double native_power_iterative(double a, int n) {
    double x = 1;
    for (int i = 0; i < n; i++)
        x *= a;
    return x;
}

double binary_power_recursion(double a, int n) {
    return (n == 0 ? 1 : (n & 1) ? a * binary_power_recursion(a, n - 1) : sqr(binary_power_recursion(a, n >> 1)));
}

double binary_power_iterative(double a, int n) {
    double x = 1;
    while (n) {
        if (n & 1)
            x *= a;
        a *= a;
        n >>= 1;
    }
    return x;
}

double root(double a, int n) {
    double x = a;
    double y;
    do {
        y = ((n - 1) * x + a / binary_power_iterative(x, n - 1)) / n;
        swap(x, y);
    } while (x != y);
    return x;
}

double sqrt(double a) {
    return root(a, 2);
}

double cbrt(double a) {
    return root(a, 3);
}

//Trigonometry (from Tolyan))0)

const double pi = 3.1415926536;

double sin(double a) {
    double last;
    double res;
    double sqra = a * a;
    double sqrpi = pi * pi;

    last = a * (1 - (sqra / sqrpi));
    for (int i = 2; i > 1; ++i) {
        res = last * (1 - (sqra / (sqrpi * sqr(i))));
        if (res == last) return res;
        else last = res;
    }
}

double cos(double a) {
    return sin(a + (pi / 2));
}