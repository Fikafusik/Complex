
#include "mathematics.hpp"
#include "algorithms.hpp"

const double pi = 3.141592653589793;

double sqr(double n)
{
    return n * n;
}

double native_power_resursion(double x, int n)
{
    return (n == 0 ? 1 : x * native_power_resursion(x, n - 1));
}

double native_power_iterative(double a, int n)
{
    double x = 1;
    for (int i = 0; i < n; i++)
        x *= a;
    return x;
}

double binary_power_recursion(double a, int n)
{
    return (n == 0 ? 1 : (n & 1) ? a * binary_power_recursion(a, n - 1) : sqr(binary_power_recursion(a, n >> 1)));
}

double binary_power_iterative(double a, int n)
{
    double x = 1;
    while (n)
    {
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
    do
    {
        y = ((n - 1) * x + a / binary_power_iterative(x, n - 1)) / n;
        swap(x, y);
    } while (x != y);
    return x;
}

double sqrt(double a)
{
    return root(a, 2);
}

double cbrt(double a)
{
    return root(a, 3);
}

//Trigonometry:

#include <cstdio>
double sin(double a)
{
    double last;
    double res;
    double sqra = sqr(a);
    double sqrpi = sqr(pi);

    last = a * (1 - (sqra / sqrpi));
    /*
    for (int i = 2; i > 1; ++i) {
        res = last * (1 - (sqra / (sqrpi * sqr(i))));
        if (res == last) 
            return res;
        else 
            last = res;
    }
    */
    const double c = sqr(a) / sqr(pi);
    int n = 2;
    do
    {
        res = last * (1 - c / sqr(n++));
        swap(last, res);
    } while (res != last);
    printf("\n%d iterations\n", n);
    return res;
}

double cos(double a)
{
    return sin(a + pi / 2);
}

double tan(double a)
{
    return sin(a) / cos(a);
}

double cot(double a)
{
    return cos(a) / sin(a);
}

double sec(double a)
{
    return 1 / cos(a);
}

double csc(double a)
{
    return 1 / sin(a);
}