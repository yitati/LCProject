/******************************************************************************
* Question: #57 Insert Interval
* company tag: Facebook, LinkedIn, eBay
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

* You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Follow-up:
company tag: Facebook
给了一个情境。每次insert要返回当前总时间
TODO
*****************************************************************************/

#include <vector>
#include <algorithm>
#include "Interval.h"

using namespace std;

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
{
	vector<Interval> results;
	int i = 0;
	while (i<intervals.size() && intervals[i].end < newInterval.start)
	{
		results.push_back(intervals[i++]);
	}
	while (i<intervals.size() && intervals[i].start <= newInterval.end)
	{
		newInterval = Interval(min(intervals[i].start, newInterval.start), max(intervals[i].end, newInterval.end));
		i++;
	}
	results.push_back(newInterval);
	while (i<intervals.size()) results.push_back(intervals[i++]);
	return results;
}
