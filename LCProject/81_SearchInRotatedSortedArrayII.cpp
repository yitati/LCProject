/******************************************************************************/
/*
* Question: #81 Seach in Rotated Sorted Array II
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* Would this affect the run-time complexity? How and why?
* Write a function to determine if a given target is in the array.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
	int n = nums.size();
	int lhs = 0, rhs = n - 1;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (nums[mid] == target) return true;
		// This is the tricky part !!!
		if (nums[lhs] == nums[mid] && nums[rhs] == nums[mid])
		{
			lhs++;
			rhs--;
		}
		else if (nums[mid] >= nums[lhs])
		{
			if (target < nums[mid] && target >= nums[lhs])
			{
				rhs = mid - 1;
			}
			else lhs = mid+1;
		}  
		else
		{
			if (target > nums[mid] && target <= nums[rhs])
			{
				lhs = mid+1;
			}
			else rhs = mid-1;
		}
	}
	return false;
}

/*
int main(int argc, char ** argv)
{
//	int input1[] = { 4, 4, 6, 6, 0, 1, 1, 3 };
//	int input1[] = { 1, 3, 1, 1, 1 };
	int input1[] = { 1 };
	vector<int> nums(input1, input1 + sizeof(input1) / sizeof(int));

	cout << search(nums, 1) << endl; // expect 0 or 1
	cout << search(nums, 3) << endl; // expect 2 or 3
	cout << search(nums, 5) << endl; // expect 4

	system("pause");

}
*/
