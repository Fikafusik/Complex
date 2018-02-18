
#include "primes.hpp"
#include "mathematics.hpp"

sieve_of_eratosthenes::sieve_of_eratosthenes(int max_number) {
    sieve = new bool[max_number + 1];
    sieve[0] = sieve[1] = true;
    for (int i = 4; i <= max_number; i += 2)
        sieve[i] = true;
    for (int i = 3; i * i <= max_number; i += 2)
        if (!sieve[i])
            for (int j = i * i; j <= max_number; j += i)
                sieve[j] = true;
}

bool sieve_of_eratosthenes::is_prime(int number) {
    return !sieve[number];
}

sieve_of_eratosthenes::~sieve_of_eratosthenes() {
    delete []sieve;
}

sieve_of_sundaram::sieve_of_sundaram(int max_number) {
    sieve = new bool[max_number + 1];
    sieve[2] = true;
    max_number >>= 1;
    bool* _sieve = new bool[max_number + 1];
    for (int i = 1; (i * (i + 1) << 1) <= max_number; ++i)
        for (int j = i; j * (2 * i + 1) + i <= max_number; ++j)
            _sieve[i + j + (i * j << 1)] = true;
    for (int i = 1; i <= max_number; ++i)
        if (!_sieve[i]) 
            sieve[2 * i + 1] = true;
    delete []_sieve;
}

bool sieve_of_sundaram::is_prime(int number) {
    return sieve[number];
}

sieve_of_sundaram::~sieve_of_sundaram() {
    delete []sieve;
}

sieve_of_atkin::sieve_of_atkin(int max_number) {
    sieve = new bool[max_number + 1];
    sieve[2] = sieve[3] = true;
    for (int x2 = 1, dx2 = 3; x2 < max_number; x2 += dx2, dx2 += 2)
        for (int y2 = 1, dy2 = 3, n; y2 < max_number; y2 += dy2, dy2 += 2) {
            n = (x2 << 2) + y2;
            if (n <= max_number && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;
            n -= x2;
            if (n <= max_number && n % 12 == 7)
                sieve[n] ^= true;
            if (x2 > y2) {
                n -= (y2 << 1);
                if (n <= max_number && n % 12 == 11)
                    sieve[n] ^= true;
            }
        }
    for (int r = 5, r2 = r * r, dr2 = r + 1 << 2; r2 < max_number; r += 2, r2 += dr2, dr2 += 8)
        if (sieve[r])
            for (int mr2 = r2; mr2 < max_number; mr2 += r2)
                sieve[mr2] = false;
}

bool sieve_of_atkin::is_prime(int number) {
    return sieve[number];
}

sieve_of_atkin::~sieve_of_atkin() {
    delete [] sieve;
}