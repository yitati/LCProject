/*
 * MinStack.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: JoanneY1
 */


#include <iostream>
#include <stack>

using namespace std;

class MinStackI {
public:
	/** initialize your data structure here. */
	MinStackI() {

	}

	void push(int x) {
		m_stack.push(x);
		if (m_minStack.empty()) m_minStack.push(x);
		else if (m_minStack.top() >= x) m_minStack.push(x); // take care of the duplicate
	}

	void pop() {
		if (m_stack.empty()) return;
		else if (m_stack.top() == m_minStack.top()) {
			m_minStack.pop();
		}
		m_stack.pop();
	}

	int top() {
		if (m_stack.empty()) return 0;
		else return m_stack.top();
	}

	int getMin() {
		if (m_minStack.empty()) return 0;
		return m_minStack.top();
	}

private:
	// m_stack to store all my numbers
	stack<int> m_stack;
	// m_minStack to store all mins
	stack<int> m_minStack;
};

/*
 * a memory reduction solution, the solution may overflow
 */
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
	}

	void push(int x) {
        long long xx = x;
		if(m_stack.empty())
		{
			m_stack.push(0);
			m_min = xx;
		}
		else
		{
			// push the diff and save current min
			m_stack.push(xx-m_min);
			if(xx < m_min) m_min = xx;
		}
	}

	void pop()
	{
		// pop out and update min
		if(m_stack.empty()) return;
		long long top = m_stack.top();
		m_stack.pop();
		if(top < 0) m_min = m_min-top;
	}

	int top() {
		long long top = m_stack.top();
        if (top > 0) return m_min + top;
        return m_min;
	}

	int getMin() {
		return m_min;
	}

private:
	// m_stack to store all my numbers
	stack<long long> m_stack;
	// current min value
	long long m_min;
};



