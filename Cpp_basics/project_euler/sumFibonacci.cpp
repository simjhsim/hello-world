// sumFibonacci.cpp

#include <iostream>

#include "sumFibonacci.h"

// sum Fibonacci returns the sum of all terms of the
// Fibonacci sequence beginning with the ordered pair
// (alpha, beta) of positive integers that is less
// than bound.
int sumFibonacci (int alpha, int beta, int bound)
{
    int x,y,z,sum;

    x   = alpha;
    y   = beta;
    sum = 0;

    while (x < bound)
    {
        if (x % 2 == 0)
        {
            sum += x;
        }

        z = x+y;
        x = y;
        y = z;
    }

    return sum;
}

