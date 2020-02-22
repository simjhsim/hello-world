// test.cpp

// This is a sandbox to test out various implemented
// functions.
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "bigInt.h"

int main (int argc, char** argv)
{
    int num_errors = 0;

    // initialize variables
    std::vector <int> digits1, digits2;

    digits1.push_back(1);
    digits1.push_back(1);

    digits2.push_back(0);

    BigInt10 bint1, bint2, suma, diffa, sum, diff, prodb, 
        prod;

    bint1.pos = true;
    bint2.pos = true;
    bint1.digits = digits1;
    bint2.digits = digits2;

    bi10absPlus(bint1, bint2, suma);
    bi10absMinus(bint1, bint2, diffa);
    bi10Plus(bint1,bint2,sum);
    bi10Minus(bint1,bint2,diff);
    bi10Prod(bint1, bint2, prodb);
    bi10ProdInt(bint1, 0, prod);

    // count errors
    
}