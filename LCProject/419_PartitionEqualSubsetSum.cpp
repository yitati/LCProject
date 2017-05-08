/******************************************************************************/
/*
* Question: #419 Partition Equal Subset Sum
* Given a non-empty array containing only positive integers, find if the array can be partitioned into 
* two subsets such that the sum of elements in both subsets is equal.

* Note:
* 1.Each of the array element will not exceed 100.
* 2.The array size will not exceed 200.

Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: [1, 2, 3, 5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
*/
/*****************************************************************************/

#include <vector>
using namespace std;

// LC 494
// combination sum of sum/2
int subsetSum(vector<int> & nums, int target)
{
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int num : nums)
	{
		for (int x = target; x >= num; x--)
		{
			dp[x] += dp[x - num];
		}
	}
	return dp[target];
}

bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int num : nums) sum += num;
	if (sum % 2 != 0) return false;
	int result = subsetSum(nums, sum / 2);
	return result == 0 ? false : true;
}