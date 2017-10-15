
#include <cstdio>
#include "complex.hpp"

complex c1 = complex(-1, -2);
complex c2 = complex(1, 1);

int main() {
    printf("(%f, %f)\n", c1.re, c1.im);
    c1 = c2;
    printf("(%f, %f)\n", c1.re, c1.im);
    c1 = -c2;
    printf("(%f, %f)\n", c1.re, c1.im);
    return 0;
}