
#include <string>
#include <vector>

using namespace std;

/*
 * Decode Ways I
 *  A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 */

int decodeWaysI(string s)
{
	int slen = s.length();
	if(s.empty() || s[0] == '0') return 0;
	vector<int> dp(slen+1, 0);
	dp[0] = 1;

	for(int i = 0; i < slen; i++)
	{
		if(s[i] != '0') dp[i+1] += dp[i];
		if(i > 0 && (s[i-1] == '1' || s[i-1] == '2'&& s[i] <= '6')) dp[i+1] += dp[i-1];
	}
	return dp[slen];
}

/*
 * improve the space
 */
int decodeWaysI_improve(string s)
{
	if(s.empty() || s[0] == '0') return 0;
	int fn = 1, fn_1 = 1;
	for(int i=1; i < s.length(); i++)
	{
		int newfn = 0;
		if(s[i] != '0') newfn += fn;
		if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) newfn += fn_1;
		fn_1 = fn;
		fn = newfn;
	}
	return fn;
}


/*
 * Decode Ways II
 * Except for the numbers we also have '*' which represents 1 - 9
 */

/*
 * 1. if we use f(i-1) to represent the decode ways of s[0, i-1], and use f(i-2) to represent the decode
 * ways of s[0, i-2], then we have f(i) = f(i-1) * dw(i) + f(i-2) * dw(i-1, i)
 * 2. we need to make a "switcher" to calculate dw(i) and ds(i-1, i)
 */
// this is the function that will calculate the decode ways of substring i and substring (i-1, i)
int decodeStr(string s)
{
	if(s.length() == 1)
	{
		if(s[0] == '*') return 9;
		else if(s[0] == '0') return 0;
		else return 1;
	}
	else if(s == "**") return 15;
	else if(s[0] == '*')
	{
		if(s[1] <= '6') return 2;
		else return 1;
	}
	else if(s[1] == '*')
	{
		if(s[0] == '1') return 9;
		else if(s[0] == '2') return 6;
		else return 0;
	}
	else
	{
		if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) return 1;
		return 0;
	}
}

int decodeWaysII(string s)
{
	int slen = s.length();
	long fn = decodeStr(s.substr(0, 1)), fn_1=1;

	for(int i=1; i<slen; i++)
	{
		long newfn = fn * decodeStr(s.substr(i, 1)) + fn_1 * decodeStr(s.substr(i-1, 2));
		fn_1 = fn;
		fn = newfn;
	}

	return fn;
}

/*
 * consider the number could be very large so we need to use long for fn, fn_1 and newfn.
 * also we probably need to do fn = newfn%MAXRANGE
 */




