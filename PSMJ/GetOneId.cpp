/*
 * GetOneId.cpp
 *
已知一个叫get_ids()的API能够耗时1s并返回100个各不相同的id（第二次call返回的和第一次的也不会有任何重复），
有个待实现的函数叫get_one_id()，每秒最多被call 100次，每次call要能返回一个新的id。
题目就是利用get_ids()实现get_one_id()，follow up是保证每次call get_one_id()不能等待超过1s
用户会随机call int get_call_id(), 已经有 get_ids(int num_of_id, int *buf)，
get ids from disk or database，consume 1s per call。
实现get_call_id()，我是一步一步来的，先实现一个单线程的，满足average小于要求的，
然后多线程，然后improve，用了mutex和condition variable。最后还用到了tcp congestion control
（1. slow start 2. congestion avoid 3. congestion recovery， 有兴趣的可以网上查一下）
的机制来处理动态分配buf的要求。
 */

#include <queue>
#include <cstdlib>
#include <ctime>

#ifdef HASMUTEX

#include <mutex>
#include <condition_variable>

/*
 * randomly generate some id values
 */
srand(time(NULL));

void get_ids(int num_of_id, int *buf)
{
	for(int i=0; i<num_of_id; i++)
	{
		int id = rand()%100;
		buf[i] = id;
	}
}


queue<int> idQueue;
mutex m_mutex;
condition_variable m_cond;

/*
 * Solution 1: Create a queue for all id (int type) and enqueue all IDs we get from get_ids().
 * Then pop them out one by one when get_one_id() gets called.
 * Drawback: long wait time when queue is empty. Average wait time is smaller than 1s, but not garenteed that each call
 * shorter than 1s.
 *
 */
int get_one_id1()
{
	m_mutex.lock();
	if(!idQueue.empty())
	{
		char buf[100];
		get_ids(100, buf);
		for(int i=0; i<100; i++)
		{
			idQueue.push(buf[i]);
		}
	}
	int id = idQueue.front();
	idQueue.pop();
	m_mutex.unlock();
	return id;
}

/*
 * Solution 2: using producer-consumer model, with background producer, but still long wait.
 */


#endif
