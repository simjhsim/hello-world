// q8.cpp

// Problem: Largest product in a series
//
// What is the largest product of four consecutive digits
// in the 1000-digit number below?

// 73167176531330624919225119674426574742355349194934
// 96983520312774506326239578318016984801869478851843
// 85861560789112949495459501737958331952853208805511
// 12540698747158523863050715693290963295227443043557
// 66896648950445244523161731856403098711121722383113
// 62229893423380308135336276614282806444486645238749
// 30358907296290491560440772390713810515859307960866
// 70172427121883998797908792274921901699720888093776
// 65727333001053367881220235421809751254540594752243
// 52584907711670556013604839586446706324415722155397
// 53697817977846174064955149290862569321978468622482
// 83972241375657056057490261407972968652414535100474
// 82166370484403199890008895243450658541227588666881
// 16427171479924442928230863465674813919123162824586
// 17866458359124566529476545682848912883142607690042
// 24219022671055626321111109370544217506941658960408
// 07198403850962455444362981230987879927244284909188
// 84580156166097919133875499200524063689912560717606
// 05886116467109405077541002256983155200055935729725
// 71636269561882670428252483600823257530420752963450

// Takes in a positive integer n and string of integers
// and computes the largest product of n consecutive
// integers in the given string.

// #define DEBUG

#include <iostream>
#include <queue> 
#include <cstring>
#include <fstream>

long long int initialQueue (std::ifstream & inFile, int adj_num, 
    std::queue<long long int> & buff1);

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        std::cout << "[Q8] ERROR: Invalid number of "
            <<" inputs.\n";
        return -1;
    }

    // txt file input initialization
    std::ifstream inFile;
    inFile.open(argv[2]);
    if (!inFile)
    {
        std::cout << "[Q8] Unable to open given file: "
            << argv[2] << ".\n";
        exit(1);
    }

    int adj_num;
    long long int max_prod, buff_prod, front, back;
    char succ_char;
    std::queue<long long int> buff1;

    adj_num   = std::stoi(argv[1]);
    max_prod  = initialQueue(inFile, adj_num, buff1);
    buff_prod = max_prod;

    #ifdef DEBUG 
        std::cout << "[Q8:DEBUG] Initial value: "
            <<"(adj_num, "<<adj_num<<").\n";
        std::cout << "[Q8:DEBUG] Initial prod is " 
            << max_prod<< ".\n";
    #endif

    if (max_prod == -1)
    {
        std::cout << "[Q8] file has less than "
            << adj_num << " nonzero digits.\n";
        
        // txt file closure
        inFile.close();
        return 0;
    }

    while (!inFile.eof())
    {
        inFile.get(succ_char);
        // ignore non-numericals
        if (succ_char >= 48 && succ_char <= 57) 
        {
            // if 0, then iterate until nonzero queue
            if (succ_char == 48)
            {
                while (!buff1.empty())
                {
                    buff1.pop();
                }

                buff_prod = initialQueue(inFile, 
                    adj_num, buff1);
                
                // terminate if end of file is reached
                if (buff_prod == -1)
                {
                    std::cout << "[Q8] largest product is "
                        << max_prod << ".\n";
    
                    // txt file closure
                    inFile.close();

                    return 0;
                }
            }
            else 
            {
                front = buff1.front();
                back  = (long long int) succ_char - 48;
                buff1.pop();
                buff1.push(back);

                buff_prod = (buff_prod / front) * back;
                #ifdef DEBUG 
                    std::cout << "[Q8:DEBUG] "
                        << "Adding " << back
                        << " and removing " << front
                        << ".\n";
                    std::cout << "     "
                        << "buff_prod: "
                        << buff_prod << ".\n";
                    std::cout << "     "
                        << "max_prod:  "
                        << max_prod << ".\n";
                #endif
            }
        }

        if (buff_prod > max_prod)
        {
            max_prod = buff_prod;
        }
    }

    std::cout << "[Q8] largest product is " << max_prod 
        << ".\n";
    
    // txt file closure
    inFile.close();

    return 0;
}


// updates queue with adj_num digits from inFile and
// returns the product.
long long int initialQueue (std::ifstream & inFile, int adj_num, 
    std::queue<long long int> & buff1)
{
    char succ_char;
    int count;
    long long int prod, gamma;

    prod = 1;
    for (count = 0; count < adj_num; ++count)
    {
        inFile.get(succ_char);
        // ignore non-numericals
        while (succ_char <= 48 || succ_char > 57) 
        {
            if (inFile.eof())
            {
                std::cout << "[Q8:iQ] file has ended.\n";
                return -1;
            }

            if (succ_char == 48)
            {
                while (!buff1.empty())
                {
                    buff1.pop();
                }
                count = 0;
                prod = 1;
            }

            inFile.get(succ_char);
        }
        gamma = succ_char - 48;
        #ifdef DEBUG 
            std::cout << "[Q8:iQ:DEBUG] Adding "
                << gamma << ".\n";
        #endif
        buff1.push(gamma);
        prod *= gamma;
    }

    return prod;
}