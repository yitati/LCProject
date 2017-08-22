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
	int len = 0, lastLen = 0;
	for(int i=0; i<=s.length(); i++)
	{
		if(s[i] == ' ' || i == s.length())
		{
			if(len > 0) lastLen = len;
			len = 0;
		}
		else
		{
			len++;
		}
	}
	return lastLen;
}
