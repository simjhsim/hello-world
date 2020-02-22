// q14.cpp

// Problem: Longest Collatz sequence
//
// Which starting number, under one million, produces
// the longest Collatz sequence?

// Background: the collatz sequence starts with a positive
// integer n and iteratively builds a sequence as follows:
//      n_0 = n
//      if n_i is even, n_(i+1) = n_i / 2
//      if n_i is odd,  n_(i+1) = (3 * n_i) + 1
// The sequence, for our purposes, ends when it hits 1.
// The Collatz conjecture states that every natural number
// eventually reaches 1. It has yet to be proven, though
// it is known (as of 2017) to hold for all natural numbers
// up to 87 * 2^60.

#define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>

#include "myMath.h"


int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "[Q14] Invalid input. Requires"
            << " parameter for upper bound.\n";
    }

    long long int index;
    int i, j, k, bound, ub;
    bound = std::stoi(argv[1]);
    ub    = 10 * bound;

    std::vector<int> collatzlengths;
    
    for (i = 0; i <= ub; ++i)
    {
        collatzlengths.push_back(0);
    }

    // initialize powers of 2
    j = 1;
    for (i = 0; j < ub; ++i)
    {
        collatzlengths[j] = i;
        j = j * 2;
    }

    std::stack<long long int> buffer;

    for (i = 1; i <= bound; ++i)
    {
        #ifdef DEBUG
        std::cout << "[Q14] Initializing " << i << ".\n";
        #endif
        if (collatzlengths[i] == 0)
        {
            index = i;
            do
            {
                buffer.push(index);

                if (2 * (index / 2) == index)
                {
                    index = index / 2;
                }
                else 
                {
                    index = (3 * index) + 1;
                }

                // treat as unanalyzed if outside of range
                if (index > ub)
                {
                    j = 0;
                }
                else 
                {
                    k = (int) index;
                    j = collatzlengths[k];
                }
            }
            while (j == 0);

            for (k = 1; !buffer.empty(); ++k)
            {
                index = buffer.top();
                if (index < ub)
                {
                    collatzlengths[index] = j + k;
                }

                buffer.pop();
            }
        }
    }

    k = 1;
    j = 0;
    for (i = 1; i < bound; ++i)
    {
        if (j < collatzlengths[i])
        {
            j = collatzlengths[i];
            k = i;
        } 
    }

    std::cout << "[Q14] Longest collatz sequence under "
        << bound << " starts at " << k << ".\n";


    return 0;
}