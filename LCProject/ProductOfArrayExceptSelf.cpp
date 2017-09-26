/******************************************************************************
* Question: #238 Product of Array Except Self
* company tag: Amazon, LinkedIn
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
vector<int> productExcSelf(vector<int>& nums)
{
	int n = nums.size();
	vector<int> result(n, 1);
	long long product = 1;
	for(int i=0; i<n; i++)
	{
		result[i] = product;
		product *= nums[i];
	}
	product = 1;
	for(int i=n-1; i>=0; i--)
	{
		result[i] *= product;
		product *= nums[i];
	}
	return result;
}
