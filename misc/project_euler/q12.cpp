// q12.cpp

// Problem: Highly divisible triangular number
//
// Find the first triangular number with over 500 divisors
// [NOTE: triangular numbers are the sum of the first n
// positive integers (e.g. the 5th triangular number is
// 1 + 2 + 3 + 4 + 5 = 15).]

// The n-th triangular number is (n)(n+1)/2. Since n and 
// n+1 are coprime, it follows that any divisor of the
// n-th triangular number is uniquely of the form a * b 
// where 
//      if n is even, a is a divisor of n/2 and b is 
//          a divisor of n+1
//      if n is odd, a is a divisor of n and b is a 
//          divisor of (n+1)/2
// Thus, the number of divisors of the n-th triangular
// number is either div(n) * div((n + 1) / 2) or 
// div(n / 2) * (div(n + 1))

// Function will take in an integer num and find n such that
// the n-th traingular number has more than num divisors.

#define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "myMath.h"


int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "[Q12] Invalid input.\n";
        return -1;
    }

    std::vector<struct IntPair> pf1, pf2, pf3;
    int i, n, numdivl, numdivu;
    n = std::stoi(argv[1]);
    i = 2;
    primeFactors(pf3, 3);

    // index by even numbers
    do
    {
        i += 2;
        pf1.swap(pf3); // reuse previous pf3

        pf2.erase(pf2.begin(),pf2.begin()+pf2.size());
        pf3.erase(pf3.begin(),pf3.begin()+pf3.size());

        primeFactors(pf2, i/2);
        primeFactors(pf3, i+1);

        numdivl = numDivisors(pf1) * numDivisors(pf2);
        numdivu = numDivisors(pf2) * numDivisors(pf3);
    } while (numdivl <= n && numdivu <= n);

    if (numdivl > n)
    {
        std::cout << "[Q12] The first triangular number "
            << "with more than " << n << " divisors is "
            << "the " << (i-1) << "-th trinum: "
            << ((i-1)*i/2) << ".\n";
        return 0;
    }

    if (numdivu > n)
    {
        std::cout << "[Q12] The first triangular number "
            << "with more than " << n << " divisors is "
            << "the " << i << "-th trinum: "
            << ((i+1)*i/2) << ".\n";
        return 0;
    }
    
    std::cout << "[Q12] ERROR end of function.\n";

    return -2;
}