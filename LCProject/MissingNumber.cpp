/******************************************************************************/
/*
* Question: #268 Missing Number
* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

* Note:
* Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*
*/
/*****************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

// the number ranges from 0 to n and one of them is missing
int missingNumber1(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	int i = 0;
	for (; i < nums.size(); i++)
	{
		if (nums[i] != i) return i;
	}
	return i;
}

int missingNumber2(vector<int>& nums)
{
	int n = nums.size(), sum = 0;
	int expect = n*(n + 1) / 2;
	for (int i = 0; i<n; i++)
	{
		sum += nums[i];
	}
	return expect - sum;

}