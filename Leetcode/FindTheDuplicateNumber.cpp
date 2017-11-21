/******************************************************************************/
/*
* Question: #287 Find The Duplicate Number
* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
* prove that at least one duplicate number must exist. 
* Assume that there is only one duplicate number, find the duplicate one.

* Note:
* You must not modify the array (assume the array is read only).
* You must use only constant, O(1) extra space.
* Your runtime complexity should be less than O(n2).
* There is only one duplicate number in the array, but it could be repeated more than once.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// binary search
int findDuplicate1(vector<int>& nums) 
{
	int n = nums.size();
	int lhs = 1, rhs = n;
	while (lhs < rhs)
	{
		int target = lhs + (rhs - lhs) / 2;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] <= target) count++;
		}
		if (count <= target) lhs = target + 1;
		else rhs = target;
	}
	return lhs;
	
}

// two pointers
int findDuplicate2(vector<int>& nums)
{
	int slow = nums[0];
	int fast = nums[nums[0]];
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	fast = 0;
	while (slow != fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}