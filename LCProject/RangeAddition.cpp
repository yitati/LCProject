/************************************************************
 * Question #370 Range Addition
 * Assume you have an array of length n initialized with all 0's and are given k update operations.
 * Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each
 * element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
 * Return the modified array after all k operations were executed.

Example:
Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]


Explanation:
Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]

 ************************************************************/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Solution 1 - brutal force, worst case can be O(n^2)
vector<int> getModifiedArray_brutalforce(int length, vector<vector<int>>& updates)
{
	vector<int> result(length, 0);
	for(auto& item : updates)
	{
		for(int i = item[0]; i<= item[1]; i++)
		{
			result[i] += item[2];
		}
	}
	return result;
}

// Solution 2 - use scanning idea
vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
{
	vector<int> result(length, 0);
	if(updates.empty()) return result;
	// since there could be duplicates in the start/end point
	map<int, int> start;
	for(auto& item : updates)
	{
		start[item[0]] += item[2];     // from this index we need to add offset
		start[item[1]+1] -= item[2];   // from this index we need to reduce offset
	}
	int offset = 0;
	auto it = start.begin();
	for (int i = 0; i < length; i++)
	{
		if (i == it->first)
		{
			offset += it->second;
			it++;
		}
		result[i] += offset;
	}
	return result;
}

// We can also use vector instead of map here
