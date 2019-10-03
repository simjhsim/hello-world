// q1.cpp

// Problem: Multiples of 3 and 5
// 
// If we list all the natural numbers below 10 that are 
// multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of 
// these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.


// Takes in three arguments n1, n2, bound and 
// returns the sum of all multiples of n1 and
// n2 less than the bound, assuming that n1 and
// n2 are positive integers


#include <iostream>
#include <string>

#include "multSum.h"

int main (int argc, char** argv) 
{
    if (argc == 4) 
    {
        int n1, n2, bound, m;

        n1 = std::stoi (argv[1]);
        n2 = std::stoi (argv[2]);
        
        // subtract 1 to get sum of multiples strictly less
        // than the given bound.
        bound = (std::stoi (argv[3])) - 1;

        m = lcm(n1, n2);

        std::cout << "The lcm of n1 and n2 is: " << m <<".\n";

        int s1, s2, s3, s;

        s1 = multSum(n1, bound);
        s2 = multSum(n2, bound);
        s3 = multSum(m,  bound);

        std::cout << "s1: " << s1 << ".\n";
        std::cout << "s2: " << s2 << ".\n";
        std::cout << "s3: " << s3 << ".\n";

        s = s1 + s2 - s3;

        std::cout << "The sum is: " << s << ".\n";

        return s;
    }
    else 
    {
        std::cout << "[ERROR] wrong number of arguments.\n";

        return -1;
    }
}

