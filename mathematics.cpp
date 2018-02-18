
#include <cstdio>
#include "mathematics.hpp"
#include "algorithms.hpp"

const double pi = 3.141592653589793;

double abs(double x) {
    return (x < 0 ? -x : x);
}

double sqr(double x) {
    return (x * x);
}

double native_power_resursion(double x, int n) {
    return (n == 0 ? 1 : x * native_power_resursion(x, n - 1));
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

double root(double a, int n)
{
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

double sin(double a) {
    const double sqrA = a * a;
    double n = 1.0;
    double x = a;
    double Teylor = x;
    while (x != 0.0)
        Teylor += x *= -sqrA / ++n / ++n;
    return Teylor;
}

double cos(double a) {
    return sin(a + pi / 2);
}

double tan(double a) {
    return sin(a) / cos(a);
}

double cot(double a) {
    return cos(a) / sin(a);
}

double sec(double a) {
    return 1 / cos(a);
}

double csc(double a) {
    return 1 / sin(a);
}