
#include "combinatorics.hpp"

long long int factorial_recursive(int n) {
    return (n == 0 ? 1 : factorial_recursive(n - 1) * n);
}

long long int factorial_iterative(int n) {
    long long int x = 1;
    while (n)
        x *= n--;
    return x;
}

long long int native_P(int n) {
    return factorial_iterative(n);
}

long long int native_A(int n, int k) {
    return factorial_iterative(n) / factorial_iterative(n - k);
}

long long int native_C(int n, int k) {
    return factorial_iterative(n) / factorial_iterative(n - k) / factorial_iterative(k);
}

combinatorics::combinatorics(int nmax) {
    pascal_table = new long long int*[nmax + 1];
    for (int i = 0; i <= nmax; ++i)
        pascal_table[i] = new long long int[nmax + 1];
    for (int i = 0; i <= nmax; ++i) {
        pascal_table[i][0] = 1;
        pascal_table[i][i] = 1;
    }
}

long long int combinatorics::C(int n, int k) {
    if (!pascal_table[n][k])
        pascal_table[n][k] = C(n - 1, k - 1) + C(n - 1, k);
    return pascal_table[n][k];
}