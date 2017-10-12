/*
 * ExclusiveTimeFunctions.cpp
 *
Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU,
find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts
from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other
functions should not be considered as this function's exclusive time. You should return the exclusive time of
each function sorted by their function id.
 */

#include <vector>
#include <string>
#include <stack>

using namespace std;

void getInfo(string& log, int& id, int& time, bool& start) {
	int pos1 = log.find(':');
	int pos2 = log.rfind(':');
	start = log.substr(pos1 + 1, pos2 - pos1 - 1) == "start" ? true : false;
	for (int i = 0; i < pos1; i++) id = id * 10 + log[i] - '0';
	for (int i = pos2 + 1; i < log.size(); i++) time = time * 10 + log[i] - '0';
}

vector<int> exclusiveTime(int n, vector<string>& logs) {
	vector<int> exeTime(n, 0); // result
	stack<pair<int, int>> table; // id - time pair

	for (string& log : logs) // string&
	{
		int id = 0, time = 0;
		bool start = false;
		getInfo(log, id, time, start);

		if (start) {
			table.push(make_pair(id, time));
		}
		else {
			int period = time - table.top().second + 1;
			table.pop();
			exeTime[id] += period;
			if (!table.empty())
			{
				exeTime[table.top().first] -= period;
			}
		}
	}

	return exeTime;
}

