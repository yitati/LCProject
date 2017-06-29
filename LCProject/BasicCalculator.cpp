/******************************************************************************/
/**
* Question: #224 Basic Calculator
* Implement a basic calculator to evaluate a simple expression string.
* The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
* non-negative integers and empty spaces .

* You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

* Note: Do not use the eval built-in library function. 
*
*****************************************************************************/
#include <string>
#include <stack>

using namespace std;

int calculateI(string s) {
	if (s.empty()) return 0;
	stack<int> table;
	int sign = 0;
	long long num = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') continue;
		else if (s[i] == '+')
		{
			sign = 1;
			continue;
		}
		else if (s[i] == '-')
		{
			sign = -1;
			continue;
		}
		else if (s[i] == '(')
		{
			table.push(num);
			table.push(sign);
			num = 0;
			sign = 0;
		}
		else if (s[i] == ')')
		{
			sign = table.top();
			table.pop();
			int prevNum = table.top();
			table.pop();
			if (sign != 0)
			{
				num = prevNum + sign * num;
				sign = 0;
			}
		}
		else
		{
			long long x = 0;
			while (s[i] >= '0' && s[i] <= '9') x = x * 10 + s[i++] - '0';
			i--;
			if (sign == 0) num = x;
			else
			{
				if (sign == 1) num += x;
				else num -= x;
				sign = 0;
			}
		}
	}
	return num;
}