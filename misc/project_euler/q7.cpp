// q7.cpp

// Problem: 10001st prime
//
// What is the 10001st prime number?

// Takes in integer n >= 1 and returns n-th prime.

#include <iostream>
#include <vector> 
#include <cstring>

#include "primeSearch.h"

int main (int argc, char** argv)
{
    int n = std::stoi(argv[1]);
    // To store all prime numbers 
    std::vector<int> primes; 

    std::cout << "Finding the " << n << "-th prime.\n";

    SieveOfEratosthenes(primes, 2000000); 

    std::cout << "The " << n << "-th prime is " 
        << primes[n-1] << ".\n";

    return 0;
}