/******************************************************************************/
/*
* Question: #345 Reverse Vowels of a String
* Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
 Given s = "hello", return "holle". 

Example 2:
 Given s = "leetcode", return "leotcede". 

* Note:
* The vowels does not include the letter "y". 
*/
/*****************************************************************************/

#include <string>
#include <unordered_set>

using namespace std;

string reverseVowels(string s)
{
	unordered_set<char> vowels({ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' });
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (i < j && !vowels.count(s[i]))
		{
			i++;
			continue;
		}
		if (i < j && !vowels.count(s[j]))
		{
			j--;
			continue;
		}
		swap(s[i], s[j]);
		i++;
		j--;
	}
	return s;
}