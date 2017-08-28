/*
 * FBMJ_TaskScheduler.cpp
 *
 * Task scheduler will take all tasks, first in first serve. You are given a list of task id
 * and a cooldown time. And return totally how many time we need to process all the tasks.
 * Every task will take on time unit.
 * For example, tasks = [1, 1, 2, 1], cooldown = 2
 * 1 -> idle -> idle -> 1 -> 2 -> idle -> 1, so return 7
 * It is also found in the discussion here -
 * https://discuss.leetcode.com/topic/112/minimal-run-time-scheduler/13
 *
 */

#include <vector>

using namespace std;

int taskSchedulerRunning(vector<int>& tasks, int k)
{
	if(tasks.empty() || k < 0) return 0;
	int prev = tasks[0];
	int curr, len = 1;
	for(int i=0; i<tasks.size(); i++)
	{
		curr = tasks[i];
		if(curr == prev) len += k;
		// add curr to the len
		len += 1;
		prev = curr;
	}
	return len;
}
