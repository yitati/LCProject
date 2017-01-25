/******************************************************************************/
/*
* Question: #35 Search Insert Postion
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.

* You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
// BST to find the closest neibours
int searchInsert(vector<int>& nums, int target) 
{
	if (nums.empty()) return 0;
	int n = nums.size();
	// if target out of boundary, return -1
	if (target <= nums[0]) return 0;
	if (target > nums[n - 1]) return n;

	int lhs = 0, rhs = n - 1;
	while (lhs < rhs - 1) // when comming out of loop, at least 2 elements
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (target == nums[mid]) return mid;
		else if (target < nums[mid]) rhs = mid;
		else lhs = mid;
	}
	// only lhs and rhs left, check the value
	return lhs + 1;
}