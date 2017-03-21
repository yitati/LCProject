/******************************************************************************/
/*
* Question: #336 PalindromePairs
* Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
* so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome. 

Example 1:
 Given words = ["bat", "tab", "cat"]
 Return [[0, 1], [1, 0]]
 The palindromes are ["battab", "tabbat"]

Example 2:
 Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// TODO use trie to solve this issue

// Use hash map to store the string with index, also reverse string and index
void collectResults(vector<vector<int>> & results, int i, int j)
{
	vector<int> result(2);
	result[0] = i;
	result[1] = j;
	results.push_back(result);
}

bool isPanlindromeString(string input, int lhs, int rhs)
{
	int i = lhs, j = rhs;
	while (i < j)
	{
		if (input[i++] != input[j--]) return false;
	}
	return true;
}
// use hash table to store the original string with index, and the reverse string and index
vector<vector<int>> palindromePairs1(vector<string>& words)
{
	unordered_map<string, int> forward;
	unordered_map<string, int> backword;
	vector<vector<int>> results;

	for (size_t i = 0; i < words.size(); i++)
	{
		string curr = words[i];
		forward[curr] = i;
		reverse(curr.begin(), curr.end());
		backword[curr] = i;
	}

	for (size_t i = 0; i < words.size(); i++)
	{
		string curr = words[i];
		string prefix, surfix;
		// search for prefix
		for (size_t j = 0; j < curr.length(); j++)
		{
			if (backword.count(prefix) && backword[prefix] != i)
			{
				if (isPanlindromeString(curr, j, curr.length() - 1))
				{
					collectResults(results, i, backword[prefix]);
				}
			}
			prefix.push_back(curr[j]);
		}
		// search for surfix
		for (size_t j = curr.length() - 1; j >= 0; j--)
		{
			if (forward.count(surfix))
			{
				if (isPanlindromeString(curr, 0, j))
				{
					collectResults(results, forward[surfix], i);
				}
			}
			surfix.push_back(curr[j]);
		}
		// search for string
		if (backword.count(curr) && backword[curr] != i)
		{
			collectResults(results, i, backword[curr]);
		}
	}

	return results;
}

// Brutal force solution: this solution exceed time limit
vector<vector<int>> palindromePairs2(vector<string>& words)
{
	vector<vector<int>> results;
	for (size_t i = 0; i<words.size(); i++)
	{
		for (size_t j = 0; j<words.size(); j++)
		{
			if (j == i) continue;
			string content = words[i] + words[j];
			if (isPanlindromeString(content, 0, content.size()-1)) {
				vector<int> result(2);
				result[0] = i;
				result[1] = j;
				results.push_back(result);
			}
		}
	}
	return results;
}