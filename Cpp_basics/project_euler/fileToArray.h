// fileToArray.cpp

// Takes in a file of text and alters the file into a
// specified type of array.

#ifndef FILE_TO_ARRAY_H
#define FILE_TO_ARRAY_H 

// fileToIntArray
// takes in a file pointer to a file of integers and a 
// pre-allocated array and fills the array with the text.
// The text is assumed to be in ascii and converted to 
// integers.
int fileToIntArray(std::ifstream & inFile, int row,
    int column, std::vector< std::vector<int> > & arr);


#endif