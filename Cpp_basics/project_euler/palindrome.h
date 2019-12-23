// palindrome.h

#ifndef PALINDROME_H
#define PALINDROME_H

// palindrome.cpp contains various functions tied to 
// palindromes.

// isIntPalindrome takes in an integer and returns -1
// if the input is negative, 0 if the input is positive
// but not a palindrome, and 1 if the input is a positive
// palindrome.
int isIntPalindrome (int palcand);

// isIntBasePalindrome does the same as isIntPalindrome
// except that it takes in another positive integer as a
// base and checks if the given palindrome candidate is 
// a palindrome when written in the given base.
int isIntBasePalindrome (int palcand, int base);

#endif