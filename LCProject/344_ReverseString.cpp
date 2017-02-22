/******************************************************************************/
/*
* Question: #34 Reverse String
* Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
/*****************************************************************************/

#include <string>

using namespace std;

string reverseString(string s) 
{
	if (s.empty() || s.size() == 1) return s;
	int len = s.length();
	int i = 0, j = len - 1;
	while (i < j)
	{
		char tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
	return s;
}