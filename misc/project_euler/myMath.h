// myMath.h

// Recurring and useful math functions.
// Index:
// aChooseb
//      - a choose b (returns long long int).
// arithSum
//      - arithmetic sum.
// consSum
//      - consecutive sum.
// greatestCommonFactor
//      - find the greatest common factor between two 
//          integers.
// leastCommonMultiple 
//      - finds the least common multiple of two integers.
// logint
//      - finds greatest integer less than log_a(b).
// numDivisors
//      - find number of divisors of a prime factorization.
// powint 
//      - integer power function.
// powllint
//      - long long int power function.
// primeFactors
//      - finds prime factorization of integer.

#ifndef MYMATH_H
#define MYMATH_H

struct IntPair
{
    int x;
    int y;
};

// powint computes a^b where a is an integer, b is a 
// nonnegative integer, and ^ is the exponential function.
int powint (int a, int b);

// powllint computes a^b where a is an integer, b is a 
// nonnegative integer, and ^ is the exponential function.
long long int powllint (long long int a, long long int b);

// greatestCommonFactor takes in two positive integers
// and returns their greatest common factor
int greatestCommonFactor (int a, int b);

// leastCommonMultiple takes in two positive integers
// and returns their least common multiple
int leastCommonMultiple (int a, int b);

// arithSum takes in two integers (a,b) and a positive 
// integer d and sums up the arithmetic sequence starting
// from a with difference d bounded by (including) b.
int arithSum (int a, int b, int d);

// consSum takes in two integers (a,b) and returns the
// sum of all integers between and a and b (inclusive).
int consSum (int a, int b);

// logint takes in a and b and computes the greatest
// integer less than log_a(b).
int logint (int a, int b);

// primeFactors takes in an empty vector of integer pairs 
// and a positive integer and fills the vector with the 
// prime factors and their multiplicities.
int primeFactors (std::vector<struct IntPair> & factors, 
    int num);

// numDivisors takes in a vector of integer pairs
// representing the prime factorization of a number and
// returns the number of divisors the number has.
int numDivisors (std::vector<struct IntPair> & pfactors);

// aChooseb computes the number of choices of b elements
// in a set of a unique elements. (optimized to reduce
// overflow)
long long int aChooseb (int a, int b);

#endif