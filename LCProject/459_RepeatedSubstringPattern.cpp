/******************************************************************************/
/*
* Question: #459 Repeated Substring Pattern
* Given a non-empty string check if it can be constructed by taking a substring of it and appending 
* multiple copies of the substring together. You may assume the given string consists of lowercase 
* English letters only and its length will not exceed 10000. 

Example 1:
Input: "abab"
Output: True
Explanation: It's the substring "ab" twice.

Example 2:
Input: "aba"
Output: False

Example 3:
Input: "abcabcabcabc"
Output: True
Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
*/
/*****************************************************************************/
#include <string>

using namespace std;

// brutal force solution
bool repeatedSubstringPattern(string s)
{
	// brutal force, check every possible substrings by there length
	int sLen = s.length(), len = 0, i = 0;
	for (len = 1; len < sLen; len++)
	{
		if (sLen%len != 0) continue;
		string curr = s.substr(0, len);
		// i is the starting point
		for (i = 0; i + len <= sLen; i += len)
		{
			if (s.substr(i, len) != curr) break;
		}
		if (i == sLen) return true;
	}
	return false;
}