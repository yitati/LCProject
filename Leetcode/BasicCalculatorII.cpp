/******************************************************************************
* Question: #227 Basic Calculator
* company tag: Facebook
* Implement a basic calculator to evaluate a simple expression string.
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
* The integer division should truncate toward zero.
* You may assume that the given expression is always valid.

Some examples:

"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

* Note: Do not use the eval built-in library function. 
*
*****************************************************************************/

#include <string>
#include <stack>

using namespace std;

static bool isOperator(char x)
{
	return x == '+' || x == '-' || x == '*' || x == '/';
}

int calculateII(string s)
{
	stack<int> table;
	int len = s.length(), num = 0;
	char sign = '+';
	for (int i = 0; i < len; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0';
		if ((i == len - 1) || isOperator(s[i]))
		{
			if (sign == '+')
			{
				table.push(num);
			}
			else if (sign == '-')
			{
				table.push(-num);
			}
			else
			{
				int prev = table.top();
				table.pop();
				if (sign == '*') table.push(prev*num);
				else table.push(prev / num);
			}
			sign = s[i];
			num = 0;
		}
	}
	num = 0;
	while (!table.empty())
	{
		num += table.top();
		table.pop();
	}
	return num;
}
