// q3.cpp

// Problem: Largest prime factor
// 
// What is the largest prime factor of the number 
// 600851475143?

// Takes in an integer of magnitude < 2^(63) (i.e. a long 
// long) and finds its largest prime divisor.


#include <iostream>
#include <string>

#include "greatestPrime.h"

int main (int argc, char** argv) 
{
    if (argc != 2)
    {
        std::cout << "[ERROR] two positive integer values"
            << "must be given as arguments.\n";
        return -1;
    }

    long long num;
    long long m;

    num = std::stoll(argv[1]);

    if (num < 0)
    {
        num = num * (-1);
    }

    m = greatestPrime(num);

    std::cout << "\nGreatest Prime Divisor of "
        << num << " is " << m << ".\n";

    return 0;
}

