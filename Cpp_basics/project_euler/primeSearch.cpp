// primeSearch.cpp

#include <iostream>
#include <vector>
#include <cstring>

#include "primeSearch.h"
#include "myMath.h"

// Various functions for finding primes

// Function to generate N prime numbers using  
// Sieve of Eratosthenes 
// taken from geeksforgeeks.org/program-to-find-the-nth-prime-number/
void SieveOfEratosthenes(
    std::vector<int> &primes, int bound)  
{  
    // Create a boolean array "IsPrime[0..MAX_SIZE]" and  
    // initialize all entries it as true. A value in  
    // IsPrime[i] will finally be false if i is  
    // Not a IsPrime, else true.  
    bool IsPrime[bound];  
    std::memset(IsPrime, true, sizeof(IsPrime));  
    
    for (int p = 2; p * p < bound; p++)  
    {  
        // If IsPrime[p] is not changed, then it is a prime  
        if (IsPrime[p] == true)  
        {  
            // Update all multiples of p greater than or   
            // equal to the square of it  
            // numbers which are multiple of p and are  
            // less than p^2 are already been marked.   
            for (int i = p * p; i <  bound; i += p)
                IsPrime[i] = false;  
        }  
    }  
    
    // Store all prime numbers  
    for (int p = 2; p < bound; p++)  
       if (IsPrime[p])  
            primes.push_back(p); 
             
}  

// Uses prime number theorem to find a reasonable bound N
// for which the num-th prime is less than N.
int primeNumThm (int num)
{
    std::cout << "[PS:PNT] Entering primeNumThm.\n";
    if (num <= 0)
    {
        std::cout << "[PS:PNT] ERROR: nonpositive integer "
            << "provided for argument: " << num << ".\n";
        return -1;
    }

    int bound, target, buff1, buff2, curr, denom1, denom2;
    bound  = powint(10,8);
    buff1  = 0;

    denom2 = logint(2, num);
    if (denom2 == 0)
    {
        denom2 = 1;
    }
    target = num / denom2;

    denom1  = logint(2, bound);
    if (denom1 == 0)
    {
        denom1 = 1;
    }
    curr   = bound / denom1;

    if (curr < target)
    {
        std::cout << "[PS:PNT] ERROR: target too large.\n";
        return -2;
    }

    while ((curr - target) <= 1 && (curr - target) >= -1)
    {
        buff2 = bound;
        bound = (bound + buff1) / 2;
        buff1 = buff2;
        curr = bound / logint(2,bound);
    }

    std::cout << "[PS:PNT] bound: "<< (bound + 1) << ".\n";

    return bound + 1;
}