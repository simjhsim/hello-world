// bigInt.cpp

// Arbitrarily large integers

#include <iostream>

#include "bigInt.h"

// compare two BigInt10
// returns 1  if inp1 > inp2
//         0  if inp1 = inp2
//         -1 if inp1 < inp2
int bi10Comp(BigInt10 & inp1, BigInt10 & inp2)
{
    int comp;
    bool sign1, sign2;
    std::vector<int> digits1, digits2;

    sign1 = inp1.pos;
    sign2 = inp2.pos;

    digits1 = inp1.digits;
    digits2 = inp2.digits;

    if (sign1)
    {
        if (!sign2)
        {
            return 1;
        }

        if (digits1.size() > digits1.size())
        {
            return 1;
        }
        else if (digits1.size() < digits2.size())
        {
            return -1;
        }
        else 
        {
            while (!digits1.empty())
            {
                comp = digits1.back() - digits2.back();

                if (comp > 0)
                {
                    return 1;
                }
                else if (comp < 0)
                {
                    return -1;
                }
            }

            return 0;
        }
    }
    else 
    {
        if (sign2)
        {
            return -1;
        }

        if (digits1.size() > digits1.size())
        {
            return -1;
        }
        else if (digits1.size() < digits2.size())
        {
            return 1;
        }
        else 
        {
            while (!digits1.empty())
            {
                comp = digits1.back() - digits2.back();

                if (comp > 0)
                {
                    return -1;
                }
                else if (comp < 0)
                {
                    return 1;
                }
            }

            return 0;
        }
    }
}

// adds the absolute value of the two given inputs
int bi10absPlus(BigInt10 & inp1, BigInt10 & inp2, 
    BigInt10 & sum)
{
    sum.pos = true;
    std::vector <int> digits1, digits2, digitssum;
    digits1 = inp1.digits;
    digits2 = inp2.digits;

    int digsum, carry;
    carry = 0;

    while (!(digits1.empty()) && !(digits2.empty()))
    {
        digsum = digits1.front() + digits2.front() + carry;

        digits1.erase(digits1.begin());
        digits2.erase(digits2.begin());

        carry = digsum / 10;
        digsum = digsum % 10;

        digitssum.push_back(digsum);
    }

    if (!digits1.empty())
    {
        while (!digits1.empty())
        {
            digsum = digits1.front() + carry;

            digits1.erase(digits1.begin());

            carry = digsum / 10;
            digsum = digsum % 10;

            digitssum.push_back(digsum);
        }
    }
    else if (!digits2.empty())
    {
        while (!digits2.empty())
        {
            digsum = digits2.front() + carry;

            digits2.erase(digits2.begin());

            carry = digsum / 10;
            digsum = digsum % 10;

            digitssum.push_back(digsum);
        }
    }

    sum.digits = digitssum;
    return 0;
}

// subtracts the absolute value of the two given inputs
// assuming the first is greater than the second
int bi10absMinus(BigInt10 & inp1, BigInt10 & inp2, 
    BigInt10 & diff)
{
    diff.pos = true;
    std::vector <int> digits1, digits2, digitsdiff;
    digits1 = inp1.digits;
    digits2 = inp2.digits;

    int digdiff, carry;
    carry = 0;

    while (!(digits1.empty()) && !(digits2.empty()))
    {
        digdiff = digits1.front() - digits2.front() + carry;

        digits1.erase(digits1.begin());
        digits2.erase(digits2.begin());

        if (digdiff < 0)
        {
            carry = -1;
        }
        digdiff = digdiff % 10;

        digitsdiff.push_back(digdiff);
    }

    if (!digits1.empty())
    {
        while (!digits1.empty())
        {
            digdiff = digits1.front() + carry;

            digits1.erase(digits1.begin());

            if (digdiff < 0)
            {
                carry = -1;
            }
            digdiff = digdiff % 10;

            digitsdiff.push_back(digdiff);
        }
    }

    diff.digits = digitsdiff;
    return 0;
}

// addition of two BigInt10
int bi10Plus(BigInt10 & summand1, BigInt10 & summand2,
    BigInt10 & sum)
{
    BigInt10 absplus, abs1, abs2;

    
    abs1.digits = summand1.digits;
    abs2.digits = summand2.digits;
    abs1.pos = true;
    abs2.pos = true;

    // eliminate when summands have same sign
    if (summand1.pos == summand2.pos)
    {
        bi10absPlus(abs1,abs2,sum);
        sum.pos = summand1.pos;
        return 0;
    }

    // the signs are assumed to be different below
    int comp = bi10Comp(abs1,abs2);

    if (comp > 0)
    {
        bi10absMinus(abs1,abs2,sum);
        sum.pos = summand1.pos;
        return 0;
    }
    else 
    {
        bi10absMinus(abs2,abs1,sum);
        sum.pos = summand2.pos;
        return 0;
    }


    return 1;
}

// difference of two BigInt10
int bi10Minus(BigInt10 & summand1, BigInt10 & summand2,
    BigInt10 & diff)
{
    BigInt10 nsummand2;

    nsummand2.digits = summand2.digits;
    nsummand2.pos = (!(summand2.pos));
    
    return bi10Plus(summand1,nsummand2,diff);
}

// product of a BigInt10 with an int
int bi10ProdInt(BigInt10 & factor1, int factor2, 
    BigInt10 & prod)
{
    if (factor2 == 0)
    {
        prod.pos = true;
        (prod.digits).clear();
        (prod.digits).push_back(0);
        return 0;
    }

    std::vector <int> digs, pdigs;
    digs = factor1.digits;
    int buff, carry, abs2;    
    carry = 0;
    
    if (factor2 > 0)
    {
        prod.pos = factor1.pos;
        abs2 = factor2;
    }
    else 
    {
        prod.pos = (!(factor1.pos));
        abs2 = (-1) * factor2;
    }

    while (!(digs.empty()))
    {
        buff = (abs2 * (digs.front())) + carry;
        carry = buff / 10;
        buff = buff % 10;

        pdigs.push_back(buff);
        digs.erase(digs.begin());
    }

    while (carry > 0)
    {
        buff = carry % 10;
        carry = carry / 10;

        pdigs.push_back(buff);
    }

    prod.digits = pdigs;

    return 0;
}

// product of two BigInt10
int bi10Prod(BigInt10 & factor1, BigInt10 & factor2,
    BigInt10 & prod)
{
    BigInt10 buff_prod, abs1, abs2, buff_sum;

    // set sign
    prod.pos = (factor1.pos == factor2.pos);
    prod.digits.clear();

    abs1.pos = true;
    abs2.pos = true;
    abs1.digits = factor1.digits;
    abs2.digits = factor2.digits;

    buff_sum.pos = true;
    buff_sum.digits.clear();
    buff_sum.digits.push_back(0);

    int i, j, comp;

    comp = bi10Comp(abs1,abs2);
    i = 0;

    // make abs2 < abs1
    if (comp < 0)
    {
        abs1.digits.swap(abs2.digits);
    }

    while (!abs2.digits.empty())
    {
        if (bi10ProdInt(abs1, abs2.digits.front(), 
            buff_prod) != 0)
        {
            return 1;
        }

        buff_prod.digits.insert(buff_prod.digits.begin(), 
            i, 0);
        
        bi10Plus(buff_sum, buff_prod, buff_sum);

        ++i;
    }

    prod.digits.swap(buff_sum.digits);

    return 0;
}

// exponentiation of two BigInt10
int bi10Exp(BigInt10 & base, int pow, BigInt10 & exp)
{
    if (pow < 0)
    {
        std::cout << "[BI:EXP] ERROR: negative exponent "
            << "given.\n";
        return -1;
    }
    else if (pow == 0)
    {
        exp.pos = true;
        exp.digits.clear();
        exp.digits.push_back(1);
        return 0;
    }

    BigInt10 prod, buff_exp;

    buff_exp.pos = true;
    buff_exp.digits.push_back(1);

    for (int i = 0; i < pow; ++i)
    {
        prod = buff_exp;
        if (0 !=bi10Prod(base, prod, buff_exp))
        {
            std::cout << "[BI:EXP] ERROR: problem "
                << "exponentiating.\n";
            return 1;
        }
    }

    exp.digits = buff_exp.digits;
    exp.pos = buff_exp.pos;

    return 0;
}