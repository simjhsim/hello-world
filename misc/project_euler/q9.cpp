// q9.cpp

// Problem: Special Pythagorean triplet
//
// What is the unique Pythagorean triplet such that
// a < b < c, and a+b+c=1000?

// This can be simplified to taking num in the set 
// {2^n 5^m : 0 <= n <= 5, 0 <= m <= 6, n + m < 11}
// and taking 
//      a = (1000-num)
//      c = (500 000/num) - a
//      b = 1000 - (a+c)
// and checking if these are a pythagorean triple.

#define DEBUG

#include <iostream>
#include <string>
#include <vector>

#include "myMath.h"


int main (int argc, char** argv)
{
    int a, b, c, quo;

    for (a = 1; a < 500; ++a)
    {
        b = (500000 - (1000 * a)) / (1000 - a);
        quo = (1000 - a) * b;

        if (quo == (500000 - (1000 * a)))
        {
            c = 1000 - (a+b);

            if (powint(a,2) + powint(b,2) == powint(c,2))
            {
                std::cout << "[Q9] Triplet found: ("
                    << a << ","
                    << b << ","
                    << c << ").\n"
                    << "Product is: " << (a*b*c) <<".\n";
                return 0;
            }
        }
    }
    
    std::cout << "[Q9] Could not find triplet.\n";
    return 0;
}