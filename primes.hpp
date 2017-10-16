
#ifndef __PRIMES_HPP__
#define __PRIMES_HPP__

class sieve_of_eratosthenes {
private:
    bool* sieve;
public:
    sieve_of_eratosthenes(int);
    bool is_prime(int);
};

class sieve_of_sundaram {
private:
    bool* sieve;
public:
    // TODO:
    sieve_of_sundaram(int);
    // TODO:
    bool is_prime(int);
};

#endif