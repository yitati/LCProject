/******************************************************************************/
/*
* Question: #76 Minimum Window Substring
* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

* Note:
* If there is no such window in S that covers all characters in T, return the empty string "".
* If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string minWindow(string s, string t) 
{
	unordered_map<char, int> target;
	unordered_map<char, int> window;

	// put target string into target map
	for (char x : t) target[x]++;
	int count = target.size();
	int lhs = 0, rhs = 0, minLen = INT_MAX;
	string result;

	while (rhs < s.length())
	{
		if (target.count(s[rhs]))
		{
			window[s[rhs]]++;
			if (window[s[rhs]] == target[s[rhs]]) count--;
			while (lhs <= rhs && count == 0)
			{
				if (rhs - lhs + 1 < minLen)
				{
					minLen = rhs - lhs + 1;
					result = s.substr(lhs, minLen);
				}

				if (target.count(s[lhs])) 
				{
					window[s[lhs]]--;
					if (window[s[lhs]] < target[s[lhs]]) count++;
				}
				lhs++;
			}
		}
		rhs++;
	}

	return result;
}