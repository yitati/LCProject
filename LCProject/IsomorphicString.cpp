/******************************************************************************/
/*
* Question: #205 Isomorphic String
* company tag: LinkedIn
* Given two strings s and t, determine if they are isomorphic.
* Two strings are isomorphic if the characters in s can be replaced to get t.
* All occurrences of a character must be replaced with another character while 
* preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.

* Note:
* You may assume both s and t have the same length.
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
	if (s.length() != t.length()) return false;
	int len = s.length();
	unordered_map<char, int> table1;
	unordered_map<char, int> table2;
	for (int i = 0; i < len; i++)
	{
		if (table1.find(s[i]) != table1.end())
		{
			if (table2.find(t[i]) == table2.end()) return false;
			if (table1[s[i]] != table2[t[i]]) return false;
		}
		else if (table2.find(t[i]) != table2.end()) return false;

		table1[s[i]] = i;
		table2[t[i]] = i;
	}
	return true;
}

