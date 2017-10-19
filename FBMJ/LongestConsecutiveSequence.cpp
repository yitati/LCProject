/******************************************************************************
* Question: #128 Longest Consecutive Sequence
* company tag: Facebook, eBay
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Your algorithm should run in O(n) complexity.
*****************************************************************************/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) 
{
	int globalLen = 0;
	unordered_set<int> table;
	for (int val : nums)
	{
		table.insert(val);
	}

	for (int val : nums)
	{
		int length = 1;
		if (table.count(val) == 0) continue;
		table.erase(val);
		int i = val + 1, j = val - 1;
		while (table.count(i))
		{
			length++;
			table.erase(i++);
		}
		while (table.count(j))
		{
			length++;
			table.erase(j--);
		}
		globalLen = max(length, globalLen);
	}

	return globalLen;
}
