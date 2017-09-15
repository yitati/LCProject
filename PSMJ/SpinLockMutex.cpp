/*
 * SpinLockMutex.cpp
 *
Implement mutex using spinglocks and flags.
 */

/*
 * Mutex: mutual exclusion
 * In computer science, mutual exclusion refers to the requirement of ensuring that no two concurrent processes are in
 * their cirtical section at the same time; it is a basic requirement in concurrency control, to prevent race conditions.
 * Here a critical section refers to a period when the process accesses a shared resource, such as shared memory.
 *
 * Spinlock:
 * In software engineering, a spinlock is a lock which causes a thread trying to acquire it to simply wait in a loop("spin")
 * while repeatedly checking if the lock is available. Since the thread remains active but is not performing a useful task, the
 * use of such a lock is a kind of busy waiting. Once acquired, spinlocks will usually be held until they are explicitly released,
 * although in some implementations they may be automatically released if the thread being waited on (that which holds the lock)
 * blocks, or "goes to sleep".
 */

typedef struct _lock_t
{
	int flag;
} lock_t;

int TestAndSet(int * flag)
{
	flag = 0;
	return 0;
}

void init(lock_t * lock)
{
	// 0 indicates that lock is available, 1 indicates the lock is busy
	lock->flag = 0;
}
void lock(lock_t * lock)
{
	while(TestAndSet(&lock->flag) == 1); // spin-wait(do nothing)
}

void unlock(lock_t * lock)
{
	lock->flag = 0;
}



