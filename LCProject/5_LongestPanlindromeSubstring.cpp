/******************************************************************************/
/*
* Question: #5 Longest Palindrome Substring
* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"

* Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"
*/
/*****************************************************************************/

#include <string>

using namespace std;

// using dp, suppose dp[i][j] is a bool, indecating the palindrome starts with i and ends with j
string longestPalindrome(string s)
{
	if (s.empty() || s.length() == 1) return s;
	int len = s.length(), maxLen = 1, markStart = 0;

	for (int k = 0; k < len;)
	{
		if (len - k < maxLen / 2) break;
		int i = k, j = k;
		// skip duplicates (duplicates are counted in palindrome length)
		while (j < len - 1 && s[j + 1] == s[j]) j++;
		k = j + 1;
		while (i > 0 && j < len - 1 && s[i - 1] == s[j + 1]) { i--; j++; }
		if (j - i + 1 > maxLen)
		{
			maxLen = j - i + 1;
			markStart = i;
		}
	}

	return s.substr(markStart, maxLen);
}