/******************************************************************************/
/*
* Question: #140 Word Break II
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
* add spaces in s to construct a sentence where each word is a valid dictionary word. 
* You may assume the dictionary does not contain duplicate words. 

* Return all such possible sentences. 

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"]. 

A solution is ["cats and dog", "cat sand dog"]. 

*/
/*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// DFS got TLE so we need to use momorized dfs

vector<string> combine(string word, vector<string> prev)
{
	// concatenate word to each of prev strings
	for (int i = 0; i < prev.size(); i++)
	{
		prev[i] += " " + word;
	}
	return prev;
}

vector<string> wordBreak_memDfs(string s, unordered_set<string> & dict, unordered_map<string, vector<string>> & mem)
{
	if (mem.count(s)) return mem[s];

	vector<string> result;
	if (dict.count(s)) result.push_back(s);

	for (int i = 1; i < s.length(); i++)
	{
		// substring [i ... n-1]
		string word = s.substr(i);
		if (dict.count(word))
		{
			// check history
			string rem = s.substr(0, i);
			vector<string> prev = combine(word, wordBreak_memDfs(rem, dict, mem));
			// add prev to result
			result.insert(result.end(), prev.begin(), prev.end());
		}
	}

	mem[s] = result;
	return result;
}

vector<string> wordBreak(string s, vector<string>& wordDict) 
{
	unordered_set<string> dict;
	for (string word : wordDict) dict.insert(word);
	unordered_map<string, vector<string>> mem;
	vector<string> result = wordBreak_memDfs(s, dict, mem);

	return result;
}
