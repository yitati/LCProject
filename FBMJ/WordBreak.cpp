/*
 * WordBreak.cpp
 *
给一个字符串 such as: "GoogleFacebookMicrosoft", 由字母构成，然后给一个字典，把给定的字符按照字典进行切割，然后输出分割后的一个解答，
例如：dict=['Google', 'Facebook', 'Microsoft', 'GoogleFace', 'bookMicsoft']
如果有多个解答，输出一个即可，对于这个例子显然有两个解答，"Google Facebook Microsoft"， "GoogleFace bookMicrosoft"。
随便输出一个就行, 我回答，递归可以做，然后给出了答案，分析了复杂度O(n^m)。这里复杂度分析卡了一下，不过还好

followup，有没有其他方法可以做？我说可以DP做，f[i] = True意味着0～i-1存在 matching，
为了输出一个solution，用g[i+len(w)] = i记录结果，然后回溯方法可以输出一个答案。interviewer跑了个conner case比较满意。

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=207049&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;

/*
 * above question is similar to word break I, we just need to add the substring when everytime it is true
 */

string getCutString(string input, vector<string>& wordDict)
{
  unordered_set<string> dict;
  for(string word : wordDict) dict.insert(word);

  int ilen = input.length();
  vector<int> dp(ilen+1, -1);
  dp[0] = 0;

  for(int i=0; i<ilen; i++)
  {
    if(dict.count(input.substr(0, i+1)))
    {
      dp[i+1] = 0;
      continue;
    }
    for(int j=i-1; j>=0; j--)
    {
      if(dp[j+1] != -1 && dict.count(input.substr(j+1, i-j)))
      {
        dp[i+1] = j+1;
      }
    }
  }

  // get the result string
  string result;
  int i = ilen-1;
  while(dp[i+1] != -1)
  {
    result = result + " " + input.substr(dp[i+1], i-dp[i+1]+1);
    i = dp[i+1] - 1;
  }

  return result;
}

/*
 * word break I, return boolean
dp[i+1] to denote that str[0, i] can do word break
then for a possible j > i, then dp[j+1] is true when dp[i+1] is true and
str[i+1, j] can be found in the dictionary
*/
bool wordBreak(string s, vector<string>& wordDict)
{
	unordered_set<string> dict;
	for (string word : wordDict)  dict.insert(word);

	int slen = s.length();
	vector<bool> dp(slen + 1, false);
	dp[0] = true;

	for (int j = 0; j < slen; j++) {
		if (dict.count(s.substr(0, j + 1)))
			dp[j + 1] = true;
		else {
			for (int i = j - 1; i >= 0; i--) {
				if (dp[i + 1] && dict.count(s.substr(i + 1, j - i))) {
					dp[j + 1] = true;
					break;
				}
			}
		}
	}
	return dp[slen];
}

/*
Word Breakk II
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

/*
if s[0, i] is a valid string that can do word break, then there are two possibilities
1. s[0, i] is a word in the dict
2. there exists a j < i, that s[0, j] can do word break and s[j+1..i] is a word in dict
so we use an array to store all possible j values
*/
void fillWordBreak(const string& s, vector<string>& results, vector<vector<int>>& dp, string curr, int rhs);

vector<string> wordBreakII(string s, vector<string>& wordDict)
{
    unordered_set<string> dict;
    for (string word : wordDict) dict.insert(word);

    int slen = s.length();
    vector<vector<int>> dp(slen);

    // O(n^2)
    for (int i = 0; i < slen; i++)
    {
        if (dict.count(s.substr(0, i + 1))) dp[i].push_back(-1);
        for (int j = 0; j <= i; j++)
        {
            if (!dp[j].empty() && dict.count(s.substr(j + 1, i - j))) dp[i].push_back(j);
        }
    }

    vector<string> results;
    fillWordBreak(s, results, dp, "", slen - 1);

    return results;
}

void fillWordBreak(const string& s, vector<string>& results, vector<vector<int>>& dp, string curr, int rhs) {
    if (rhs == -1)
    {
        curr.pop_back(); // curr is empty and we have one more space at last, so remove it
        results.push_back(curr);
        return;
    }

    for (int lhs : dp[rhs])
    {
        string sub = s.substr(lhs + 1, rhs - lhs);
        fillWordBreak(s, results, dp, sub + " " + curr, lhs);
    }
}
