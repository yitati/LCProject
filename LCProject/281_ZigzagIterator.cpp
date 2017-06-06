/******************************************************************************/
/*
* Question: #281 Zigzag Iterator
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:
v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, 
replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/
/*****************************************************************************/

#include <vector>
#include <queue>

using namespace std;

// one of the best idea seen on leetcode
class ZigzagIterator 
{
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) 
	{
		// take care of the corner cases
		if (!v1.empty()) index.emplace(v1.begin(), v1.end());
		if (!v2.empty()) index.emplace(v2.begin(), v2.end());
	}

	int next() 
	{
		auto curr = index.front();
		index.pop();
		int val = *curr.first;
		curr.first++;
		if (curr.first != curr.second)
		{
			index.push(curr);
		}
		return val;
	}

	bool hasNext() 
	{
		return index.empty() ? false : true;
	}
private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> index;
};