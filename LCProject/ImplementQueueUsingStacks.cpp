/******************************************************************************/
/**
* Question: #232 Implement Queue Using Stacks
* Implement the following operations of a queue using stacks. 
• push(x) -- Push element x to the back of queue. 
• pop() -- Removes the element from in front of queue. 
• peek() -- Get the front element. 
• empty() -- Return whether the queue is empty. 
* Notes:
* You must use only standard operations of a stack -- 
* which means only push to top, peek/pop from top, size, and is empty operations are valid.
* Depending on your language, stack may not be supported natively. 
* You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
* You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*
*****************************************************************************/

#include <stack>

using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		m_stack.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int element = -1;
		if (!m_stackBack.empty())
		{
			element = m_stackBack.top();
			m_stackBack.pop();
			return element;
		}
		int len = m_stack.size();
		if (!m_stack.empty())
		{
			for (int i = 0; i < len; i++)
			{
				element = m_stack.top();
				m_stack.pop();
				m_stackBack.push(element);
			}
			m_stackBack.pop();
		}
		return element;
	}

	/** Get the front element. */
	int peek() {
		int element = -1;
		if (!m_stackBack.empty())
		{
			element = m_stackBack.top();
			return element;
		}
		int len = m_stack.size();
		if (!m_stack.empty())
		{
			for (int i = 0; i < len; i++)
			{
				element = m_stack.top();
				m_stack.pop();
				m_stackBack.push(element);
			}
		}
		return element;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (m_stack.size() == 0) && (m_stackBack.size() == 0);
	}

	stack<int> m_stack;
	stack<int> m_stackBack;
};