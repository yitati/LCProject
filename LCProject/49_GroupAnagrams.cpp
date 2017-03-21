/******************************************************************************/
/*
* Question: #49 Group Anagrams
* Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
* Note: All inputs will be in lower-case.
*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> results;
	unordered_map<string, int> table;
	for (int i = 0; i < strs.size(); i++)
	{
		string curr = strs[i];
		sort(curr.begin(), curr.end());
		if (table.count(curr)) results[table[curr]].push_back(strs[i]);
		else
		{
			table[curr] = results.size();
			vector<string> item;
			item.push_back(strs[i]);
			results.push_back(item);
		}
	}
	return results;
}