/******************************************************************************
* Question: #283 Move Zeros
* company tag: Facebook
* Given an array nums, write a function to move all 0's to the end of it while 
* maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

* Note:
* You must do this in-place without making a copy of the array.
* Minimize the total number of operations.
*****************************************************************************/

#include <vector>

using namespace std;

// to maintain the original order, we need to keep two pointers proceed to same directions
// O(n) time and O(1) space
void moveZeroes(vector<int>& nums)
{
	int n = nums.size(), slow = 0, fast = 0;
	while(fast < n)
	{
		if(nums[fast] != 0)
		{
			nums[slow++] = nums[fast];
		}
		fast++;
	}
	while(slow < n) nums[slow++] = 0;
}

// two way partition - this will also do the partition but won't keep the order
void moveZerosTowards(vector<int>& nums)
{
	int n = nums.size(), i = 0 , j = n-1;
	while(i <= j)
	{
		if(nums[i] == 0)
		{
			swap(nums[i], nums[j--]);
		}
		else
		{
			i++;
		}
	}
}

