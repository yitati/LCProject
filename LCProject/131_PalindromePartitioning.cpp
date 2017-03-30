/******************************************************************************/
/*
* Question: #131 Palindrome Partitioning
* Given a string s, partition s such that every substring of the partition is a palindrome. 
* Return all possible palindrome partitioning of s. 
For example, given s = "aab",
Return 
[
  ["aa","b"],
  ["a","a","b"]
]
*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

inline bool isPalindromeStr(string & s, int start, int end)
{
	int i = start, j = end;
	while (i < j)
	{
		if (s[i++] != s[j--]) return false;
	}
	return true;
}

void palindromePartition_dfs(vector<vector<string>> & results, vector<string> & result, string & s, int index)
{
	if (index == s.length())
	{
		results.push_back(result);
		return;
	}

	for (int i = 0; index + i<s.length(); i++)
	{
		if (isPalindromeStr(s, index, index + i))
		{
			result.push_back(s.substr(index, i + 1));
			palindromePartition_dfs(results, result, s, index + i + 1);
			result.pop_back();
		}
	}
}


vector<vector<string>> partition(string s)
{
	vector<vector<string>> results;
	vector<string> result;
	palindromePartition_dfs(results, result, s, 0);
	return results;
}