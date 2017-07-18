/******************************************************************************
* Question: #76 Minimum Window Substring
* company tag: Facebook, LinkedIn
* Given a string S and a string T, find the minimum window in S which will contain all the characters in
* T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

* Note:
* If there is no such window in S that covers all characters in T, return the empty string "".
* If there are multiple such windows, you are guaranteed that there will always be only one unique minimum
* window in S.
*
* Similar problem:
* LC340 Longest Substring with at most K distinct characters
* All Anagram
*****************************************************************************/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// solution 1 - use unordered_map to map char and frequency
// this is a sliding window problem
string minWindow(string s, string t)
{
	int minLen = INT_MAX, start = -1, diff = 0;
	unordered_map<char, int> window;
	for (char c : t) window[c]++;  // make the differencial table
	diff = t.length();
	int lhs = 0, rhs = 0;
	while (rhs < s.length())
	{
		if (window.count(s[rhs])) // find a match 
		{
			window[s[rhs]]--;
			if (window[s[rhs]] >= 0) diff--;  // we we find enough char to cover the string, no need to decrease the counter
		}
		rhs++;
		while (diff == 0)
		{
			if (rhs - lhs < minLen)   // get the length
			{
				start = lhs;
				minLen = rhs - lhs;
			}

			if (window.count(s[lhs]))
			{
				window[s[lhs]]++;
				if (window[s[lhs]] == 1) diff++; // add diff if the char to be poped matters in the substring
			}
			lhs++;
		}
	}
	if (start == -1) return "";
	return s.substr(start, minLen);
}

// solution 2 - use vector instead of unordered_map
// for ASCII code, first 128 code from [0, 127] are printable code
// and the next 128 code from [128-255] are extended code
// here we can consider only the printable ones
string minWindow2(string s, string t)
{
	int minLen = INT_MAX, start = -1, diff = 0, lhs = 0, rhs = 0;
	vector<int> window(128, 0);
	for(char c : t) window[c]++;   // instead of using c-'a' we can just use c here since it will cover all letters
	diff = t.length();
	while(rhs < s.length())
	{
		window[s[rhs]]--;
		if(window[s[rhs]] >= 0) diff--;
		rhs++;
		while(diff == 0)
		{
			if(rhs - lhs < minLen)
			{
				minLen = rhs - lhs;
				start = lhs;
			}
			window[s[lhs]]++;
			if(window[s[lhs]] == 1) diff++;
			lhs++;
		}
	}

	if(start == -1) return  "";
	return s.substr(start, minLen);
}
