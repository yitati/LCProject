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

#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
private:
	int m_integer;
	vector<NestedInteger> m_list;
	bool m_isInteger;
public:
	// Constructor initializes an empty nested list.
	NestedInteger() {
		m_isInteger = false;
	}

	// Constructor initializes a single integer.
	NestedInteger(int value) {
		m_isInteger = true;
		m_integer = value;
	}

	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const {
		return m_isInteger;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const {
		return m_integer;
	}

	// Set this NestedInteger to hold a single integer.
	void setInteger(int value) {
		m_isInteger = true;
		m_integer = value;
	}

	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni) {
		m_isInteger = false;
		m_list.push_back(ni);
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const {
		return m_list;
	}
};

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
