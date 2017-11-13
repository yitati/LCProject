/*
 * LongestCommonSubsequence.cpp

Find the length of longest common subsequence of two given strings.

Assumptions

The two given strings are not null
Examples

S = “abcde”, T = “cbabdfe”, the longest common subsequence of s and t is {‘a’, ‘b’, ‘d’, ‘e’}, the length is 4.

 */

#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// LCS
int longestCommonSubsequence(string s, string t) {
  int sLen = s.length(), tLen = t.length();
  vector<vector<int>> dp(sLen+1, vector<int>(tLen+1, 0));

  for(int i=0; i<sLen; i++)
  {
    for(int j=0; j<tLen; j++)
    {
      /*
       * there are two situations
       * 1. when s[i] == t[j], compare with previous elements in both string, dp[i+1][j+1] = dp[i][j] + 1
       * 2. when s[i] != t[j], compare the current elements with previous one, dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
       */
      int extend = s[i] == t[j] ? 1 : 0;
      dp[i+1][j+1] = max(dp[i][j] + extend, max(dp[i][j+1], dp[i+1][j]));
    }
  }
  return dp[sLen][tLen];
}

