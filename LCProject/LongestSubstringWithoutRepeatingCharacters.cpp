/******************************************************************************
* Question: #3 Longest Substring Without Repeating Characters
* company tag: eBay
* Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*****************************************************************************/

#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// keep an unordered_set
int lengthOfLongestSubstring(string s)
{
	unordered_set<char> visited;
	int start = 0, end = 0;
	int len = 0;
	while (start <= end && end < s.length())
	{
		if (visited.count(s[end]))
		{
			while (s[start] != s[end]) visited.erase(s[start++]);
			visited.erase(s[start++]);
		}

		visited.insert(s[end++]);
		len = max(len, end - start);
	}

	return len;
}

int longestSubstrWithoutRepeat(string s)
{
	vector<bool> visit(256, false);
	int start = 0, end = 0, len = 0;
	while(start <= end && end < s.length())
	{
		if(visit[s[end]])
		{
			while(s[start] != s[end]) visit[s[start++]] = false;
			visit[s[start++]] = false;
		}
		visit[s[end++]] = true;
		len = max(len, end-start);
	}
	return len;
}

