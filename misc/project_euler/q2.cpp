// q2.cpp

// Problem: Even Fibonacci numbers
// 
// By considering the terms in the Fibonacci sequence whose
// values do not exceed four million, find the sum of the
// even-valued terms.

// Takes in three arguments n1, n2, b where n1 
// and n2 are the two beginning terms of the
// Fibonacci sequence and b is the bound.
// The main function returns the sum of all
// terms below the bound that are even.


#include <iostream>
#include <string>

#include "sumFibonacci.h"

int main (int argc, char** argv) 
{
    if (argc == 4) 
    {
        int n1, n2, b;

        n1 = std::stoi (argv[1]);
        n2 = std::stoi (argv[2]);
        b  = std::stoi (argv[3]);

        if (n1 <= 0 || n2 <= 0)
        {
            std::cout << "[ERROR] invalid initial values.\n";
            return -1;
        }
        else
        {
            int totalsum;

            totalsum = sumFibonacci(n1,n2,b);

            std::cout << "The sum of even terms of the "
            << "Fibonacci starting with " << n1 << " and "
            << n2 << " is " << totalsum << ".\n";
        }
    }
    else 
    {
        std::cout << "[ERROR] wrong number of arguments.\n";

        return -3;
    }
}

