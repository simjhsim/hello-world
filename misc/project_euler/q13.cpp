// q13.cpp

// Problem: Large Sum
//
// Work out the first ten digits of the sum of the
// following one-hundred 50-digit numbers.

// The program will take a text file of n numbers, 
// each with m-digits with no leading zeros, and num
// for the number of digits we want. The implementation
// uses the fact the the first num digits of the sum
// cannot be affected by digits less than a number
// dependent on n, m, and num.

// Assume that num + 2 < m

#define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "myMath.h"


int main (int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "[Q13] Invalid input. q13.exe requires"
            << " two parameters:"
            << " number_of_digits_requested"
            << " text_file_of_summands.txt \n";
        exit(1);
    }

    std::ifstream inFile;

    inFile.open(argv[2]);

    if (!inFile)
    {
        std::cout << "[Q13] Unable to open given file.\n";
        exit(2);
    }

    long long int sum, summand, mask;
    int i, num, a;
    char dig;

    num  = std::stoi(argv[1]);
    sum  = 0;
    a    = num + 3;
    mask = powllint(10, num);

    while (!inFile.eof())
    {
        summand = 0;

        // get first a digits of file
        for (i = 0; i < a; ++i)
        {
            inFile.get(dig);

            std::cout << "[Q13] Reading char: " << dig
                << "\n";

            // if non-numeric, break the for loop
            if (dig < 48 || dig > 57)
            {
                break;
            }

            summand = (summand * 10) + (dig - 48);
        }

        std::cout << "[Q13] Adding " << summand << ".\n";

        // add summand to sum
        sum += summand;

        // run through file until a non-numeric is hit
        while (dig >= 48 && dig <= 57)
        {
            if (inFile.eof())
            {
                break;
            }
            std::cout << "[Q13] Ignoring: " << dig << "\n";
            inFile.get(dig);
        }
    }

    std::cout << "[Q13] The sum is: "<< sum << ".\n";

    std::cout << "[Q13] The mask is: " << mask << ".\n";

    while (sum >= mask)
    {
        sum = sum / 10;
    }

    std::cout << "[Q13] The first " << num 
        << " digits of the sum is: "
        << sum << ".\n";

    inFile.close();

    return 0;
}