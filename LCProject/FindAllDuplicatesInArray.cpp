/******************************************************************************/
/*
* Question: #442 Find All Duplicates In an Array
* Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
* Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// same as #448 find all numbers disappeared in an array
vector<int> findDuplicates(vector<int>& nums) 
{
	vector<int> results;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		if (nums[i] == i + 1) continue;
		int curr = nums[i];
		if (nums[curr - 1] == curr) continue;
		swap(nums[i], nums[curr - 1]);
		i--;
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] != i + 1) results.push_back(i + 1);
	}

	return results;
}