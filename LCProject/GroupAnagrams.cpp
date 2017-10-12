/******************************************************************************
* Question: #49 Group Anagrams
* company tag: Facebook
* Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
* Note: All inputs will be in lower-case.
*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// TODO - BAOBAO time complexity

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> results;
	unordered_map<string, vector<int>> table;  // we can remember only the index for the string in strs
	for(int i=0; i<strs.size(); i++)
	{
		string curr = strs[i];
		sort(curr.begin(), curr.end());
		table[curr].push_back(i);
	}
	for(auto it = table.begin(); it != table.end(); it++)
	{
		vector<string> result;
		for(int i=0; i<it->second.size(); i++)
		{
			result.push_back(strs[it->second[i]]);
		}
		results.push_back(result);
	}
	return results;
}
