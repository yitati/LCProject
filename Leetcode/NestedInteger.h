#pragma once

#include <vector>

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