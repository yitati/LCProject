/*
 * Laicode_LongestCommonSubstring.cpp
 * company tag: eBay

Find the longest common substring of two given strings.

Assumptions

The two given strings are not null
Examples

S = “abcde”, T = “cdf”, the longest common substring of S and T is “cd”

 */

#include <vector>
#include <string>

using namespace std;

/*
 * a common dp problem, use dp[i+1][j+1] to denote the length of common string ending
 * at s[i] and t[j], then dp[i+1][j+1] = dp[i][j] + 1 if(s[i] == t[j])
 */
string longestCommon(string s, string t)
{
	int sLen = s.length(), tLen = t.length();
	vector<vector<int>> dp(sLen+1, vector<int>(tLen+1, 0));

	int start = -1, maxLen = 0;
	for(int i=0; i<sLen; i++)
	{
		for(int j=0; j < tLen; j++)
		{
			if(s[i] == t[j])
			{
				dp[i+1][j+1] = dp[i][j] + 1;
				if(dp[i+1][j+1] > maxLen)
				{
					maxLen = dp[i+1][j+1];
					start = i + 1 - maxLen;
				}
			}
		}
	}
	if(start == -1) return "";
	return s.substr(start, maxLen);
}




