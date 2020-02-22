// q17.cpp

// Problem: Number letter counts
//
// How many letters are used to write out all natural 
// numbers from 1 to 1000? (spaces and hyphens don't count)

#define DEBUG

#include <iostream>
#include <string>


int main (int argc, char** argv)
{
    int tens [10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
    int hundred, two_dig, teens, ones, final;

    hundred = 10; // "hundred and"
    ones    = 36; // "one" through "nine"
    teens   = 70; // "ten" through "nineteen"

    two_dig = 0;
    for (int i = 2; i < 10; ++i)
    {
        two_dig +=  (10 * (tens[i])) + ones;
    }
    two_dig += ones + teens;

    final = (two_dig * 10) + (100 * ((hundred * 9) + ones))
        - 27 + 11;

    std::cout << "[Q17] There are " << final << " letters.\n";

    return 0;
}