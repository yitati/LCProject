/********************************************************************************************
 * Question #252 Meeting Room
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

 ******************************************************************************************/

#include <vector>
#include <algorithm>
#include "Interval.h"

using namespace std;

/*
 * a person can attend meeting when there is no overlap
 */

static bool intervalSort(const Interval& lhs, const Interval& rhs)
{
	return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.end < rhs.end);
}

bool canAttendMeetings(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), intervalSort);
	// check for overlapping
	for(int i=0; i+1 < intervals.size(); i++)
	{
		if(intervals[i].end > intervals[i+1].start) return false;
	}
	return true;
}

