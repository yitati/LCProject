/******************************************************************************
* Question: #150 Evaluate Reverse Polish Notation
* company tag: LinkedIn
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*****************************************************************************/

#include <string>
#include <vector>
#include <stack>

using namespace std;

inline bool isSymbol(string input)
{
	return (input == "+" || input == "-" || input == "*" || input == "/");
}

int evalRPN(vector<string>& tokens) 
{
	if (tokens.empty()) return 0;
	stack<int> numbers;
	int result = 0;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (!isSymbol(tokens[i]))
		{
			numbers.push(atoi(tokens[i].c_str()));
		}
		else
		{
			int opt1 = numbers.top();
			numbers.pop();
			int opt2 = numbers.top();
			numbers.pop();
			if (tokens[i] == "+") result = opt1 + opt2;
			else if (tokens[i] == "-") result = opt2 - opt1;
			else if (tokens[i] == "*") result = opt1 * opt2;
			else result = opt2 / opt1;
			numbers.push(result);
		}
	}
	return numbers.top();
}
