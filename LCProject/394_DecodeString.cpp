/******************************************************************************/
/*
* Question: #394 Decode String
* Given an encoded string, return it's decoded string. 
* The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is 
* being repeated exactly k times. Note that k is guaranteed to be a positive integer.

* You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

* Furthermore, you may assume that the original data does not contain any digits and that digits are only for those 
* repeat numbers, k. For example, there won't be input like 3a or 2[4]. 

Examples: 
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/
/*****************************************************************************/

#include <string>
#include <stack>

using namespace std;

string decodeString(string s)
{
	string str;
	int num = 0;
	stack<int> numStack;
	stack<string> strStack;

	for (char c : s)
	{
		if (c >= '0' && c <= '9')
		{
			num = num * 10 + c - '0';
		}
		else if ((c >= 'a'&& c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			str.push_back(c);
		}
		else if (c == '[')
		{
			numStack.push(num);
			num = 0;
			if (!str.empty())
			{
				strStack.push(str);
				str.clear();
			}
		}
		else // when char is  ']'
		{
			// first, pop out num and make it multiple string
			int cycle = numStack.top();
			numStack.pop();
			string unit = str;
			while (--cycle)
			{
				str += unit;
			}
			if (!strStack.empty())
			{
				str = strStack.top() + str;
				strStack.pop();
			}
		}
	}

	return str;
}