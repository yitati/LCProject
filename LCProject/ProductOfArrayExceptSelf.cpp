/******************************************************************************
* Question: #238 Product of Array Except Self
* company tag: LinkedIn
* Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product 
* of all the elements of nums except nums[i].

* Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

* Follow up:
* Could you solve it with constant space complexity? 
* (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*****************************************************************************/

#include <vector>

using namespace std;

// output[i] = product of all numbers in the left * product of all numbers in the right
vector<int> productExceptSelf(vector<int>& nums) 
{
	int n = nums.size();
	vector<int> output(n, 1);
	int right = 1;
	// calculate the left product
	for (int i = 1; i < n; i++)
	{
		output[i] *= output[i - 1] * nums[i - 1];
	}
	// calculate the right product
	for (int i = n - 1; i >= 0; i--)
	{
		output[i] *= right;
		right *= nums[i];
	}
	return output;

}
