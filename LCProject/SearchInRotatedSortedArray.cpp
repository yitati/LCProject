/******************************************************************************
* Question: #33 Search in Rotated Sorted Array
* company tag: LinkedIn
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* You are given a target dvalue to search. If found in the array return its index, otherwise return -1.
* You may assume no duplicate exists in the array.
*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int lhs = 0, rhs = n - 1;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) return mid;
		if (nums[mid] >= nums[lhs])
		{
			if (target < nums[mid] && target >= nums[lhs])
			{
				rhs = mid - 1;
			}
			else lhs = mid + 1;
		}
		else if (nums[mid] <= nums[rhs])
		{
			if (target > nums[mid] && target <= nums[rhs])
			{
				lhs = mid + 1;
			}
			else rhs = mid - 1;
		}
	}
	return -1;
}

/*
int main(int argc, char ** argv)
{
	int input1[] = { 4, 5, 6, 7, 0, 1, 2, 3 };
	vector<int> nums(input1, input1+sizeof(input1)/sizeof(int));

	cout << search(nums, 6) << endl; // expect 2
	cout << search(nums, 0) << endl; // expect 4

	system("pause");

}
*/
