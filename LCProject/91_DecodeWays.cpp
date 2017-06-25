/******************************************************************************/
/*
* Question: #91 Decode Ways
* A message containing letters from A-Z is being encoded to numbers using the following mapping: 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26

* Given an encoded message containing digits, determine the total number of ways to decode it. 

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 

* The number of ways decoding "12" is 2. 
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;
// this is a dp problem
// dp[i] = dp[i-1] (if s[i] != '0') + dp[i-2] (if s[i-1, i] is valid) 
int numDecodings(string s)
{
	if (s.empty()) return 0;
	int n = s.length();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for (int i = 0; i<n; i++)
	{
		if (s[i] != '0') dp[i + 1] += dp[i];
		if (i >= 1 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) dp[i + 1] += dp[i - 1];
	}
	return dp[n];
}