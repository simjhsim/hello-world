// myMath.h

// Recurring and useful math functions.
// Index:
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
// powint 
//      - integer power function

#ifndef MYMATH_H
#define MYMATH_H

// powint computes a^b where a is an integer, b is a 
// nonnegative integer, and ^ is the exponential function.
int powint (int a, int b);

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


#endif