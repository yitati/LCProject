/*
 * EventFire.cpp
 *
We want to implement a callback mechanism that allows listeners to register a function that will be
invoked when then event fires.

The API functions are register_callback and event_fired.
	1. There is only one event and it will fire only once.
	2. Callbacks registerd before the event fires shouldn't block waiting for the event to fire.
	3. Callbacks registered after the event fires should get invoked ASAP.


	                                 event_fired()
	                                      |
	                                      |
   ------------------------------------------------------------------------------------>time
       |            |                 cb1.call()                  |
       |            |                 cb2.call()                  |
    reg_cb(cb1)  reg_cb(cb2)                                   reg_cb(cb3)
                                                               cb3.call()
 */

#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

#ifdef HASMUTEX

class Callback{
public:
	Callback():m_id(0){}

	Callback(int id){
		m_id = id;
	}

	void call()
	{
		// do something here
	}

private:
	int m_id;
};

/*
 * Step 1: Design a single thread solution
 */
class Event
{
public:
	Event(){
		m_eventTriggered = false;
	}

	void register_callback(Callback & cb)
	{
		if(m_eventTriggered)
		{
			cb.call();
		}
		else
		{
			m_callbacks.push(cb);
		}
	}

	void event_fired()
	{
		m_eventTriggered = true;
		while(!m_callbacks.empty())
		{
			Callback cb = m_callbacks.front();
			m_callbacks.pop();
			cb.call();
		}
	}

private:
	queue<Callback> m_callbacks;
	bool m_eventTriggered;
};

/*
 * Step 2: switch to multi-threading solution.
 * We want to introduce multiple threads, one main thread handling register callback and event firing.
 * The other threads can handle the actual calling of callbacks.
 * Keep critical section as small as possible to avoid deadlock.
 *
 */
class ThreadSafeEvent
{
public:
	ThreadSafeEvent(){
		m_eventTriggered = false;
	}

	void register_callback(Callback & cb)
	{
		if(m_eventTriggered)
		{
			cb.call();
		}
		else
		{
			m_mutex.lock();
			m_callbacks.push(cb);
			m_mutex.unlock();
		}
	}

	bool isQueueEmpty()
	{
		bool empty;
		m_mutex.lock();
		empty = m_callbacks.empty();
		m_mutex.unlock();
		return empty;
	}


	void event_fired()
	{
		m_eventTriggered = true;
		while(!isQueueEmpty())
		{
			m_mutex.lock();
			Callback cb = m_callbacks.front();
			m_callbacks.pop();
			m_mutex.unlock();
			cb.call();
		}
	}

private:
	// shared resource
	queue<Callback> m_callbacks;
	bool m_eventTriggered;
	mutex m_mutex;
};

/*
 * Step 3 : Improve efficiency.
 * If callback function takes much time, the other dequeue actions have to wait. This limit the efficiency of the
 * event_fired. We want to dispatch as many workers as possible.
 * Every worker will work independantly and everytime it will check if queue is empty and if event is fired. If
 * condition satisfied it will dequeue one callback and execute. In this case, we want to use a conditional
 * variable to indicate the condition has been satisfied or not.
 */
class MultiWorkerEvent
{
public:
	MultiWorkerEvent(){
		m_eventTriggered = false;
	}

	/*
	 * start worker thread
	 */
	void start(int workerCount)
	{
		m_workers.clear();
		for(int i=0; i<workerCount; i++)
		{
			m_workers.push_back(thread(&MultiWorkerEvent::worker, this));
		}
	}

	/*
	 * join every worker thread
	 */
	void join()
	{
		for(int i=0; i<m_workers.size(); i++)
		{
			m_workers[i].join();
		}
	}
	/*
	 * non-blocking call
	 */
	void register_callback(Callback cb)
	{
		m_mutex.lock();
		m_callbacks.push(cb);
		if(m_eventTriggered)
		{
			m_cond.notify_all();
		}
		m_mutex.unlock();
	}

	/*
	 * non-blocking call
	 */
	void event_fire()
	{
		m_mutex.lock();
		m_eventTriggered = true;
	}

	/*
	 * this is a blocking process to consume the callback in the shared queue
	 */
	void worker()
	{
		while(true)
		{
			// lock mutex with unique_lock
			unique_lock<mutex> lock(m_mutex);
			if(m_callbacks.empty() || !m_eventTriggered)
			{
				m_cond.wait(lock, [this]() -> bool {
					return !this->m_callbacks.empty() && this->m_eventTriggered;
				});
			}
			Callback cb = m_callbacks.front();
			m_callbacks.pop();
			lock.unlock();
			if(cb.id == -1) break;
			cb.call();
		}
	}

private:
	// shared resource
	queue<Callback> m_callbacks;
	vector<thread> m_workers;
	bool m_eventTriggered;
	mutex m_mutex;
	condition_variable m_cond;
};

/*
 * main function
 */
int main(int argc, char ** argv)
{
	MultiWorkerEvent handler;
	handler.start(4);
	handler.register_callback(Callback(0));
	handler.register_callback(Callback(1));
	handler.register_callback(Callback(2));
	handler.event_fire();
	handler.register_callback(Callback(3));
	handler.register_callback(Callback(4));
	for(int i=0; i<5; i++)
	{
		handler.register_callback(Callback(-1));
	}
	handler.join();

}

#endif

