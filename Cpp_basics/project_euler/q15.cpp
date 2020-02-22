// q15.cpp

// Problem: Lattic paths
//
// Starting in the top left corner of a 20x20 grid and 
// only moving right and down by 1, how many routes are
// there?

// Every such path is a permutation of 20 movements in the
// right-ward direction and 20 movements down-ward 
// direction. Thus, the total comes to 40!/(20!)(20!).
// Generalizing this implementation to an n x m grid,
// we can take (n+m)! / (n!)(m!), i.e. (n+m) choose n.

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
        std::cout << "[Q15] Invalid input. q15.exe requires"
            << " two parameters:"
            << " width_of_lattice"
            << " length_of_lattice\n";
        exit(1);
    }

    long long int routes;
    int n, m;

    n = std::stoi(argv[1]);
    m = std::stoi(argv[2]);

    routes = aChooseb(n+m,m);

    std::cout << "[Q15] The number of routes in an "
        << n << "x" << m << " lattice is: "
        << routes << ".\n";

    return 0;
}