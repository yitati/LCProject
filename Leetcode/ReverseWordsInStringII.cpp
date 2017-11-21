/***********************************************************************************************
 * Question #186 Reverse Words In a String II
 * company tag: Facebook
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

 * Could you do it in-place without allocating extra space?
 ***********************************************************************************************/

#include <string>
#include <algorithm>

using namespace std;

void reverseWordsInString(string &s)
{
	// first reverse the whole string
	reverse(s.begin(), s.end());
	// reverse each word inside the string
	int i = 0;
	while(i < s.length())
	{
		int start = i;
		while(i < s.length() && s[i] != ' ') i++;
		reverse(s.begin() + start, s.begin() + i);  // !! be careful here end should be exclusive
		i++;
	}
}




