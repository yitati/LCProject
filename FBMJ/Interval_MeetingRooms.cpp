/*************************************************************************************
 * Meeting Room II
 * Given an array of meeting time intervals consisting of start and end times [[s1, e1], [s2, e2], ...] (si < ei),
 * find the minimum number of conference rooms required.
 *************************************************************************************/

#include <vector>
#include <algorithm>
#include "Interval.h"

using namespace std;

/*
 * Meeting Room I, decide if one person can attend all meetings (if there is overlap)
 * time complexity: O(nlogn)
 */
bool canAttendMeetings(vector<Interval>& intervals)
{
	// sort the intervals and check if they are non-overlapped
	sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs)
			{
				return (lhs.start < rhs.start) || (lhs.start == rhs.start && lhs.end < rhs.end);
			});

	for(int i=0; i<intervals.size()-1; i++)
	{
		if(intervals[i].end > intervals[i+1].start) return false;
	}

	return true;
}


/*
 * solution 1: Use minHeap to store how many meeting rooms we need
 */
int meetingRoomsMinHeap(vector<Interval>& intervals)
{
	// sort the meeting rooms by start time
	sort(intervals.begin(), intervals.end(), [](const Interval& lhs, const Interval& rhs)
	{
		return lhs.start < rhs.start;
	});

	// create a min heap for end time, the minHeap represents the number of rooms we need
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for(auto meeting : intervals)
	{
		if(!minHeap.empty() && minHeap.top() <= meeting.start)
		{
			minHeap.pop();
		}
		minHeap.push(meeting.end);
	}

	return minHeap.size();
}


/*
 * solution 2: Linear sweep the time and find the number of overlapped meetings
 */
int meetingRoomsLinarSweep(vector<Interval>& intervals)
{
	vector<pair<int, int>> timeTable;        // need order by time
	for(auto& meet : intervals)  // O(n) time
	{
		timeTable.emplace_back(meet.start, 1);
		timeTable.emplace_back(meet.end, -1);
	}
	/*
	 * since when doing acending order, will order first and then second
	 * so if end overlaps with start, we should count end first and then count start
	 */
	sort(timeTable.begin(), timeTable.end());  // approximately O(nlogn) time

	int count = 0, maxCount = 0;
	for(auto& it : timeTable)  // O(n) time
	{
		if(it.second == -1) count--;   // if one end time overlaps the other start time
		else count++;
		maxCount = max(maxCount, count);
	}
	return maxCount;
}

/*
 * a more simplified version of the above solution, by using a map
 * time complexity is O(nlogn)
 */
int meetingRoomsMap(vector<Interval>& intervals)
{
	// use an ordered map
	map<int, int> table;
	// insertion is O(nlogn)
	for(auto meeting : intervals)
	{
		table[meeting.start]++;
		table[meeting.end]--;
	}

	int room = 0, res = 0;
	for(auto it : table)
	{
		room += it.second;
		res = max(res, room);
	}
	return res;
}

/*
 * solution 3: use two vectors to store the sorted start point and sorted end point
 * and use two pointers to calculate the overlap
 * Time: O(nlogn) Space: O(n)
 */
int meetingRoomsTwoPointers(vector<Interval>& intervals)
{
	vector<int> starts;
	vector<int> ends;

	int room = 0, endpos = 0;

	for(auto meeting : intervals)
	{
		starts.push_back(meeting.start);
		ends.push_back(meeting.end);
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	for(int i=0; i<intervals.size(); i++)
	{
		if(starts[i] < ends[endpos]) room++;
		else endpos++;
	}

	return room;


}
