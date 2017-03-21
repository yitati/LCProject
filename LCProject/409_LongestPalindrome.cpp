/******************************************************************************/
/*
* Question: #409 Longest Palindrome
* Given a string which consists of lowercase or uppercase letters, find the length 
* of the longest palindromes that can be built with those letters.
* This is case sensitive, for example "Aa" is not considered a palindrome here.
* Note:
* Assume the length of given string will not exceed 1,010. 

Example:  
Input:
"abccccdd"

Output:
7

* Explanation:
* One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
/*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) 
{
	unordered_map<char, int> table;
	int pLen = 0, len = s.length();
	for (int i = 0; i < len; i++)
	{
		table[s[i]]++;
	}
	for (auto it: table)
	{
		if (it.second % 2 == 0) pLen += it.second;
		else if (it.second > 2) pLen += it.second - 1;
	}
	pLen += 1;
	if (pLen > len) pLen = len;
	return pLen;
	
}