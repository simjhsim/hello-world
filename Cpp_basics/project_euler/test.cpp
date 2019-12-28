// test.cpp

// This is a sandbox to test out various implemented
// functions.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "myMath.h"

int main (int argc, char** argv)
{
    std::vector<struct IntPair> pfactors;
    struct IntPair ipair;

    if (primeFactors(pfactors, 25) == 0)
    {
        std::cout << "[TEST] 25 has " << 
            numDivisors(pfactors) << " divisors.\n";
        std::cout << "[TEST] The prime factorization of 25 "
            << "is:";
        while (!pfactors.empty())
        {
            ipair = pfactors.front();
            std::cout << " " << ipair.x << "^" << ipair.y;
            pfactors.erase(pfactors.begin());
        }
        std::cout << ".\n";
    }

    if (primeFactors(pfactors, 35) == 0)
    {
        std::cout << "[TEST] 35 has " << 
            numDivisors(pfactors) << " divisors.\n";
        std::cout << "[TEST] The prime factorization of 35 "
            << "is:";
        while (!pfactors.empty())
        {
            ipair = pfactors.front();
            std::cout << " " << ipair.x << "^" << ipair.y;
            pfactors.erase(pfactors.begin());
        }
        std::cout << ".\n";
    }

    if (primeFactors(pfactors, 47) == 0)
    {
        std::cout << "[TEST] 47 has " << 
            numDivisors(pfactors) << " divisors.\n";
        std::cout << "[TEST] The prime factorization of 47 "
            << "is:";
        while (!pfactors.empty())
        {
            ipair = pfactors.front();
            std::cout << " " << ipair.x << "^" << ipair.y;
            pfactors.erase(pfactors.begin());
        }
        std::cout << ".\n";
    }

    return 0;
}