/******************************************************************************/
/*
* Question: #521 Longest Uncommon Subsequence II
* Given a list of strings, you need to find the longest uncommon subsequence among them. 
* The longest uncommon subsequence is defined as the longest subsequence of one of these strings 
* and this subsequence should not be any subsequence of the other strings.
* A subsequence is a sequence that can be derived from one sequence by deleting some characters 
* without changing the order of the remaining elements. Trivially, any string is a subsequence of itself 
* and an empty string is a subsequence of any string.
* The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. 
* If the longest uncommon subsequence doesn't exist, return -1.

Example 1:

Input: "aba", "cdc", "eae"
Output: 3

* Note:
* 1.All the given strings' lengths will not exceed 10.
* 2.The length of the given list will be in the range of [2, 50].
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

bool isSubSequence(string sub, string str)
{
	if (sub.length() > str.length()) return false;
	else if (sub == str) return true;
	int i = 0, j = 0;
	while (i < sub.length() && j < str.length())
	{
		if (sub[i] != str[j])
		{
			j++;
			continue;
		}
		else
		{
			i++;
			j++;
		}
	}
	if (i < sub.length()) return false;
	return true;
}

int findLUSlength(vector<string>& strs)
{
	int maxSub = -1;
	for (int i = 0; i < strs.size(); i++)
	{
		string sub = strs[i];
		bool isSub = true;
		for (int j = 0; j < strs.size(); j++)
		{
			if (j == i) continue;
			if (isSubSequence(strs[i], strs[j]))
			{
				isSub = false;
				break;
			}
		}
		if (isSub == false) continue;
		else maxSub = max(maxSub, (int)strs[i].length());
	}
	return maxSub;
}