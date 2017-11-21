/******************************************************************************
* Question: #340 Longest Substring with At Most K Distinct Characters
* company tag: Facebook
* Given a string, find the length of the longest substring T that contains at most k distinct characters. 
For example, Given s = “eceba” and k = 2, 
T is "ece" which its length is 3. 
*****************************************************************************/

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// sliding window problem
int lengthOfLongestSubstringKDistinct(string s, int k)
{
	if (s.length() < k) return s.length();
	// we need to use a map to store the char and the frequence
	unordered_map<int, int> table;
	int lhs = 0, rhs = 0, maxLen = 0;
	while (rhs < s.length())
	{
		// push the element to the table
		table[s[rhs]]++;
		rhs++;
		if (table.size() <= k)
		{
			maxLen = max(maxLen, rhs - lhs);
		}
		if (table.size() > k) // maintain the table to be capacity with k
		{
			while (table.size() > k)
			{
				table[s[lhs]]--;
				if (table[s[lhs]] == 0) table.erase(s[lhs]);
				lhs++;
			}
		}
	}
	return maxLen;
}
