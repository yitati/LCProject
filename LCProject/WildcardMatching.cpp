/******************************************************************************/
/*
* Question: #44 Wildcard Matching
* Implement wildcard pattern matching with support for '?' and '*'.
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).

* The matching should cover the entire input string (not partial).

* The function prototype should be:
* bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

/*
 *  We define the state dp[i][j] to be whether s[0, i) matches p[0, j). The state
 *  equation are as follow:
 *  1. if(p[j] != '*') dp[i+1][j+1] = dp[i][j] && (s[i]== p[j] || p[j] == '?')
 *  2. if(p[j] == '*') dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j]
 *  The meaning of above two euqations:
 *  1. Equation 1 means that if p[j] is not '*', dp[i][j] is determined by if s[0, i-1]
 *  matches p[0, j-1] and if s[i] matches p[j];
 *  2. Equation 2 means that if p[j] is '*', dp[i+1][j+1] is true either s[0, i] matches
 *  p[0, j-1] and * matches to nothing; or dp[i][j+1] is true, which means s[0, i-1] matches
 *  p[0, j] and * is used to match s[i]
 *
 */
bool isMatchWildcard(string s, string p) 
{
	int sLen = s.length(), pLen = p.length();
	vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
	dp[0][0] = true;
	for (int j = 0; j < pLen; j++) dp[0][j + 1] = (p[j] == '*') && dp[0][j];

	for (int i = 0; i < sLen; i++)
	{
		for (int j = 0; j < pLen; j++)
		{
			if (p[j] != '*') dp[i + 1][j + 1] = dp[i][j] && (p[j] == '?' || s[i] == p[j]);
			else
			{
				// two situations when p[j] == '*'
				// 1. match empty() then dp[i+1][j+1] = dp[i+1][j]
				// 2. match anything then dp[i+1][j+1] = dp[i][j+1]
				dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
			}
		}
	}

	return dp[sLen][pLen];
}
