/******************************************************************************/
/*
* Question: #97 Interleaving String
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2. 
For example,
Given:
s1 = "aabcc",
s2 = "dbbca", 
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

// refer to 62 Unique Path
bool isInterleave(string s1, string s2, string s3) 
{
	int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
	if (len3 != len1 + len2) return false;
	int i = 0, j = 0;
	vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

	dp[0][0] = true;
	for (int i = 0; i < len1; i++) dp[i + 1][0] = (dp[i][0] && s3[i] == s1[i]);
	for (int j = 0; j < len2; j++) dp[0][j + 1] = (dp[0][j] && s3[j] == s2[j]);

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			dp[i + 1][j + 1] = (dp[i][j + 1] && s3[i + j + 1] == s1[i]) || (dp[i + 1][j] && s3[i + j + 1] == s2[j]);
		}
	}

	return dp[len1][len2];
}