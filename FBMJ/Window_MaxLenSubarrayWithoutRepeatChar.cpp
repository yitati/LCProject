/*
 * Window_MaxLenSubarrayWithoutRepeatChar.cpp
 *
Given a string, find the length of the longest substring without repeating characters.

 */

#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<bool> visit(256, false);

    int lhs = 0, rhs = 0, maxLen = 0;
    while(rhs < s.length())
    {
        if(!visit[s[rhs]])
        {
            visit[s[rhs]] = true;
            rhs++;
            maxLen = max(maxLen, rhs-lhs);
        }
        else
        {
            visit[s[lhs]] = false;
            lhs++;
        }
    }

    return maxLen;
}




