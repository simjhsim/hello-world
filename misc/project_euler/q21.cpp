// q21.cpp

// Problem: Amicable numbers
//
// Evaluate the sum of all the amicable numbers under 10000.
//
// If d(n) is the sum of all proper divisors of n (e.g. 
// d(220) = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 
// + 110 = 284), we call a and b amicable if d(a) = b and 
// d(b) = a.

#define DEBUG
#define BOUND 10000

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "myMath.h"


int main (int argc, char** argv)
{
    // check keeps track of which numbers have been 
    // traversed
    bool check[BOUND];
    int i, prev, curr, amic_sum;

    amic_sum = 1;

    check[0] = false;
    check[1] = false;

    for (i = 2; i < BOUND; ++i)
    {
        check[i] = true;
    }

    for (i = 2; i < BOUND; ++i)
    {
        if (check[i])
        {
            curr = i;

            do
            {
                check[curr] = false;
                prev = curr;
                curr = sumPDiv(prev); // Implement sumPDiv

                if (curr >= BOUND)
                {
                    break;
                }
            }
            while (check[curr]);

            if (sumPDiv(curr) == prev)
            {
                if (curr < BOUND)
                {
                    check[curr] = false;

                    amic_sum += curr;
                }

                amic_sum += prev;
            }
        }
    }

    std::cout << "[Q21] The sum of all amicable numbers "
        << "less than " << BOUND << " is: " << amic_sum 
        << ".\n";

    return 0;
}