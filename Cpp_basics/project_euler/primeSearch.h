// primeSearch.h

// Various functions for finding primes.

#ifndef PRIMESEARCH_H 
#define PRIMESEARCH_H

// Function to generate N prime numbers using  
// Sieve of Eratosthenes 
// taken from geeksforgeeks.org/program-to-find-the-nth-prime-number/
void SieveOfEratosthenes(
    std::vector<int> &primes, int bound);  

// Uses prime number theorem to find a reasonable bound N
// for which the num-th prime is less than N.
int primeNumThm (int num);

#endif 