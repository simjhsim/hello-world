// myMath.cpp

// Useful math functions

#include <iostream>

#include "myMath.h"

// powint computes a^b where a is an integer, b is a 
// nonnegative integer, and ^ is the exponential function.
int powint (int a, int b)
{
    int i, j, exp;
    exp = 1;
    if (b < 0)
    {
        std::cout << "Power is negative. Computing powint("
            << a << "," << (-1 * b) << ").\n";
        j = -b;
    }
    else
    {
        j = b;
    }

    for (i = j; i > 0; i--)
    {
        exp = exp * a;
    }

    return exp;
}

// Below are implementations of finding various math
// operations related to multiples and factors.

// greatestCommonFactor takes in two positive integers
// and returns their greatest common factor
int greatestCommonFactor (int a, int b)
{
    int p, gcd, min, mul1, mul2;
    mul1 = a;
    mul2 = b;
    gcd = 1;

    if (a <= 0 || b <= 0)
    {
        std::cout << "[GCD] nonpositive inputs "<< a << 
            "," << b << ".\n";
            return 1;
    }
    else if (a == 1 || b == 1)
    {
        return 1;
    }
    
    if (mul1 < mul2)
    {
        min = mul1;
    }
    else
    {
        min = mul2;
    }

    for (p = 2; p <= min; p++)
    {
        while ((mul1 % p == 0) && (mul2 % p == 0))
        {
            gcd = p * gcd;
            mul1 = mul1 / p;
            mul2 = mul2 / p;
        }
    }

    return gcd;
}

// leastCommonMultiple takes in two positive integers
// and returns their least common multiple
int leastCommonMultiple (int a, int b)
{
    int gcd = greatestCommonFactor(a,b);

    return gcd * (a / gcd) * (b / gcd);
}

// arithSum takes in two integers (a,b) and a positive 
// integer d and sums up the arithmetic sequence starting
// from a with difference d bounded by (including) b.
int arithSum (int a, int b, int d)
{
    if (a > b)
    {
        return 0;
    }
    else if (d <= 0)
    {
        std::cout << "[ARITHSUM] ERROR: nonpositive "
            << "difference" << d << ".\n";
    }
    else if (a == b)
    {
        return a;
    }

    int sum, i, buff;

    for (buff = a; buff <= b; buff += d)
    {
        sum = sum += buff;
    }

    return sum;
}

// consSum takes in two integers (a,b) and returns the
// sum of all integers between and a and b (inclusive).
int consSum (int a, int b)
{
    if (a > b)
    {
        return 0;
    }

    return (b-a+1)*(a+b)/2;
}