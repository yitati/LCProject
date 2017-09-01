/*****************************************************************************
* Question: #41 First Missing Positive
* company tag: eBay
* Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

// One solution idea - to use extra N space to store the arrary and use a flag to mark if number k exits
// on position k-1. So if position flag[x-1] not marked then return x
// But to switch to constant space - we can put numbers "in place" by doing a swaping
// Always put k in nums[k-1] (if nums[k-1] != k)

int firstMissingPositive(vector<int>& nums) 
{
	int n = nums.size();
	int i = 0;
	// put numbers in place
	for (i = 0; i < n; i++)
	{
		if (nums[i] == i + 1) continue;
		if (nums[i] > n || nums[i] <= 0) continue;
		if (nums[i] == nums[nums[i] - 1]) continue;
		// k found in [1, n]
		swap(nums[i], nums[nums[i] - 1]);
		i--;
	}

	for (i = 0; i < n; i++)
	{
		if (nums[i] == i + 1) continue;
		return i + 1;
	}

	return i + 1;
}
