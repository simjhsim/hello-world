// q5.cpp

// Problem: smallest multiple
//
// What is the smallest positive number that is divisble
// by all of the numbers from 1 to 20?

// Takes in integer n > 1 and returns the smallest positive
// integer that is divisible by all integers between 1 and
// n.

#include <iostream>
#include <string>

#include "multiples.h"

int main (int argc, char** argv)
{
    // Given positive integer cap > 1
    int cap = std::stoi(argv[1]);
    int mult;

    std::cout << "Finding LCMcap with cap " << cap << ".\n";
    mult = leastCommonMultipleCap(cap);

    std::cout << "The least common multiple of all positive"
        << " integers less than " << cap << " is " 
        << mult << ".\n";

    return 0;
}