
#ifndef __COMBINATORICS_HPP__
#define __COMBINATORICS_HPP__

long long int factorial_recursive(int);
long long int factorial_iterative(int);

long long int native_P(int);
long long int native_A(int, int);
long long int native_C(int, int);

class combinatorics {
private:
    long long int** pascal_table;
public:
    combinatorics(int);
    // TODO:
    long long int P(int);
    // TODO:
    long long int A(int, int);
    
    long long int C(int, int);
};

#endif