/******************************************************************************/
/**
* Question: #205 Isomorphic String
* Given two strings s and t, determine if they are isomorphic.
* Two strings are isomorphic if the characters in s can be replaced to get t.
* All occurrences of a character must be replaced with another character while preserving the order of characters.
* No two characters may map to the same character but one character can map to itself.
* For example,
* Given "egg", "add", return true.
* Given "foo", "bar", return false.
* Given "paper", "title", return true.
* Note:
* You may assume both s and t have the same length.
*/
/*****************************************************************************/

#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;


bool isIsomorphic_jy(string s, string t) 
{
	if (s.empty()) return t.empty();
	map<char, char> table;
	unordered_set<char> visited;
	int i, j;
	for (i = 0, j = 0; i < s.size() && j < t.size(); i++, j++)
	{
		if (table.find(s[i]) != table.end()) {
			if (table[s[i]] != t[j]) {
				return false;
			}
		}
		else if (visited.find(t[j]) != visited.end())
		{
			return false;
		}
		else
		{
			table[s[i]] = t[j];
			visited.insert(t[j]);
		}
	}
	return true;
}

// instead of mapping char to char, map char to index
bool isIsomorphic(string s, string t)
{
	int map1[256], map2[256];
	for (int i = 0; i < s.size(); i++)
	{
		if (map1[s[i]] != map2[t[i]]) return false;
		map1[s[i]] = i + 1;
		map2[t[i]] = i + 1;
	}
	return true;
}

/*
int main(int argc, char * argv)
{
	cout << isIsomorphic("egg", "add") << endl;
	cout << isIsomorphic("paper", "title") << endl;
	cout << isIsomorphic("foo", "bar") << endl;
	cout << isIsomorphic("ab", "aa") << endl;
	system("pause");
}
*/
