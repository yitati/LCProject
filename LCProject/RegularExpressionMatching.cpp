/******************************************************************************
* Question: #10 Regular Expression Matching
* company tag: Facebook
* Implement regular expression matching with support for '.' and '*'.
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).

* The function prototype should be:
* bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*****************************************************************************/

#include <string>
#include <vector>

using namespace std;

/*
 * suppose dp[i+1][j+1] denotes matching from s[0, i] to p[0, j]
 * then if p[j] != '*' then dp[i+1][j+1] = dp[i][j] && s[i] matches p[j]
 * else if p[j] == '*'
 * 1. p[j] match zero preceding element dp[i+1][j+1] = dp[i+1][j-1]
 * 2. p[j] match 1 or more element dp[i+1][j+1] = dp[i][j+1] || s[i] matches p[j-1]
 *
 */
bool isRegExpMatch(string s, string p)
{
     int sLen = s.length(), pLen = p.length();
     vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));

     dp[0][0] = true;
     for(int j=0; j<pLen; j++) dp[0][j+1] = j > 0 && dp[0][j-1] && p[j] == '*'; // always matches empty

     for(int i=0; i<sLen; i++)
     {
         for(int j=0; j<pLen; j++)
         {
            if(p[j] != '*') dp[i+1][j+1] = dp[i][j] && (s[i] == p[j] || p[j] == '.');
            else dp[i+1][j+1] = (dp[i+1][j-1] && j > 0) || (dp[i][j+1] && (s[i] == p[j-1] || p[j-1] == '.'));
         }
     }
     return dp[sLen][pLen];
}
