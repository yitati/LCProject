/******************************************************************************/
/*
* Question: #162 Find Peak Element
* A peak element is an element that is greater than its neighbors.
* Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
* The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
* You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums)
{
	int lhs = 0, rhs = nums.size() - 1;
	while (lhs + 1 < rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
		else if (nums[mid] < nums[mid - 1]) rhs = mid - 1;
		else lhs = mid + 1;
	}
	return lhs > rhs ? lhs : rhs;
}