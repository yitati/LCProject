/*************************************************************************************
 * Question #253 Meeting Room II
 * Given an array of meeting time intervals consisting of start and end times [[s1, e1], [s2, e2], ...] (si < ei),
 * find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 *************************************************************************************/

#include <vector>
#include <algorithm>
#include "Interval.h"

using namespace std;
// finding the minimum number of conference rooms that means to find the max number
// of overlapped meetings, so we can use the idea of time scanning
int minMeetingRooms(vector<Interval>& intervals)
{
	vector<pair<int, int>> timeTable;        // need order by time
	for(auto& meet : intervals)
	{
		timeTable.emplace_back(meet.start, 1);
		timeTable.emplace_back(meet.end, -1);
	}
	/*
	 * since when doing acending order, will order first and then second
	 * so if end overlaps with start, we should count end first and then count start
	 */
	sort(timeTable.begin(), timeTable.end());

	int count = 0, maxCount = 0;
	for(auto& it : timeTable)
	{
		if(it.second == 1) count--;   // if one end time overlaps the other start time
		else count++;
		maxCount = max(maxCount, count);
	}
	return maxCount;
}


