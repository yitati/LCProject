/******************************************************************************/
/*
* Question: #290 Word Pattern
* Given a pattern and a string str, find if str follows the same pattern.
* Here follow means a full match, such that there is a bijection between a letter in pattern and a
* non-empty word in str.

Examples:
1.pattern = "abba", str = "dog cat cat dog" should return true.
2.pattern = "abba", str = "dog cat cat fish" should return false.
3.pattern = "aaaa", str = "dog cat cat dog" should return false.
4.pattern = "abba", str = "dog dog dog dog" should return false.

* Notes:
* You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// refer to 205 isomorphic string

// helper function that will put each string in str into the vector
void cutAndFillStr(vector<string>& dict, string & str)
{
	int i = 0, j = 0;
	while(j < str.length())
	{
		while(j < str.length() && str[j] != ' ') j++;
		dict.push_back(str.substr(i, j-i));
		i = j+1;
		j = i;
	}
}

// project each char in pattern to its index
// project each string in str to its index
bool wordPattern_practice(string pattern, string str)
{
	vector<string> dict;
	// first we get all strings from str
	cutAndFillStr(dict, str);
	if(dict.size() != pattern.length()) return false;
	unordered_map<char, int> pmap;
	unordered_map<string, int > smap;
	for(int i=0; i<pattern.length(); i++)
	{
		if(pmap.count(pattern[i]) ^ smap.count(dict[i])) return false;
		if(pmap.count(pattern[i]))
		{
			if(pmap[pattern[i]] != smap[dict[i]]) return false;
		}
		pmap[pattern[i]] = i;
		smap[dict[i]] = i;
	}
	return true;
}

/*
int main(int argc, char ** argv)
{
	string pattern = "abba";
	string str = "cat dog dog cat";

	cout << "do they match ? "<< wordPattern_practice(pattern, str) << endl;
}
*/
