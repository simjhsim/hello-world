// q11.cpp

// Problem: Largest product in a grid
//
// Find the greatest product of four adjacent numbers
// in the same direction (up, down, left, right, or 
// diagonally) from the given 20 x 20 grid.

// Create an array from the given grid and find largest
// product. Only need to check the right, down, down-right,
// and up-right.

// #define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "fileToArray.h"


int main (int argc, char** argv)
{
    // initialize vector array
    std::ifstream inFile;

    inFile.open("20x20grid_q11.txt");

    if (!inFile)
    {
        std::cout << "[Q11] Unable to open given file.\n";
        exit(1);
    }

    std::vector< std::vector<int> > arr;

    if (fileToIntArray(inFile, 20, 20, arr) != 0)
    {
        std::cout << "[Q11] Unsuccessful array init.\n";
        return -1;
    }

    inFile.close();

    int i, j;
    int k, prod_r, prod_d, prod_rd, prod_ld;
    int max_prod;

    max_prod = 1;

    for (i = 0; i < 20; ++i)
    {
        for (j = 0; j < 20; ++j)
        {
            prod_r  = 1;
            prod_rd = 1;
            prod_d  = 1;
            prod_ld = 1;
            #ifdef DEBUG
                std::cout << "[Q11] Starting at (" << i 
                    << "," << j << "): entry "<< arr[i][j] 
                    << ".\n";
            #endif

            // right product
            if (j < 17)
            {
                for (k = 0; k < 4; ++k)
                {
                    prod_r *= arr[i][j+k];
                }

                if (max_prod < prod_r)
                {
                    max_prod = prod_r;
                }

                // right-down product
                if (i < 17)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        prod_rd *= arr[i+k][j+k];
                    }

                    if (max_prod < prod_rd)
                    {
                        max_prod = prod_rd;
                    }
                }
            }

            // down product
            if (i < 17)
            {
                for (k = 0; k < 4; ++k)
                {
                    prod_d *= arr[i+k][j];
                }

                if (max_prod < prod_d)
                {
                    max_prod = prod_d;
                }

                // left-down product
                if (j >= 3)
                {
                    for (k = 0; k < 4; ++k)
                    {
                        prod_ld *= arr[i+k][j-k];
                    }

                    if (max_prod < prod_ld)
                    {
                        max_prod = prod_ld;
                    }
                }
            }
        }
    }

    std::cout << "[Q11] The maximum product of four "
        << "adjacent entries of the grid is: "
        << max_prod << ".\n";

    return 0;
}