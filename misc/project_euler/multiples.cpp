// multiples.cpp

#include <iostream>

#include "myMath.h"
#include "multiples.h"

// leastCommonMultipleCap takes in a positive integer 
// and returns the least common multiple of all positive
// integers less than or equal to the given integer
int leastCommonMultipleCap (int cap)
{
    // std::cout << "[LCMcap] entering with " << cap << ".\n";
    if (cap <= 1)
    {
        // std::cout << "[LCMcap] base case.\n";
        return 1;
    }
    else 
    {
        return leastCommonMultiple(cap, 
            leastCommonMultipleCap(cap - 1));
    }
}



