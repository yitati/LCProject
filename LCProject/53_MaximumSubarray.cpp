/******************************************************************************/
/*
* Question: #53 Maximum Subarray
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
/*****************************************************************************/

#include <algorithm>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int sum = nums[0];
	int globalSum = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		sum = max(sum + nums[i], nums[i]);
		globalSum = max(globalSum, sum);
	}
	return globalSum;
}