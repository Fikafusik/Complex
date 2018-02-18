
#ifndef __PRIMES_HPP__
#define __PRIMES_HPP__

class sieve_of_eratosthenes {
private:
    bool* sieve;
public:
    sieve_of_eratosthenes(int);
    bool is_prime(int);
    ~sieve_of_eratosthenes();
};

class sieve_of_sundaram {
private:
    bool* sieve;
public:
    sieve_of_sundaram(int);
    bool is_prime(int);
    ~sieve_of_sundaram();
};

class sieve_of_atkin {
private:
    bool* sieve;
public:
    sieve_of_atkin(int);
    bool is_prime(int);
    ~sieve_of_atkin();
};

#endif