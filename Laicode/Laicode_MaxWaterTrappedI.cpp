/*
 * Laicode_MaxWaterTrappedI.cpp

Given a non-negative integer array representing the heights of a list of adjacent bars.
Suppose each bar has a width of 1. Find the largest amount of water that can be trapped in the histogram.

Assumptions

The given array is not null
Examples

{ 2, 1, 3, 2, 4 }, the amount of water can be trapped is 1 + 1 = 2 (at index 1,
1 unit of water can be trapped and index 3, 1 unit of water can be trapped)

 */

#include <vector>
#include <climits>

using namespace std;

/*
 * at any point, the amount of rain water trapped is decided by the left
 */
// Solution 1 - dp, time complexit is O(n) and space complexity is O(n)


// Solution 2 - two pointers, time complexity is O(n) and space complexity is O(1)
int maxTrapped(vector<int> array)
{
	int lhs = 0, rhs = array.size()-1;
	int leftMax = INT_MIN, rightMax = INT_MIN;
	int water = 0;
	while(lhs < rhs)
	{
		if(array[lhs] <= array[rhs])
		{
			if(array[lhs] > leftMax) leftMax = array[lhs];
			else water += leftMax - array[lhs];
			lhs++;
		}
		else
		{
			if(array[rhs] >  rightMax) rightMax = array[rhs];
			else water += rightMax - array[rhs];
			rhs--;
		}
	}
	return water;
}


