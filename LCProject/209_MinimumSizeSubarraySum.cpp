/******************************************************************************/
/**
* Question: #209 Minimum Size Subarray Sum
* Given an array of n positive integers and a positive integer s, 
* find the minimal length of a contiguous subarray of which the sum ≥ s. 
* If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int minSubArrayLength(int s, vector<int>& nums) 
{
	int n = nums.size(), minLen = INT_MAX;
	int lhs = 0, rhs = 0, sum = 0;
	while (rhs < n)
	{
		sum += nums[rhs];
		while (sum >= s)
		{
			minLen = min(minLen, rhs - lhs + 1);
			sum -= nums[lhs++];
		}
		rhs++;
	}
	return minLen == INT_MAX ? 0 : minLen;
}