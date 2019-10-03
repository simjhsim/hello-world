// multSum.cpp

#include <iostream>
#include <string>

#include "multSum.h"

// Takes in three arguments n1, n2, bound and 
// returns the sum of all multiples of n1 and
// n2 less than the bound, assuming that n1 and
// n2 are positive integers

int multSum (int mul, int maxval) 
{
    if (mul > maxval)
    {
        return 0;
    }

    int a = maxval / mul;

    return (mul * a * (a + 1)) / 2;
}

int lcm (int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    int mul = a;

    while (mul%b != 0)
    {
        mul += a;
    }

    return mul;
}

