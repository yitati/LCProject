/*
 * Laicode_LongestCommonSubsequence.cpp

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

// TODO BAOBAO

int longest(string s, string t)
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	unordered_set<char> collect;

	int i=0, j=0;
	while(i < s.length() && j < t.length())
	{
		if(s[i] == t[j])
  		{
  		  collect.insert(s[i]);
  		  i++;
  		  j++;
  		}
		else if(s[i] < t[j]) i++;
		else j++;
	}

	return collect.size();
}

