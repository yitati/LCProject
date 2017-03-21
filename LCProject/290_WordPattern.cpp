/******************************************************************************/
/*
* Question: #290 Hash Table
* Given a pattern and a string str, find if str follows the same pattern.
* Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
1.pattern = "abba", str = "dog cat cat dog" should return true.
2.pattern = "abba", str = "dog cat cat fish" should return false.
3.pattern = "aaaa", str = "dog cat cat dog" should return false.
4.pattern = "abba", str = "dog dog dog dog" should return false.

* Notes:
* You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

// refer to 205 isomorphic string
bool wordPattern(string pattern, string str) 
{
	unordered_map<char, int> table1;
	unordered_map<string, int> table2;
	vector<string> dict;

	int pLen = pattern.length(), sLen = str.length();
	int i = 0, j = 0, k = 0;
	for (j = 0; j < sLen; j++)
	{
		k = j;
		while (k < sLen && str[k] != ' ') k++;
		dict.push_back(str.substr(j, k - j));
		j = k;
	}

	if (dict.size() != pLen) return false;
	j = 0;

	for (; i < pLen; i++)
	{
		char key1 = pattern[i];
		string key2 = dict[i];
		if (table1.count(key1) ^ table2.count(key2)) return false;
		if (table1.count(key1))
		{
			if (table1[key1] != table2[key2]) return false;
		}
		table1[key1] = i;
		table2[key2] = i;
	}

	return true;
}