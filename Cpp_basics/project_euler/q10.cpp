// q10.cpp

// Problem: Summation of primes
//
// Find the sum of all primes below two million.

// Use Sieve of Eratosthenes to sum up the primes below
// 2000000

#define DEBUG

#include <iostream>
#include <string>
#include <vector>

#include "primeSearch.h"


int main (int argc, char** argv)
{
    std::vector<int> primes;
    long long int sum;
    int i, primesize;
    sum = 0;

    SieveOfEratosthenes(primes, 2000000);

    primesize = primes.size();

    for (i = 0; i < primesize; ++i)
    {
        sum += (long long int) primes[i];
    }

    std::cout << "[Q10] The sum of all primes less than "
        << "2000000 is: " << sum << ".\n";

    return 0;
}