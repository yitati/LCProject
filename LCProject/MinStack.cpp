/******************************************************************************/
/**
* Question: #155 Min Stack
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*  * push(x) -- push element x onto stack
*  * pop() -- remove the element on top of the stack
*  * top() -- get the top element
*  * getMin() -- retrieve the minimum element in the stack
*
*  Example:
*  MinStack minStack = new MinStack();
*  minStack.push(-2);
*  minSTack.push(0);
*  minStack.push(-3);
*  minStack.getMin(); --> returns -3.
*  minStack.pop();
*  minStack.top();
*  minStack.getMin(); --> returns -2
*
*****************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		m_stack.push(x);
		if (m_minStack.empty()) m_minStack.push(x);
		else if (m_minStack.top() >= x) m_minStack.push(x);
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

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/


