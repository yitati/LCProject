/******************************************************************************
* Question: #438 Find All Anagrams In a String
* company tag: Amazon
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

*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// the idea is to keep a "difference table", when the table size is zeor, then we found
// one valid anagram

vector<int> findAnagrams(string s, string p)
{
	vector<int> result;
	int plen = p.length(), slen = s.length();
	unordered_map<char, int> diff;
	for(char c : p) diff[c]++;
	int count = diff.size();
	int lhs = 0, rhs = 0;
	while(rhs < s.length())
	{
		if(diff.count(s[rhs]))
		{
			diff[s[rhs]]--;
			if(diff[s[rhs]] == 0) count--;
			else if(diff[s[rhs]] == -1) count++;
		}
		rhs++;
		// fix the length
		while(rhs - lhs > plen)
		{
			if(diff.count(s[lhs]))
			{
				diff[s[lhs]]++;
				if(diff[s[lhs]] == 0) count--;
				else if(diff[s[lhs]] == 1) count++;
			}
			lhs++;
		}
		if(count == 0)
		{
			result.push_back(lhs);
		}
	}
	return result;
}
