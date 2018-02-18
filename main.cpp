
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

    printf("\n");
    int arr1[10] = {3, 1, 5, 2, 6, 8, 4, 9, 7, 0};
    int arr2[10] = {3, 1, 5, 2, 6, 8, 4, 9, 7, 0};
    int arr3[10] = {3, 1, 5, 2, 6, 8, 4, 9, 7, 0};
    for (int i = 0; i < 10; i++) printf("%d ", arr1[i]);
    printf("\n");
    printf("Sort_stupid:\n");
    sort_stupid(arr1, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d ", arr1[i]);
    printf("\n");
    printf("Sort_selection:\n");
    sort_selection(arr2, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d ", arr2[i]);
    printf("\n");
    printf("Sort_insertion:\n");
    sort_insertion(arr3, 0, 9);
    for (int i = 0; i < 10; i++) printf("%d ", arr2[i]);
    printf("\n");

    printf("-> \n");
}

void test_primes() {
    printf("-> Hello, I'm test_primes()!\n");
    
    const int max_number = int(1e+6);

    sieve_of_eratosthenes   sieve1(max_number);
    sieve_of_sundaram       sieve2(max_number);
    sieve_of_atkin          sieve3(max_number);
    
    printf("%10s%15s%15s%15s\n", "Number", "Eratosthenes", "Sundaram", "Atkin");
    for (int number = 0; number <= max_number; ++number) {
        bool ip1 = sieve1.is_prime(number);
        bool ip2 = sieve2.is_prime(number);
        bool ip3 = sieve3.is_prime(number);
        if (ip1 != ip2 || ip1 != ip3 || ip2 != ip3)
            printf("%10d%15s%15s%15s", number, (ip1 ? "prime" : "not prime"), (ip2 ? "prime" : "not prime"), (ip3 ? "prime" : "not prime"));
    }

    printf("-> \n");
}