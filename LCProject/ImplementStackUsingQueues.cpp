/******************************************************************************/
/**
* Question: #225 Implement Stack Using Queues
* Implement the following operations of a stack using queues. 
• push(x) -- Push element x onto stack. 
• pop() -- Removes the element on top of the stack. 
• top() -- Get the top element. 
• empty() -- Return whether the stack is empty. 
* Notes:
* You must use only standard operations of a queue -- 
* which means only push to back, peek/pop from front, size, and is empty operations are valid.
* Depending on your language, queue may not be supported natively. 
* You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
* You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

*
*****************************************************************************/

#include <vector>
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		m_queue.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int element = -1;
		if (!m_queue.empty())
		{
			for (int i = 0; i<(m_queue.size() - 1); i++)
			{
				element = m_queue.front();
				m_queue.pop();
				m_queue.push(element);
			}
			element = m_queue.front();
			m_queue.pop();
		}
		return element;
	}

	/** Get the top element. */
	int top() {
		int element = -1;
		if (!m_queue.empty())
		{
			for (int i = 0; i<m_queue.size(); i++)
			{
				element = m_queue.front();
				m_queue.pop();
				m_queue.push(element);
			}
		}
		return element;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return (m_queue.size() == 0);
	}

	queue<int> m_queue;
};