/*
 * EBMJ_DesignThreadSafeHeap.cpp
 *
 *  Created on: Sep 2, 2017
 *      Author: JoanneY1
 */

#include <queue>
#include <thread>
#include <mutex>

using namespace std;

/*
 * the functionalities that we want to have here is
 * - push()
 * - pop()
 * - empty()
 * - size()
 * - top()
 */
/*

template <class T>
class MyHeap
{
public:
	void push(T val)
	{
		m_mutex.lock();
		m_heap.push(val);
		m_mutex.unlock();
	}

	T pop()
	{
		m_mutex.lock();
		T val = m_heap.top();
		m_heap.pop();
		m_mutex.unlock();
		return val;
	}

	int size()
	{
		return m_heap.size();
	}

	int empty()
	{
		return m_heap.empty();
	}

	int top()
	{
		m_mutex.lock();
		T val = m_heap.top();
		m_mutex.unlock();
		return val;
	}

private:
	priority_queue<T> m_heap;
	mutex m_mutex;
};

*/


