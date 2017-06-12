/******************************************************************************/
/*
* Question: #10 Regular Expression Matching
* Implement regular expression matching with support for '.' and '*'.
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).

* The function prototype should be:
* bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

bool isMatchRegularExpression(string s, string p) 
{
	int sLen = s.length(), pLen = p.length();
	vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, 0));

	dp[0][0] = 1;
	for (int i = 0; i < sLen; i++) dp[i+1][0] = false;
	for (int j = 0; j < pLen; j++) dp[0][j + 1] = j > 0 && p[j] == '*' && dp[0][j - 1];

	for (int i = 0; i < sLen; i++)
	{
		for (int j = 0; j < pLen; j++)
		{
			if (p[j] != '*')
			{
				dp[i + 1][j + 1] = dp[i][j] && (s[i] == p[j] || p[j] == '.');
			}
			else
			{
				// when p[j] == '*' there are 3 different situations, denote p[0, j-1] = x
				// 1. when x* repeats 0 times - dp[i+1][j+1] = dp[i+1][j-1]
				// 2. when x* repeats 1 times - dp[i+1][j+1] = dp[i][j+1] && p[j-1] == s[i] 
				// 3. when x* repeats >= 2 times - dp[i+1][j+1] = dp[i+1][j]
				dp[i + 1][j + 1] = (dp[i + 1][j - 1] && j > 0) || 
									dp[i + 1][j] || 
									(dp[i][j + 1] && (p[j - 1] == s[i] || p[j-1] == '.') && j > 0);
			}
		}
	}

	return dp[sLen][pLen];
}