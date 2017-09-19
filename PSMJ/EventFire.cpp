/*
 * EventFire.cpp
 *
We want to implement a callback mechanism that allows listeners to register a function that will be
invoked when the event fires.

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
		while(!m_callbacks.empty())
		{
			Callback cb = m_callbacks.front();
			m_callbacks.pop();
			cb.call();
		}
		m_eventTriggered = true;
	}

private:
	queue<Callback> m_callbacks;
	bool m_eventTriggered;
};

/*
 * Step 2: switch to multi-threading solution.
 * Q: If thread1 reads the flag, and evenTriggered is false, so we need to push it to queue. However before callback 1 is
 * pushed to queue, another thread2 called event_fired and cleared the queue. And after that, callback1 is pushed to queue.
 * Then callback1 will wait in queue forever.
 * 	- We need to toggle the flag at the end of the event_fired function.
 */
bool m_eventFired = false;
queue<Callback> m_callbacks;
mutex m_mutex;

void register_callback_update1(Callback & cb)
{
	/*
	 * we need to put lock here before the m_eventFired checking, so the flag cannot toggle before the push happens.
	 */
	m_mutex.lock();
	if(!m_eventFired)
	{
		m_callbacks.push(cb);
	}
	else
	{
		cb.call();
	}
	m_mutex.unlock();
}


/*
 * This will protect the atomicity for the flag but
 * Q: If a callback function invoke another regester_callback function, will there be deadlock?
 * Q: How is the efficiency?
 * 	- if cb.call() is calling another register function then there will be a deadlock.
 * 	- if the cb.call() takes long time then the critical section will be blocked for long time for other regestering.
 * so we need to update the function again.
 */
void register_callback_update2(Callback & cb)
{
	/*
	 * we need to put lock here before the m_eventFired checking, so the flag cannot toggle before the push happens.
	 */
	m_mutex.lock();
	if(!m_eventFired)
	{
		m_callbacks.push(cb);
		m_mutex.unlock();
	}
	else
	{
		m_mutex.unlock();
		cb.call();
	}
}

/*
 * Now let's move to fire_event
 */
void fire_event_update1()
{
	m_mutex.lock();
	while(!m_callbacks.empty())
	{
		Callback cb = m_callbacks.front();
		m_callbacks.pop();
		cb.call();
	}
	/*
	 * flag toggle happens here, after dealing with all callbacks that has registered before event fire
	 */
	m_eventFired = true;
	m_mutex.unlock();
}

/*
 * Same with register, non-reentrant mutex can cause deadlock with cb.call(), so need to update it as following
 */
void fire_event_update2()
{
	m_mutex.lock();
	while(!m_callbacks.empty())
	{
		Callback cb = m_callbacks.front();
		m_callbacks.pop();
		m_mutex.unlock();
		cb.call();
		m_mutex.lock();
	}
	/*
	 * flag toggle happens here, after dealing with all callbacks that has registered before event fire
	 */
	m_eventFired = true;
	m_mutex.unlock();
}

/*
 * Summary: exclude invoke() since we have no control; keep boolean isFired consistent with q status(q.isEmpty()),
 * which is achieved by the last acquire and release
 */

/*
 * to better improve above solution with condition variable
 */
class TaskDispatcher
{
private:
	bool isFired;
	queue<Task> tasks;
	mutex mtx;
	condition_variable cv;

public:
	TaskDispatcher()
	{
		isFired = false;
	}

	void registerTask(Task & t)
	{

		{
			// enter the scope of unique lock
			unique_lock<mutex> lck(mtx);

			if(!isFired)
			{
				task.push(t);
			}
			else
			{
				while(!task.empty())
				{
					cv.wait(lck);
				}
			}
		}
		t.invoke();
	}

	void fire()
	{
		unique_lock<mutex> lck(mtx);

		isFired = true;

		while(!tasks.empty())
		{
			Task * currTask = &tasks.front();
			lck.unlock();
			currTask->invoke();
			lck.lock();
			tasks.pop();
		}
		cv.notify_all();
	}

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

