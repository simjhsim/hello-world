// q6.cpp

// Problem: sum square difference
//
// What is the difference between the sum of the squares 
// of the first one hundred natural numbers and the square 
// of the sum.

// Takes in integer n > 1 and returns the difference
// between the sum of the square of the first n positive
// integers and the square of the sum.

#include <iostream>
#include <string>

#include "myMath.h"

int main (int argc, char** argv)
{
    int i, j, n, sum;
    n = std::stoi(argv[1]);
    sum = 0;
    
    // the difference we are looking for is the non square
    // terms of (1+...+n)^2.
    for (i = 1; i < n; i++)
    {
        sum = sum + (i * consSum(i+1, n));
    }

    sum = sum * 2;

    std::cout << "[Q6] The difference is " << sum << ".\n";

    return 0;
}