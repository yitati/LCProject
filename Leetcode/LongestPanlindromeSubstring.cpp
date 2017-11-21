/******************************************************************************
* Question: #5 Longest Palindrome Substring
* company tag : Amazon
* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"

* Note: "aba" is also a valid answer.
Example:
Input: "cbbd"
Output: "bb"
*****************************************************************************/

#include <string>
#include <vector>

using namespace std;
/*
 * there could be only one longest palindrome string, so we can do O(n) solution
 */
string longestPalindromeSubstr(string s)
{
	if(s.empty() || s.length() == 1) return s;
	int slen = s.length();
	vector<vector<bool>> dp(slen, vector<bool>(slen, false));
	int maxLen = 0, start = -1;

	int center = 0;
	while(center < slen)
	{
		if(slen - center < maxLen/2) break;
		int lhs = center, rhs = center;
		while(rhs+1 < slen && s[rhs+1] == s[rhs]) rhs++;
		center = rhs + 1;
		while(lhs > 0 && rhs + 1 < slen && s[lhs-1] == s[rhs+1]) { lhs--; rhs++;}
		int len = rhs - lhs + 1;
		if(len > maxLen)
		{
			maxLen = len;
			start = lhs;
		}
	}
	return s.substr(start, maxLen);
}
