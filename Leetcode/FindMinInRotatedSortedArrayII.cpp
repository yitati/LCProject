/******************************************************************************/
/*
* Question: #154 Find Minimum in Rotated Sorted Array II
* Follow up for  "Find Minimum in Rotated Sorted Array"
* What if duplicates are allowed?
* Would this affect the run-time complexity? How and why?
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// compare with only nums[end]

int findMinInRotatedSortedArrayII(vector<int>& nums)
{
	int n = nums.size();
	int start = 0, end = n - 1;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] > nums[end]) start = mid + 1;
		else if (nums[mid] < nums[end]) end = mid;
		else end--;
	}
	return nums[start];
}