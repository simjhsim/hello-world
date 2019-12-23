// test.cpp

// This is a sandbox to test out various implemented
// functions.
#include <iostream>
#include <string>

#include "myMath.h"

int main (int argc, char** argv)
{
    int n,m;
    n = std::stoi(argv[1]);
    m = std::stoi(argv[2]);

    std::cout << "[TEST] Consecutive sum between " << n
        << " and " << m << " is " << consSum(n,m) <<".\n";

    return 0;
}