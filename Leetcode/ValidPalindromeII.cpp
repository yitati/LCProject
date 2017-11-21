/******************************************************************************
* Question: #680 Valid Palindrome II
* company tag: Facebook
* Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

* Note:
* The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
*****************************************************************************/

#include <string>

using namespace std;

/*
 * Two pointers to check if i and j equals, if not, skip the current and check the rest
 * O(n) time and O(1) space
 */
bool isPalindromic(string s, int lhs, int rhs)
{
	while(lhs >= 0 && rhs < s.length() && lhs < rhs)
	{
		if(s[lhs] != s[rhs]) return false;
		lhs++;
		rhs--;
	}
	return true;
}

bool validPalindrome(string s)
{
	int lhs = 0, rhs = s.length()-1;
	while(lhs < rhs)
	{
		if(s[lhs] == s[rhs])
		{
			lhs++;
			rhs--;
		}
		else
		{
			return isPalindromic(s, lhs+1, rhs) || isPalindromic(s, lhs, rhs-1);
		}
	}
	return true;
}

