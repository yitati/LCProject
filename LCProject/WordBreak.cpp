/******************************************************************************
* Question: #139 Word Break
* company tag: eBay
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
* determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
* You may assume the dictionary does not contain duplicate words. 

For example, given
s = "leetcode",
dict = ["leet", "code"]. 

Return true because "leetcode" can be segmented as "leet code". 

*****************************************************************************/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
	if (s.empty()) return wordDict.empty();
	// use a set to store all the words
	unordered_set<string> dict;
	for (string str : wordDict) dict.insert(str);

	int len = s.length();
	vector<bool> dp(s.length(), false);

	for (int i = 0; i < len; i++)
	{
		if (dict.count(s.substr(0, i + 1))) dp[i] = true;
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] && dict.count(s.substr(j + 1, i - j)))
				{
					dp[i] = true;
					break;
				}
			}
		}

	}

	return dp[len - 1];
}
