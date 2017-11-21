/*
 * Window_AllAnagrams.cpp
 *
 * Find all occurrence of anagrams of a given string s in a given string l.
 * Return the list of starting indices.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * this could be the follow-up for str str
 */

/*
 * the brutal force solution would be getting all substring with length = pattern length,
 * and compare if it is the anagram of given pattern.
 */

// this problem is trying to calculate a fixed length window
vector<int> allAnagrams(string str, string pattern)
{
	vector<int> result;
	int plen = pattern.length(), slen = str.length();
	if(plen > slen) return result;

	// make difference table
	unordered_map<char, int> table;
	for(char c : pattern) table[c]++;
	int diff = table.size(); // diff means how many identical letter in the table

	// start looking to find anagrams in each window
	int lhs = 0, rhs = 0;
	while(rhs < plen)
	{
		// push the new element
		if(table.count(str[rhs]))
		{
			table[str[rhs]]--;
			if(table[str[rhs]] == 0) diff--;
			else if(table[str[rhs]] == -1) diff++;
		}
		rhs++;

		// remove the old element by checking fixed length
		while(rhs - lhs > plen)
		{
			if(table.count(str[lhs]))
			{
				table[str[lhs]]++;
				if(table[str[lhs]] == 1) diff++;
				else if(table[str[lhs]] == 0) diff--;
			}
			lhs++;
		}

		if(diff == 0)
		{
			result.push_back(lhs);
		}
	}

	return result;
}


