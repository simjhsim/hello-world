// greatestPrime.cpp

#include <iostream>

#include "greatestPrime.h"


// takes in a number and returns the greatest prime divisor
// the function starts from 1 and checks if the number 
// is a divisor. If so, all factors of the divisor is 
// removed from the number. The last such divisor must 
// be a prime.
long long greatestPrime(long long inp)
{
    long long primecand = 1;
    long long num = inp;

    while (primecand < num)
    {
        primecand += 1;

        while (num % primecand == 0)
        {
            num = num / primecand;
        }
    }

    return primecand;
}