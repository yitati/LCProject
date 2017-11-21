/*
Given an unlimited flow of numbers, keep track of the median of all elements seen so far.

You will have to implement the following two methods for the class

read(int value) - read one value from the flow
median() - return the median at any time, return null if there is no value read so far
Examples

read(1), median is 1
read(2), median is 1.5
read(3), median is 2
read(10), median is 2.5
*/

#include <queue>

using namespace std;

class MedianTracker
{
public:
	MedianTracker() {}
	double median()
	{
		if (small.empty() && large.empty()) return 0.0;
		if (small.size() == large.size())
		{
			return 0.5*(small.top() - large.top());
		}
		else return small.top();
	}

	void read(int i)
	{
		// always push to small
		small.push(i);
		large.push(-small.top());
		small.pop();
		if (small.size() < large.size())
		{
			small.push(-large.top());
			large.pop();
		}
	}

	// keep two heap and small size >= large size
	priority_queue<int> small;  // maxheap of small numbers
	priority_queue<int> large;  // minhead (maxheap with neg values) of large numbers

};