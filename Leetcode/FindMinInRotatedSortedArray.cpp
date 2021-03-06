/******************************************************************************/
/*
* Question: #153 Find Minimum in Rotated Sorted Array
* Suppose a sorted array is rotated at some pivot unknown to you beforehhand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* Find the minimum element.
* You may assume no duplicate exists in the array.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int findMinInRotatedSortedArray(vector<int>& nums) 
{
	int n = nums.size();
	int start = 0, end = n - 1;
	while (start < end)
	{
		if (nums[start] < nums[end]) return nums[start];
		int mid = start + (end - start) / 2;
		if (nums[mid] >= nums[start]) start = mid + 1;
		else end = mid;
	}
	return nums[start];
}