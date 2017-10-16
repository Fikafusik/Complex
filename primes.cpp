
#include "primes.hpp"
#include "mathematics.hpp"

sieve_of_eratosthenes::sieve_of_eratosthenes(int max_number) {
    sieve = new bool[max_number + 1];
    sieve[0] = true;
    sieve[1] = true;
    for (int i = 2; i * i <= max_number; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= max_number; ++j)
                sieve[j] = true;
}

bool sieve_of_eratosthenes::is_prime(int number) {
    return !sieve[number];
}
// TODO:
sieve_of_sundaram::sieve_of_sundaram(int max_number) {
    sieve = new bool[max_number + 1];
}