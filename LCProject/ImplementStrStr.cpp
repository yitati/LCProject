/******************************************************************************
* Question: #28 Implement strStr()
* company tag: Facebook
* Implement strStr().
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part
* of haystack.
* Follow-up: instead of looking for needle, what if we are looking for needle's permutation?
* Refer to problem: AllAnagrams
* Follow-up: what if we need to find all occurance of the needle?
*****************************************************************************/

#include <string>

using namespace std;

// Native solution
int strStr(string haystack, string needle) 
{
	int start = 0, i = 0;
	if (haystack.empty()) return needle.empty() ? 0 : -1;
	if (needle.empty()) return 0;
	for (start = 0; start + needle.length() <= haystack.length(); start++)
	{
		for (i = 0; i < needle.size(); i++)
		{
			if (haystack[start + i] != needle[i]) break;
		}
		if (i == needle.size()) return start;
	}
	return -1;
}

int findOccurance(string haystack, int needle)
{
	int start = 0, i = 0, count = 0;
	if(haystack.empty()) return needle.empty() ? 1 : 0;
	if(needle.empty()) return 0;
	for(start = 0; start + needle.length() <= haystack.length(); start++)
	{
		for(i=0; i<needle.size(); i++)
		{
			if(haystack[start+i] != needle[i]) break;
		}
		if(i == needle.size()) count++;
	}
	return count;
}
