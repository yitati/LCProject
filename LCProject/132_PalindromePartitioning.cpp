/******************************************************************************/
/*
* Question: #132 Palindrome Partitioning II
* Given a string s, partition s such that every substring of the partition is a palindrome. 
* Return the minimum cuts needed for a palindrome partitioning of s. 

For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minCut(string s)
{
	int len = s.length();
	vector<vector<bool>> table(len, vector<bool>(len, false));
	for (int l = 1; l <= len; l++)
	{
		for (int lhs = 0; lhs + l - 1<len; lhs++)
		{
			int rhs = lhs + l - 1;
			if (rhs == lhs) table[lhs][rhs] = true;
			else if (rhs == lhs + 1) table[lhs][rhs] = (s[lhs] == s[rhs]);
			else table[lhs][rhs] = (s[lhs] == s[rhs] && table[lhs + 1][rhs - 1]);
		}
	}

	vector<int> dp(len, INT_MAX);
	for (int i = 0; i<len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (table[j][i])
			{
				dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	return dp[len - 1];
}