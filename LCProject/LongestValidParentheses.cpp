/******************************************************************************
* Question: #32 Longest Valid Parentheses
* company tag: Facebook
* Given a string containing just the characters '(' and ')', find the length of the longest 
* valid (well-formed) parentheses substring.
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*****************************************************************************/

#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// reverse the string, then we can get some overlapped part of the original string
// and the reversed string

// solution 1 - use stack
// loop the string and push '(' indices to the stack, then when meeting a ')', pop top if top is '(' indices
// then what left in stack are the not matched ones
int longestValidParentheses_stack(string s)
{
	stack<int> noMatch;
	int start = 0, end = s.length(), maxLen = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(') noMatch.push(i);
		else
		{
			if (!noMatch.empty())
			{
				int index = noMatch.top();
				if (s[index] == '(') noMatch.pop();
				else noMatch.push(i);
			}
			else
			{
				noMatch.push(i);
			}
		}
	}
	if (noMatch.empty()) return s.length();
	// then calculate the length
	while (!noMatch.empty())
	{
		start = noMatch.top();
		noMatch.pop();
		int currLen = end - start - 1;
		maxLen = max(maxLen, currLen);
		end = start;
	}
	maxLen = max(maxLen, end);

	return maxLen;
}

// solution 2 - dp solution
// suppose dp[i] denotes the longest length when ending i
// 1. when s[i] == '(' dp[i] = 0
// 2. when s[i] == ')' then 
// - if s[i-1] = '(' dp[i] = dp[i-2] + 2
// - if s[i-1] == ')' then the index which starts the length ending with i-1 is i-dp[i-1],
//   so the last one that before this string is i-1-dp[i-1], so if s[i-1-dp[i-1]] == '(' then
//   dp[i] = dp[i-1] + 2 + dp[i-2-dp[i-1]]
int longestValidParentheses_dp(string s)
{
	int len = s.length(), maxLen = 0;
	if (len <= 1) return 0;
	vector<int> dp(len, 0);
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(') dp[i] = (i >= 2) ? dp[i - 2] + 2 : 2;
			else
			{
				if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
				{
					dp[i] = dp[i - 1] + 2 + ((i - 2 - dp[i - 1] >= 0) ? dp[i - 2 - dp[i - 1]] : 0);
				}

			}
		}
		maxLen = max(maxLen, dp[i]);
	}
	return maxLen;
}
