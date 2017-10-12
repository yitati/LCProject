/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in
 T in complexity O(n).
 */

#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

// TODO - BAOBAO time complexity
/*
 * Brutal force solution
 * 1. find all possible substrings in str and sort it.
 * 2. compare if substring is same with pattern
 * 3. return the shortest one
 */

string mimWindow(string str, string pattern)
{
	int slen = str.length(), plen = pattern.length();
	int start = -1, minLen = INT_MAX;

	// preprocess the pattern string
	unordered_map<char, int> table;
	for(char c : pattern) table[c]++;
	int diff = pattern.length();

	int lhs = 0, rhs = 0;
	while(rhs < plen)
	{
		// add new element
		if(table.count(str[rhs]))
		{
			table[str[rhs]]--;
			if(table[str[rhs]] >= 0) diff--;
		}
		rhs++;

		// remove old element
		while(diff == 0)
		{
			if(rhs-lhs < minLen)
			{
				minLen = rhs - lhs;
				start = lhs;
			}
			if(table.count(str[lhs]))
			{
				table[str[lhs]]++;
				if(table[str[lhs]] == 1) diff++;
			}

			lhs++;
		}
	}

	if(start == -1) return "";
	return str.substr(start, minLen);
}

/*
 * since actually it does not matter if we use map or vector
 */
string minWindow(string s, string t)
{
	int minLen = INT_MAX, start = -1, diff = 0, lhs = 0, rhs = 0;
	vector<int> window(128, 0);
	// instead of using c-'a' we can just use c here since it will cover all letters
	for(char c : t) window[c]++;
	diff = t.length();

	while(rhs < s.length())
	{
		// start matching the characters of given pattern, and if it matches, we decrese the counter
		window[s[rhs]]--;
		if(window[s[rhs]] >= 0) diff--;
        rhs++;
        // when diff == 0 means the window is found, try to minimize it
		while(diff == 0)
		{
			if(rhs - lhs < minLen)
			{
				minLen = rhs - lhs;
				start = lhs;
			}
			// remove extra characters
			window[s[lhs]]++;
			// by removing matching element from window, we increse diff
			if(window[s[lhs]] == 1) diff++;
			lhs++;
		}
	}

	if(start == -1) return  "";
	return s.substr(start, minLen);
}
