/******************************************************************************
* Question: #647 Panlindromic Substrings
* company tag: Facebook
* Given a string, your task is to count how many palindromic substrings in this string.
* The substrings with different start indexes or end indexes are counted as different substrings even they
* consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

* Note:
* The input string length won't exceed 1000.

*****************************************************************************/


#include <string>

using namespace std;

/*
 * solution 1 : use dp[i][j] as a bool to denote if s[i...j] is a palindrome or not
 * O(n^3) solution
 */
bool isPalindrome(string s)
{
    if(s.empty()) return false;
    int lhs = 0, rhs = s.length()-1;
    while(lhs <= rhs)
    {
        if(s[lhs] != s[rhs]) return false;
        lhs++;
        rhs--;
    }
    return true;
}

int countSubstrings1(string s)
{
    if(s.empty()) return 0;
    int n = s.length();
    int count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // then loop with length
    for(int len = 1; len <= n; len++)
    {
        for(int i=0; i<n; i++)
        {
            if(len == 1)
            {
                dp[i][i] = true;
                //cout << s.substr(i, 1) << endl;
                count++;
            }
            else
            {
                if(i+len <= n && isPalindrome(s.substr(i, len)))
                {
                    //cout << s.substr(i, len) << endl;
                    dp[i][i+len-1] = true;
                    count++;
                }
            }
        }
    }

    return count;
}

/*
 * solution 2 : choose each char as the center and extend odd / even to find palindrom strings
 * O(n^2) solution
 */

void extendPalindrome(string s, int lhs, int rhs, int& count)
{
	while(lhs >= 0 && rhs < s.length() && s[lhs] == s[rhs])
	{
		count++; lhs--; rhs++;
	}
}

int countSubstrings2(string s)
{
	if(s.empty()) return 0;
	int count = 0;
	for(int i=0; i < s.length(); i++)
	{
		extendPalindrome(s, i, i, count);
		extendPalindrome(s, i, i+1, count);
	}
	return count;
}

