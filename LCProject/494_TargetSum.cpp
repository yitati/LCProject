/******************************************************************************/
/*
* Question: #494 Target Sum
* You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
* Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
* Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

* Note:
* 1.The length of the given array is positive and will not exceed 20.
* 2.The sum of elements in the given array will not exceed 1000.
* 3.Your output answer is guaranteed to be fitted in a 32-bit integer.
*/
/*****************************************************************************/
#include <vector>
using namespace std;

// using the dfs solution it is very slow
// using dp idea : first we denote sp to be sum of all positive numbsers 
// and sn to be sum of all negative numbers, then sp - sn = target
// add (sp + sn) at both sides we got sp = (taget + SUM)/2
// so if we get SUM we turn the problem to find subset sum in a vector
// Same with LC 419

int subSum(vector<int> & nums, int target)
{
	vector<int> dp(target + 1, 0);
	dp[0] = 1;
	for (int num : nums)
	{
		for (int i = target; i >= num; i--)
		{
			dp[i] += dp[i - num];
		}
	}
	return dp[target];
}

int findTargetSumWays(vector<int>& nums, int S)
{
	int sum = 0;
	for (int num : nums) sum += num;
	if (sum < S) return 0;
	if ((S + sum) % 2 != 0) return 0;
	return subSum(nums, (S + sum) / 2);
}


