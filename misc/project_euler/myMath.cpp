// myMath.cpp

// Useful math functions

#include <iostream>
#include <vector>

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

// logint takes in a and b and computes the greatest
// integer less than log_a(b).
int logint (int a, int b)
{
    int i, j, base, inp;
    base = a;
    inp  = b;
    j = inp % base;

    for (i = 0; j != 0; i++)
    {
        inp = inp / base;
        j = inp % base;
    }

    return i;
}


// primeFactors takes in an empty vector of integer pairs 
// and a positive integer and fills the vector with the 
// prime factors and their multiplicities.
int primeFactors (std::vector<struct IntPair> & factors, 
    int num)
{
    if (num == 0)
    {
        std::cout << "[MM:PF] primeFactors given 0.\n";
        return -1;
    }

    struct IntPair ipair;
    int i, j, n;
    n = num;
    j = 0;

    for (i = 2; i <= n; ++i)
    {
        while (n % i == 0)
        {
            n = n / i;
            ++j;
        }

        if (j > 0)
        {
            ipair.x = i;
            ipair.y = j;
            factors.push_back(ipair);
            j = 0;
        }
    }

    return 0;
}

// numDivisors takes in a vector of integer pairs
// representing the prime factorization of a number and
// returns the number of divisors the number has.
int numDivisors (std::vector<struct IntPair> & pfactors)
{
    int size = pfactors.size();
    int numDiv = 1;

    for (int i = 0; i < size; ++i)
    {
        numDiv *= (pfactors[i]).y + 1;
    }

    return numDiv;
}

// powllint computes a^b where a is an integer, b is a 
// nonnegative integer, and ^ is the exponential function.
long long int powllint (long long int a, long long int b)
{
    long long int i, j, exp;
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

// aChooseb computes the number of choices of b elements
// in a set of a unique elements. Implemented recursively.
long long int aChooseb (int a, int b)
{
    if (a < b || b < 0)
    {
        return 0;
    }
    else if (b == 0)
    {
        return 1;
    }
    else if (a == b)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else if (a - b < 5)
    {
        int prodn, prodd, bound;
        bound = a - b;
        prodn = 1;
        prodd = 1;
        for (int i = 0; i < bound; ++i)
        {
            prodn = prodn * (a-i);
            prodd = prodd * (i+1);
        }
        return prodn / prodd;
    }

    return aChooseb(a-1, b) + aChooseb(a-1,b-1);
}