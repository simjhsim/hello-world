// q4.cpp

// Problem: Largest palindrome product
// 
// Find the largest palindrome made from the product of 
// two 3-digit numbers.

// Takes in a positive integer n > 1 and finds the largest 
// palindrome made from the product of two n-digit integers.

// Notice that (10^(n-1)+1)^2 is a palindrome, so there will
// always be at least one palindrome.


#include <iostream>
#include <string>

#include "palindrome.h"
#include "myMath.h"

int main (int argc, char** argv) 
{
    // Given positive integer n > 1
    int n = std::stoi(argv[1]);
    int a, b, c, prodinit, cand, bound, prodcand;

    std::cout << "Finding palindrome with " << n << 
        " digits.\n";

    a     = powint(10, n);
    b     = powint(10, n) - 1;
    c     = 0;
    bound = powint(10, n-1);
    cand  = 0;

    // iterate down from (10^n - 1) to find the pair (a,b) 
    // of n-digit integers whose product is a palindrome 
    // with the largest a.
    do
    {
        a = a - 1;
        b = a;
        prodinit = a * b;
        while (!isIntPalindrome(prodinit))
        {
            b = b - 1;
            prodinit = a * b;
        }

        std::cout << "Palindrome pair found: ("
            << a << "," << b << ").\n";

        cand = b;
    }
    while (cand < bound);

    for (prodcand = prodinit; a > b; a--)
    {
        for (c = a; c > b; c--)
        {
            prodcand = a * c;
            if (isIntPalindrome(prodcand))
            {
                if (prodinit < prodcand)
                {
                    prodinit = prodcand;
                }
                // found one palindrome, so remaining c
                // will only find smaller palindromes.
                break; 
            }
        }
    }

    std::cout << "The largest palindrome that is a product"
        << " of two " << n << " digit integers is " 
        << prodinit << ".\n";

    return 0;
}

