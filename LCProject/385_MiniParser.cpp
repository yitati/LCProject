/******************************************************************************/
/*
* Question: #385 Mini Parser
* Given a nested list of integers represented as a string, implement a parser to deserialize it.
* Each element is either an integer, or a list -- whose elements may also be integers or other lists.
* Note: You may assume that the string is well-formed: 
* String is non-empty.
* String does not contain white spaces.
* String contains only digits 0-9, [, - ,, ].

*/
/*****************************************************************************/

#include <stack>
#include "NestedInteger.h"

using namespace std;

inline void resetFlags(int & num, int & sign, bool & hasNum)
{
	num = 0;
	sign = 1;
	hasNum = false;
}

NestedInteger deserialize(string s) {
	NestedInteger result;
	int num = 0, sign = 1;
	bool hasNum = 0;
	stack<NestedInteger> table;

	for (char c : s)
	{
		if (c == '[')
		{
			table.push(NestedInteger());
			resetFlags(num, sign, hasNum);
		}
		else if (c == ']')
		{
			NestedInteger curr = table.top();
			table.pop();
			if (hasNum)  curr.add(NestedInteger(sign * num));
			if (table.empty()) result = curr;
			else table.top().add(curr);
			resetFlags(num, sign, hasNum);
		}
		else if (c == ',')
		{
			if (hasNum) table.top().add(NestedInteger(sign * num));
			resetFlags(num, sign, hasNum);
		}
		else
		{
			if (c == '-') sign = -1;
			else num = num * 10 + c - '0';
			hasNum = true;
		}
	}

	if (hasNum) result = NestedInteger(sign * num);

	return result;
}
