/******************************************************************************/
/*
* Question: #187 Repeated DNA Sequence
* company tag: LinkedIn
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
#include <map>
#include <unordered_map>

using namespace std;

// This is a sliding window + hashmap question
// there are 4 posibilities A, C, G, T then 2 bits is enough to represent the nucleotides
// then for a sequence of 10 nucleotides, an integer will be enough

// function that will clear off the first 2 bits of an integer (of 20 bits)
unsigned int eviction(unsigned int x)
{
	return x & (0xFFFFF);
}

// function that will add 2 bits as the last bits
unsigned int addition(unsigned int x, unsigned int a)
{
	return (x << 2) + a;
}


// A - 00(0), C - 01(1), G-10(2), T - 11(3) 
vector<string> findRepeatedDnaSequences(string s)
{
	vector<string> result;
	if (s.length() < 10) return result;
	unordered_map<unsigned int, int> table;
	map<char, unsigned int> dict;
	dict['A'] = 0;
	dict['C'] = 1;
	dict['G'] = 2;
	dict['T'] = 3;
	unsigned int curr = 0;
	// build the hash table
	for (int i = 0; i < s.length(); i++)
	{
		curr = addition(curr, dict[s[i]]);
		if (i >= 9)
		{
			if(i > 9) curr = eviction(curr);
			if (table[curr]++ == 1)
			{
				result.push_back(s.substr(i - 9, 10));
			}
		}
	}
	return result;
}

/*
int main(int argc, char * * argv)
{
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	vector<string>  result = findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	system("pause");
}
*/
