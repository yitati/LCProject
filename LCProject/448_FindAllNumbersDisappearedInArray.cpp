/******************************************************************************/
/*
* Question: #448 Find All Numbers Disappeared In an Array
* Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
* Find all the elements of [1, n] inclusive that do not appear in this array.
* Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/
/*****************************************************************************/

#include <vector>

using namespace std;

vector<int> findDisappearedNumbers1(vector<int>& nums) 
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

// nagate the numbers
vector<int> findDisappearedNumbers2(vector<int>& nums)
{
	vector<int> results;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		int index = nums[i];
		if (nums[abs(index) - 1] > 0) nums[abs(index) - 1] = -nums[abs(index) - 1];
	}

	for (int i = 0; i < n; i++)
	{
		if (nums[i] > 0) results.push_back(i + 1);
	}

	return results;
}