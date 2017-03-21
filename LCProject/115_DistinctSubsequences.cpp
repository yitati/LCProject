/******************************************************************************/
/*
* Question: #115 Distinct Subsequences
* Given a string S and a string T, count the number of distinct subsequences of T in S. 
* A subsequence of a string is a new string which is formed from the original string by 
* deleting some (can be none) of the characters without disturbing the relative positions 
* of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Here is an example:
S = "rabbbit", T = "rabbit" 
Return 3. 
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

int numDistinct(string s, string t) 
{
	int sLen = s.length(), tLen = t.length();
	int i = 0, j = 0;
	vector<vector<int>>dp(tLen + 1, vector<int>(sLen + 1, 0));
	dp[0][0] = 1;
	for (i = 0; i < tLen; i++) dp[i + 1][0] = 0;
	for (j = 0; j < sLen; j++) dp[0][j + 1] = 1;
	for (i = 0; i < tLen; i++)
	{
		for (j = 0; j < sLen; j++)
		{
			dp[i + 1][j + 1] = dp[i + 1][j];
			if (t[i] == s[j]) dp[i + 1][j + 1] += dp[i][j];
		}
	}
	return dp[tLen][sLen];
}