/******************************************************************************/
/*
* Question: #14 Longest Common Prefix
* Write a function to find the longest common prefix string amongst an array of strings.
*/
/*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

string findCommPrefix(string str1, string str2)
{
	int start = 0, idx = 0;
	while (str1[idx] == str2[idx]) idx++;
	return str1.substr(0, idx);
}

string longestCommonPrefix(vector<string>& strs) 
{
	if (strs.size() == 0) return "";
	if (strs.size() == 1) return strs[0];
	string prefix = strs[0];
	for (int i = 1; i < strs.size(); i++)
	{
		prefix = findCommPrefix(prefix, strs[i]);
	}
	return prefix;
}