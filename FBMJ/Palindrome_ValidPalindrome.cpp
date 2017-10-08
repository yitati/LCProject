
#include <string>
#include <iostream>

using namespace std;

/*
 * Valid Palindrome I
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 */
bool isSameLetter(char x, char y)
{
	if (x == y) return true;
	if ((x >= '0' && x <= '9') || (y >= '0' && y <= '9')) return false;
	return abs(x - y) == 32 ? true : false;
}

inline bool isAlphanumeric(char x)
{
	return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9'));
}

bool isPalindrome(string s)
{
	if (s.empty() || s.size() == 1) return true;
	int len = s.length();
	int i = 0, j = len-1;
	while(i < j)
	{
		if (!isAlphanumeric(s[i])) {
			i++;
			continue;
		}

		if (!isAlphanumeric(s[j])) {
			j--;
			continue;
		}
		if (!isSameLetter(s[i], s[j])) return false;
		i++;
		j--;
	}

	return true;
}

/*
 * Valid Palidrome II
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
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

bool validPalindromeII(string s)
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

