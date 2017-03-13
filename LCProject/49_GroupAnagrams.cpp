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

bool isIsomorphic(string s, string t)
{
	if (s.length() != t.length()) return false;
	int len = s.length();
	vector<int> table1(256, -1);
	vector<int> table2(256, -1);
	for (int i = 0; i < len; i++)
	{
		if (table1[s[i]] != table2[t[i]]) return false;
		table1[s[i]] = i;
		table2[t[i]] = i;
	}
	return true;
}