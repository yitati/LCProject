#include <algorithm>
#include <vector>

#include "../Leetcode/Interval.h"

using namespace std;
/*
 * Merge Intervals: the given interval vector is not sorted so we need to first sort it
 */
vector<Interval> merge(vector<Interval>& intervals)
{
	// sort the interval using lambda function
	sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval & rhs)->bool{
		lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
	});

	vector<Interval> result;

	for(int i=0; i<intervals.size(); i++)
	{
		if(result.empty() || result.back().end < intervals[i].start) result.push_back(intervals[i]);
		result.back().end = max(result.back().end, intervals[i].end);
	}

	return result;
}

/*
 * Insert Intervals
 */
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	vector<Interval> result;
	int i = 0;

	while(i < intervals.size() && intervals[i].end < newInterval.start) result.push_back(intervals[i++]);

	while(i < intervals.size() && intervals[i].start <= newInterval.end)
	{
		newInterval.start = min(newInterval.start, intervals[i].start);
		newInterval.end = max(newInterval.end, intervals[i].end);
		i++;
	}
	result.push_back(newInterval);
	while(i < intervals.size())
	{
		result.push_back(intervals[i++]);
	}

	return result;
}



