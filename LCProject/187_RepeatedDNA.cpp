/******************************************************************************/
/*
* Question: #187 Repeated DNA Sequence
* All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
* for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
* Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
/*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// This is a sliding window + hashmap question
// there are 4 posibilities A, C, G, T then 2 bits is enough to represent the nucleotides
// then for a sequence of 10 nucleotides, an integer will be enough
vector<string> findRepeatedDnaSequences(string s)
{

}