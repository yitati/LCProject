/******************************************************************************/
/*
* Question: #438 Find All Anagrams In a String
* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
* Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
* The order of output does not matter.

Example 1: 
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2: 
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// the idea is to keep a "difference table", when the table size is zeor, then we found
// one valid anagram

vector<int> findAnagrams(string s, string p) 
{
	unordered_map<char, int> diff;
	vector<int> result;
	int pLen = p.length(), sLen = s.length();

	for (int i = 0; i < pLen; i++)
	{
		diff[p[i]]++;
	}

	for (int i = 0; i < sLen; i++)
	{
		diff[s[i]]--;
		if (diff[s[i]] == 0)
		{
			diff.erase(s[i]);
			if (diff.empty())
			{
				result.push_back(i - pLen + 1);
			}
		}
		if (i - pLen + 1 >= 0)
		{
			diff[s[i - pLen + 1]]++;
		}
	}

	return result;
}