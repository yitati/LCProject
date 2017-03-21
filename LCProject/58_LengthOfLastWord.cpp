/******************************************************************************/
/*
* Question: #58 Length Of Last Word
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* If the last word does not exist, return 0.
* Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
 Given s = "Hello World",
 return 5. 

*/
/*****************************************************************************/
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
	if (s.empty()) return 0;
	int len = s.length(), wordLen = 0, lastLen = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			if (wordLen > 0)lastLen = wordLen;
			wordLen = 0;
			continue;
		}
		else
		{
			wordLen++;
			if (i == len - 1) lastLen = wordLen;
		}
	}
	return lastLen;
}