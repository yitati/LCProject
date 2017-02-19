/******************************************************************************/
/*
* Question: #28 Implement strStr()
* Implement strStr().
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
/*****************************************************************************/

#include <string>

using namespace std;

// 1. Native solution
int strStr(string haystack, string needle) 
{
	int start = 0, i = 0;
	if (haystack.empty()) return needle.empty() ? 0 : -1;
	if (needle.empty()) return 0;
	for (start = 0; start + needle.length() <= haystack.length(); start++)
	{
		if (haystack[start] != needle[0]) continue;
		for (i = 0; i < needle.size(); i++)
		{
			if (haystack[start + i] != needle[i]) break;
		}
		if (i == needle.size()) return start;
	}
	return -1;
}