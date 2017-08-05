/******************************************************************************/
/*
* Question: #318 Maximum Product of Word Length
* Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where 
* the two words do not share common letters. You may assume that each word will contain only lower case letters. 
* If no such two words exist, return 0. 
Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn". 
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 Return 4
 The two words can be "ab", "cd". 
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
 Return 0
 No such pair of words. 
*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int maxProduct(vector<string>& words)
{
	vector<int> bitTable(words.size());
	int maxProduct = 0;

	for (int i = 0; i < words.size(); i++)
	{
		int toInt = 0;
		string str = words[i];
		for (char c : str)
		{
			toInt |= 1 << (c - 'a');
		}
		bitTable[i] = toInt;
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = i + 1; j < words.size(); j++)
		{
			if ((bitTable[i] & bitTable[j]) == 0)
			{
				maxProduct = max(maxProduct, (int)(words[i].length() * words[j].length()));
			}
		}
	}

	return maxProduct;
}
