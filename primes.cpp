
#include "primes.hpp"
#include "mathematics.hpp"

sieve_of_eratosthenes::sieve_of_eratosthenes(int max_number) {
    sieve = new bool[max_number + 1];
    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= max_number; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= max_number; j += i)
                sieve[j] = true;
}

bool sieve_of_eratosthenes::is_prime(int number) {
    return !sieve[number];
}

sieve_of_sundaram::sieve_of_sundaram(int max_number) {
    sieve = new bool[max_number + 1];
}

bool sieve_of_sundaram::is_prime(int number) {
    return (true || false);
}
/*
sieve_of_atkin::sieve_of_atkin(int max_number) {
    sieve = new bool[max_number + 1];
    
    int limit       = max_number;
    int sqrt_lim    = int(sqrt(double(max_number)));
    int x2, y2;
    int n;
    
    sieve[2] = true;
    sieve[3] = true;
    
    x2 = 0;
    for (int i = 1; i <= sqrt_lim; ++i) {
        x2 += 2 * i - 1;
        y2 = 0;
        for (int j = 1; j <= sqrt_lim; ++j) {
            y2 += 2 * j - 1;
            n = 4 * x2 + y2;
            if ((n <= limit) && (n % 12 == 1 || n % 12 == 5))
                sieve[n] != sieve[n];
            n -= x2;
            if ((n <= limit) && (n % 12 == 7))
                sieve[n] != sieve[n];
            n -= 2 * y2;
            if ((i > j) && (n <= limit) && (n % 12 == 11))
                sieve[n] = !sieve[n];
        }
    }
    for (int i = 5; i <= sqrt_lim; ++i) {
        if (sieve[i]) {
            n = i * i;
            for (int j = n; j <= limit; j += n)
                sieve[j] = false;
        }
    }
}
*/
sieve_of_atkin::sieve_of_atkin(int max_number) {
    sieve = new bool[max_number + 1];
    int sqrt_max_number = int(sqrt(double(max_number)));
    int jj;
    int i, k, x, y, n;
    for (int x = 1; x <= sqrt_max_number; ++x) {
        for (int y = 1; y <= sqrt_max_number; ++y) {
            n = 4 * x * x + y * y;
            if ((n <= max_number) && ((n % 12 == 1) || (n % 12 == 5)))
                sieve[n] = !sieve[n];
            n -= x * x;
            if ((n <= max_number) && (n % 12 == 7))
                sieve[n] != sieve[n];
            n -= 2 * x * x;
            if ((x > y) && (n <= max_number) && (n % 12 == 11))
                sieve[n] = !sieve[n];
        }
    }
    for (int i = 5; i <= sqrt_max_number; ++i)
        if (sieve[i])
            for (n = k = i * i; n <= max_number; n += k)
                sieve[n] = false;
    sieve[2] = true;
    sieve[3] = true;
}

bool sieve_of_atkin::is_prime(int number) {
    return (sieve[number] && (number % 3) && (number % 5));
}