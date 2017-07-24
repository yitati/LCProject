/******************************************************************************
* Question: #151 Reverse Words In A String
* Given an input string, reverse the string word by word. 

For example,
 Given s = "the sky is blue",
 return "blue is sky the". 

Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space. 

* Clarification:
* What constitutes a word?
* A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
* Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
* Reduce them to a single space in the reversed string.
*****************************************************************************/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void reverseWords(string &s) 
{
	int startPoint = 0, i = 0, j= 0;
	reverse(s.begin(), s.end());
	for (; i < s.length(); i++)
	{
		if (s[i] != ' ') 
		{
			if (startPoint != 0) s[startPoint++] = ' ';
			j = i;
			while (j < s.length() && s[j] != ' ')
			{
				s[startPoint++] = s[j++];
			}
			reverse(s.begin() + startPoint - (j-i), s.begin() + startPoint);
			i = j;
		}
	}
	s.erase(s.begin() + startPoint, s.end());
}

/*
int main(int argc, char ** argv)
{
	string str1 = "the sky is blue";
	string str2 = "     ";
	string str3 = "  the sky  ";
	string str4 = "the";

	reverseWords(str1);
	reverseWords(str2);
	reverseWords(str3);
	reverseWords(str4);

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;

	system("pause");

}
*/
