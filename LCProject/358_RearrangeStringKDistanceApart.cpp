/******************************************************************************/
/*
* Question: #358 Rearrange String k Distance Apart
* Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.
* All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
*
Example 1:
s = "aabbcc", k = 3
Result: "abcabc"
The same letters are at least distance 3 from each other.

Example 2:
s = "aaabc", k = 3
Answer: ""
It is not possible to rearrange the string.

Example 3:
s = "aaadbbcc", k = 2
Answer: "abacabcd"
Another possible answer is: "abcabcda"
The same letters are at least distance 2 from each other.
*
*/
/*****************************************************************************/

#include <string>

using namespace std;

// Similar problem - LC621 Task Scheduler

// helper function returns the element we want to put in position pos
// everytime we found the one with the largest frequency to be the valid one
int findValidIndex(vector<int>& count, vector<int>& valid, int pos)
{
	int indexToRet = -1, maxFreq = 0;
	for(auto i=0; i < count.size(); i++)
	{
		if(count[i] > maxFreq && pos >= valid[i])
		{
			maxFreq = count[i];
			indexToRet = i;
		}
	}
	return indexToRet;
}


string rearrangeString(string s, int k)
{
	// vector used to log the count of every char
	vector<int> count(26, 0);
	// vector used to indicate the valid position
	vector<int> valid(26, 0);
	for(char c : s) count[c-'a']++;
	string result;
	for(int pos = 0; pos < s.length(); pos++)
	{
		int index = findValidIndex(count, valid, pos);
		if(index == -1) return "";
		result.push_back('a' + index);
		count[index]--;
		valid[index] = pos+k;
	}
	return result;
}


