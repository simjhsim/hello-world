// fileToArray.cpp

// Takes in a file of text and alters the file into a
// specified type of array.

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

#include "fileToArray.h"

// fileToIntArray
// takes in a file pointer to a file of integers and a 
// pre-allocated array and fills the array with the text.
// The text is assumed to be in ascii and converted to 
// integers.
int fileToIntArray(std::ifstream & inFile, int row,
    int column, std::vector< std::vector<int> > & arr)
{
    int i,j,r,c,n;
    c = column;
    r = row;

    std::vector<int> buff_row;

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < column; ++j)
        {
            if (inFile >> n)
            {
                buff_row.push_back(n);
            }
            else
            {
                std::cout << "[FTIA] Reached end of file "
                    << "prior to end of array.\n";
                return -1;
            }
        }

        arr.push_back(buff_row);

        while (!buff_row.empty())
        {
            buff_row.pop_back();
        }
    }

    #ifdef DEBUG
        std::cout << "[FTIA] Array initializaed from file "
            << "with the first " << (r*c) << " values.\n";
    #endif
    return 0;
}