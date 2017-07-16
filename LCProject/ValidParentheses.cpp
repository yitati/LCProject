/******************************************************************************/
/*
* Question: #20 Valid Parentheses
* company tag: Facebook
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
/*****************************************************************************/

#include <string>
#include <stack>

using namespace std;

// push all left parenthese to stack, pop them out when meeting a corresponding right parentheses
bool isValid(string s) 
{
	if (s.empty()) return true;
	int len = s.length();
	if (len % 2 == 1) return false;
	stack<char> history;
	int i = 0;
	while (i < len)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') history.push(s[i++]);
		else
		{
			if (history.empty()) return false;
			if (history.top() == '(' && s[i] != ')') return false;
			if (history.top() == '[' && s[i] != ']') return false;
			if (history.top() == '{'&& s[i] != '}') return false;
			history.pop();
			i++;
		}
	}

	return history.empty();
}
