/******************************************************************************/
/*
* Question: #283 Move Zeros
* company tag: Facebook
* Given an array nums, write a function to move all 0's to the end of it while 
* maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

* Note:
* You must do this in-place without making a copy of the array.
* Minimize the total number of operations.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// swap with the next non-zero element
void moveZeroes(vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != 0) continue;
		int j = i + 1;
		while (j>0 && j < nums.size() && nums[j] == 0) j++;
		if (j == nums.size()) break;
		swap(nums[i], nums[j]);
	}

}
