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
#include <algorithm>

using namespace std;

// one easy solution by using two pointers to compare original string and reversed string
// we want to find the longest substring which will be the prefix of original string and
// surfix of reversed string
// So this is actually a string matching problem
string shortestPalindrome(string s)
{
	string ori = s, rev = s;
	reverse(rev.begin(), rev.end());
	int i = 0, j = 0, maxLen = 0, cut = 0;
	while (i < s.length())
	{
		while (i + j < s.length() && rev[i + j] == ori[j]) j++;
		if (i + j == s.length()) break;
		j = 0;
		i++;
	}
	// get prefix
	string prefix = rev.substr(0, i);
	return prefix + s;
}

// use KMP
string shortestPalindrome_KMP(string s)
{
	// TODO - add code here
	return s;
}
