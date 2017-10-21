
#include <cstdio>
#include "mathematics.hpp"
#include "algorithms.hpp"
#include "primes.hpp"

void test_mathematics();
void test_algorithms();
void test_primes();

int main() {
    test_mathematics();
    test_algorithms();
    test_primes();
    return 0;
}

void test_mathematics() {
    printf("-> Hello, I'm test_mathematics()!\n");

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

void test_algorithms() {
    printf("-> Hello, I'm test_algorithms()!\n");

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

void test_primes() {
    printf("-> Hello, I'm test_primes()!\n");
    
    const int max_number = int(1e+6);

    sieve_of_eratosthenes   sieve_1(max_number);
    sieve_of_sundaram       sieve_2(max_number);
    sieve_of_atkin          sieve_3(max_number);
    
    for (int i = 0; i <= max_number; ++i) {
        if (sieve_2.is_prime(i) != sieve_3.is_prime(i))
            printf("%d\t%s\t%s\n", i, sieve_2.is_prime(i) ? "true" : "false", sieve_3.is_prime(i) ? "true" : "false");
    }

    printf("-> \n");
}