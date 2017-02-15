/******************************************************************************/
/*
* Question: #214 Shortest Palindrome
* Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
* Find and return the shortest palindrome you can find by performing this transformation.
For example:
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/
/*****************************************************************************/

#include <string>

using namespace std;

// This is when using two pointers
string shortestPalindrome_twoPointers(string s)
{
	string pattern = s;
	reverse(s.begin(), s.end());
	string target = s;
	reverse(s.begin(), s.end());
	int len = s.length(), maxLen = 0, i = 0, j = 0;
	while (i < len)
	{
		while (i<len && pattern[0] != target[i]) i++;
		while (i + j < len && target[i + j] == pattern[j]) j++;
		if (i + j == len) break;
		i++;
		j = 0;
	}

	maxLen = j - i;
	if (maxLen == len) return s;
	string add = s.substr(j, len - maxLen);
	reverse(add.begin(), add.end());
	return add + s;
}

// use KMP
string shortestPalindrome_KMP(string s)
{
	// TODO - add code here
	return s;
}
