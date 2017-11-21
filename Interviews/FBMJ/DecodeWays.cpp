/******************************************************************************
* Question: #91 Decode Ways
* company tag: Facebook
* A message containing letters from A-Z is being encoded to numbers using the following mapping: 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26

* Given an encoded message containing digits, determine the total number of ways to decode it. 

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12). 

* The number of ways decoding "12" is 2. 
*****************************************************************************/

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

// can we improve the time complexity or space complexity
// we can improve the space complexity to make O(1)
int decodeWays_improvedSpace(string s)
{
	int n = s.length();
	if(n == 0 || s[0] == '0') return 0;
	if(n == 1) return 1;
	int fn = 1, fn_1 = 1;
	for(int i=1; i<n; i++)
	{
		int newfn = 0;
		if(s[i] != '0') newfn += fn;
		if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) newfn += fn_1;
		fn_1 = fn;
		fn = newfn;
	}
	return fn;
}
