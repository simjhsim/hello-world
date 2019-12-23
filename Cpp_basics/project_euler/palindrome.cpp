// palindrome.cpp

#include <iostream>

#include "palindrome.h"

// This script contains various functions tied to 
// palindromes.

// isIntPalindrome takes in an integer and returns -1
// if the input is negative, 1 if the input is a positive
// palindrome, and 0 otherwise.
int isIntPalindrome (int palcand)
{
    return isIntBasePalindrome(palcand, 10);
}

// isIntBasePalindrome does the same as isIntPalindrome
// except that it takes in another positive integer as a
// base and checks if the given palindrome candidate is 
// a palindrome when written in the given base.
int isIntBasePalindrome (int palcand, int base)
{
    int n,m,b;
    n = palcand;
    m = 0;
    b = base;

    if (n < 0 || b <= 1)
    {
        std::cout << "[ERROR] Invalid input given." <<
            " Integers must be positive and base > 1.\n";
        return -1;
    }

    // the function will construct the reverse of palcand
    // and test if the two numbers are equal

    while (n > 0)
    {
        m = (b * m) + (n % b); // shift m & add unit of n
        n = n / b;
    }

    std::cout << "Testing " << palcand << 
        " and " << m << ".\n";

    if (m == palcand)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}