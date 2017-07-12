/******************************************************************************
* Question: #76 Minimum Window Substring
* company tag: LinkedIn
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
*****************************************************************************/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

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
