/***********************************************************************************
 * Question #639 Decode Ways II
 * company tag: Facebook
 * A message containing letters from A-Z is being encoded to numbers using the following mapping way:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Beyond that, now the encoded string can also contain the character '*', which can be treated as
 * one of the numbers from 1 to 9.
 * Given the encoded message containing digits and the character '*', return the total number of
 * ways to decode it.
 * Also, since the answer may be very large, you should return the output mod 109 + 7.
 * Note:
 * The length of the input string will fit in range [1, 105].
 * The input string will only contain the character '*' and digits '0' - '9'.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F",
"G", "H", "I".
Example 2:
Input: "1*"
Output: 9 + 9 = 18
 ***********************************************************************************/

#include <string>
#include <vector>

using namespace std;

#define MAXRANGE    1000000007

/*
 *  1. For any string s logner than 2, we can decode either the last 2 char as a whole or the
 *  last 1 char. So
 *                  dp[i] = dp[i-1]*f(s.substr(i, 1)) + dp[i-2]*f(s.substr(i-1, 2))
 *  f(x) is the number of ways to decode a string of length 1 or 2. f(x) could be 0, for example,
 *  f("67")
 *
 *  2. There is a lot of cases and corner cases for f(string s). For example, * cannot be '0', so ** has
 *  15 instead of 26 possibilities. But the time complexity is still O(n).
 */

// this is the helper function that will decode a short string with max 2 chars
int decodeStr(string s)
{
	if(s.length() == 1)  // string has one char
	{
		if(s[0] == '*') return 9;
		else if(s[0] == '0') return 0;
		return 1;
	}
	else if(s == "**")
	{
		return 15;
	}
	else if(s[1] == '*')
	{
		if(s[0] == '1') return 9;
		else if(s[0] == '2') return 6;
		else return 0;
	}
	else if(s[0] == '*')
	{
		if(s[1] <= '6') return 2;
		else return 1;
	}
	else
	{
		if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) return 1;
		return 0;
	}
}

int numDecodingsII(string s)
{
	int len = s.length();
	if(len == 0) return 0;
	vector<int> dp(len+1, 0);
	dp[0] = 1;
	dp[1] = decodeStr(s.substr(0, 1));
	for(int i=1; i<len; i++)
	{
		dp[i+1] = dp[i] * decodeStr(s.substr(i, 1))%MAXRANGE + dp[i-1] * decodeStr(s.substr(i-1, 2))%MAXRANGE;
	}
	return dp[len];
}

int numDecodingsII_improvedSpace(string s)
{
	int len = s.length();
	// f2 is the answer for substring ending at i, initially i = 0
	long f1 = 1, f2 = decodeStr(s.substr(0, 1));
	// DP to get f2 for substring ending at position len-1
	for(int i=1; i<len; i++)
	{
		long f3 = f2*decodeStr(s.substr(i, 1)) + f1*decodeStr(s.substr(i-1, 2));
		f1 = f2;
		f2 = f3%MAXRANGE;
	}
	return f2;
}
