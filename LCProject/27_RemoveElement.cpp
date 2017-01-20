/******************************************************************************/
/*
* Question: #27 Remove Element
* Given an array and a value, remove all instances of that value in place and return the new length.
* Do not allocate extra space for another array, you must do this in place with constant memory.
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int n = nums.size();
	int search = 0, insert = 0;
	int count = 0;
	while (search < nums.size())
	{
		if (nums[search] != val)
		{
			nums[insert] = nums[search];
			insert++;
			count++;
		}
		search++;
	}

	return count;
}