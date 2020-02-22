// bigInt.h

// Arbitrarily large integers
#ifndef BIG_INT_H
#define BIG_INT_H

#include <vector>

// BigInt10
// structure for arbitrarily large integers
// digits stores number's digits in base 10 from least
// significant to most
// neg is true if positive and false if negative
struct BigInt10
{
    std::vector <int> digits;
    bool pos;
};

// compare two BigInt10
// returns 1  if inp1 > inp2
//         0  if inp1 = inp2
//         -1 if inp1 < inp2
int bi10Comp(BigInt10 & inp1, BigInt10 & inp2);

// adds the absolute value of the two given inputs
int bi10absPlus(BigInt10 & inp1, BigInt10 & inp2, 
    BigInt10 & sum);

// subtracts the absolute value of the two given inputs
// assuming the first is greater than the second
int bi10absMinus(BigInt10 & inp1, BigInt10 & inp2, 
    BigInt10 & diff);

// addition of two BigInt10
int bi10Plus(BigInt10 & summand1, BigInt10 & summand2,
    BigInt10 & sum);

// difference of two BigInt10
int bi10Minus(BigInt10 & summand1, BigInt10 & summand2,
    BigInt10 & diff);

// product of a BigInt10 with an int
int bi10ProdInt(BigInt10 & factor1, int factor2, 
    BigInt10 & prod);

// product of two BigInt10
int bi10Prod(BigInt10 & factor1, BigInt10 & factor2,
    BigInt10 & prod);

// exponentiation of two BigInt10
int bi10Exp(BigInt10 & base, int pow, BigInt10 & exp);


#endif