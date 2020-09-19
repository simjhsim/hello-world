// q18.cpp

// Problem: Maximum path sum I
//
// In the given triangle of numbers, what is the maximum
// sum of numbers in the path from top to bottom?

//                              75
//                            95  64
//                          17  47  82
//                        18  35  87  10
//                      20  04  82  47  65
//                    19  01  23  75  03  34
//                  88  02  77  73  07  63  67
//                99  65  04  28  06  16  70  92
//              41  41  26  56  83  40  80  70  33
//           41  48  72  33  47  32  37  16  94  29
//         53  71  44  65  25  43  91  52  97  51  14
//       70  11  33  28  77  73  17  78  39  68  17  57
//     91  71  52  38  17  14  91  43  58  50  27  29  48
//   63  66  04  68  89  53  67  30  73  16  69  87  40  31
// 04  62  98  27  23  09  70  98  73  93  38  53  60  04  23

// We iterate through elements starting from the top and 
// add the maximum from the top-adjacent elements. For
// example, if we have 25 and the top-left space has 2
// stored and the top-right space has 10 stored, then
// we store 35 in the corresponding space. The maximum sum
// is then the maximum of the bottom row of corresponding
// spaces.

#define DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main (int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "[Q14] Invalid input. Requires"
            << " triangle_file.txt.\n";
        return 1;
    }

    std::ifstream inFile;
    std::vector <int> triangle;
    std::vector <int> buffer_row1, buffer_row2, ind_row;
    std::vector <std::vector <int>> max_triangle;
    std::vector <std::vector <int>> given_triangle;

    inFile.open(argv[1]);

    if (!inFile)
    {
        std::cout << "[Q13] Unable to open given file.\n";
        exit(2);
    }

    int i, j, levels, num_elem, init, max1, max2;

    // initialize triangle from text file 
    // (make sure the result is a triangle)
    num_elem = 0;
    while (inFile >> max1)
    {
        ++num_elem;
        triangle.push_back(max1);
        #ifdef DEBUG
            std::cout << "[Q18:DEBUG] Adding " << max1
                << ".\n";
        #endif
    }
    #ifdef DEBUG 
        std::cout << "[Q18:DEBUG] Total number of integers "
            << num_elem << ".\n";
    #endif

    inFile.close();

    levels = 1;
    for (levels = 1; levels * (levels + 1) / 2 < num_elem; 
        ++levels)
    {
        #ifdef DEBUG
            std::cout << "[Q18:DEBUG] Level is more than "
            << levels << ".\n";
        #endif
    }


    // initialize row
    #ifdef DEBUG
        std::cout << "[Q18:DEBUG] Initializing pyramid.\n";
    #endif
    for (i = 0; i < levels; ++i)
    {
        init = i * (i + 1) / 2;
        for (j = 0; j <= i; ++j)
        {
            buffer_row1.push_back(triangle[init + j]);
        }

        given_triangle.push_back(buffer_row1);

        // empty buffer_row
        buffer_row1.clear();
    }

    // initialize first row of max_triangle
    #ifdef DEBUG
        std::cout << "[Q18:DEBUG] Initializing 1st row "
            << "of max_triangle.\n";
    #endif
    max_triangle.push_back(given_triangle[0]);

    // iterate through rows of given_triangle to fill in
    // max_triangle's rows
    #ifdef DEBUG
        std::cout << "[Q18:DEBUG] Initializing remaining "
            << "rows.\n";
    #endif
    for (i = 1; i < levels; ++i)
    {
        buffer_row1 = max_triangle[i - 1];
        ind_row = given_triangle[i];

        // first entry
        max2 = buffer_row1[0];
        buffer_row2.push_back(max2 + ind_row[0]);
        #ifdef DEBUG
            std::cout << "[Q18:DEBUG] Adding "
                << (max2 + ind_row[0]) 
                <<" to row " << i << ".\n";
        #endif

        // middle entries
        for (j = 1; j < i; ++j)
        {
            max1 = max2;
            max2 = buffer_row1[j];

            if (max1 < max2)
            {
                buffer_row2.push_back(max2 + ind_row[j]);
                #ifdef DEBUG
                    std::cout << "[Q18:DEBUG] Adding "
                        << (max2 + ind_row[j]) 
                        <<" to row " << i << ".\n";
                #endif
            }
            else 
            {
                buffer_row2.push_back(max1 + ind_row[j]);
                #ifdef DEBUG
                    std::cout << "[Q18:DEBUG] Adding "
                        << (max1 + ind_row[j]) 
                        <<" to row " << i << ".\n";
                #endif
            }
        }

        // final entry
        buffer_row2.push_back(max2 + ind_row[i]);
        #ifdef DEBUG
            std::cout << "[Q18:DEBUG] Adding "
                << (max2 + ind_row[i]) 
                <<" to row " << i << ".\n";
        #endif

        max_triangle.push_back(buffer_row2);

        buffer_row2.clear();
    }

    // iterate through last level
    max1 = 0;
    buffer_row1 = max_triangle[levels-1];
    for (j = 0; j < levels; ++j)
    {
        max2 = buffer_row1[j];
        if (max1 < max2)
        {
            max1 = max2;
        }
    }

    std::cout << "[Q18] The maximum path sum of the "
        << "given triangle of integers is: "
        << max1 << ".\n";

    return 0;
}