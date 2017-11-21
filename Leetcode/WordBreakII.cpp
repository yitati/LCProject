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

// Solution 1: DFS got TLE so we need to use momorized dfs
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

vector<string> wordBreakII(string s, vector<string>& wordDict)
{
	unordered_set<string> dict;
	for (string word : wordDict) dict.insert(word);
	unordered_map<string, vector<string>> mem;
	vector<string> result = wordBreak_memDfs(s, dict, mem);

	return result;
}

// Solution 2 :  Use DP first to memorize the positions for the break point, then combine the strings
void fillWordBreaks(string& s, vector<string>& results, vector<vector<int>>& dp, string curr, int rhs);
vector<string> wordBreakII_DP(string s, vector<string>& wordDict)
{
	// push all words to unordered_set 
	unordered_set<string> dict;
	for (string word : wordDict) dict.insert(word);
	// first memorize all lhs positions that are able to do the word breaks to point i - make a matrix
	int sLen = s.length();
	vector<vector<int>> dp(sLen);
	for (int i = 0; i<sLen; i++)
	{
		if (dict.count(s.substr(0, i + 1))) dp[i].push_back(-1); // use -1 to denote lhs from 0
		for (int j = 0; j <= i; j++)
		{   // if s[0...j] is a valid word and s[j+1...i] is a valid word 
			if (!dp[j].empty() && dict.count(s.substr(j + 1, i - j))) dp[i].push_back(j);
		}
	}
	// we can fill the results using DFS then
	vector<string> results;
	fillWordBreaks(s, results, dp, "", s.size() - 1);
	return results;
}
// dfs searching for every possible string
void fillWordBreaks(string& s, vector<string>& results, vector<vector<int>>& dp, string curr, int rhs)
{
	if (rhs == -1)
	{
		curr.pop_back();
		results.push_back(curr);
		return;
	}

	for (int lhs : dp[rhs])
	{
		string sub = s.substr(lhs + 1, rhs - lhs);
		fillWordBreaks(s, results, dp, sub + " " + curr, lhs);
	}
}

