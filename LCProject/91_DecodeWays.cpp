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

using namespace std;

void numDecodings_dfs(string & s, int & count, int level)
{
	if (level == s.length())
	{
		count++;
		return;
	}
	if (s[level] == '0') return;

	if (level < s.size() - 1)
	{
		if ((s[level] == '1' || (s[level] == '2' && s[level + 1] < '7')))
			numDecodings_dfs(s, count, level + 2);
	}
	if (s[level] != '0')numDecodings_dfs(s, count, level + 1);
}

int numDecodings(string s)
{
	if (s.empty()) return 0;
	int count = 0;
	numDecodings_dfs(s, count, 0);
	return count;
}