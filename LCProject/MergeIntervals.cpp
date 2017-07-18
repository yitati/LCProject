/******************************************************************************
* Question: #56 Merge Intervals
* company tag: Facebook, LinkedIn
* Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

* Follow-up:
* 1. What is the total range that the merged interval covers? - merge and sum up
* 2. How to deal with 2-D intervals?
* company tag: Facebook
*****************************************************************************/

// TODO - how to deal with 2D intervals merge

#include <algorithm>
#include <vector>
#include "Interval.h"

using namespace std;

static bool wayToSort(Interval v1, Interval v2) { return v1.start < v2.start; };

vector<Interval> merge(vector<Interval>& intervals) 
{
	vector<Interval> result;
	sort(intervals.begin(), intervals.end(), wayToSort);
	for (int i = 0; i < intervals.size(); i++)
	{
		if (!result.empty() && result.back().end >= intervals[i].start)
		{
			result.back().end = max(intervals[i].end, result.back().end);
		}
		else result.push_back(intervals[i]);
	}
	return result;

}
