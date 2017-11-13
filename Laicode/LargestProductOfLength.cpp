/*
 * Laicode_LargestProductOfLength.cpp

Given a dictionary containing many words, find the largest product of two words’ lengths,
such that the two words do not share any common characters.

Assumptions

The words only contains characters of 'a' to 'z'
The dictionary is not null and does not contains null string, and has at least two strings
If there is no such pair of words, just return 0
Examples

dictionary = [“abcde”, “abcd”, “ade”, “xy”], the largest product is 5 * 2 = 10 (by choosing “abcde” and “xy”)

 */

#include <vector>
#include <algorithm>

using namespace std;

int toBitMask(string word)
{
	int mask = 0;
	for(int i=0; i<word.length(); i++)
	{
		mask |= 1 << (word[i]-'a');
	}
	return mask;
}

// LC 318 Maximum Product of Word Length
int largestProduct(vector<string> dict)
{
	/*
	 * there are maximum 26 chars int the dict so we can use int to map the word
	 */
	vector<int> bitMask;
	for(string word : dict) bitMask.push_back(toBitMask(word));

	int maxProd = 0;

	for(int i=0; i<bitMask.size(); i++)
	{
		for(int j=i+1; j < bitMask.size(); j++)
		{
			if(bitMask[i] & bitMask[j] == 0)
			{
				int currProd = dict[i].length() * dict[j].length();
				maxProd = max(maxProd, currProd);
			}
		}
	}

	return maxProd;
}
