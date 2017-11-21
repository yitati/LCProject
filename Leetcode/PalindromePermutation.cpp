/******************************************************************************
* Question: #266 PalindromePermutation
* company tag: Facebook
* Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*****************************************************************************/

#include <string>
#include <unordered_map>

using namespace std;

/*
 * count the frequency of each char, and if only 1 char has odd frequency, that means it can be palindrome
 */

bool canPermutePalindrome(string s)
{
	bool hasOdd = false;
	unordered_map<char, int> freq;
	for(int c : s)
	{
		freq[c]++;
	}
	for(auto it = freq.begin(); it != freq.end(); it++)
	{
		if(it->second%2 == 0) continue;
		else
		{
			if(hasOdd) return false;
			hasOdd = true;
		}
	}
	return true;
}


