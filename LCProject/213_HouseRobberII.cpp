/******************************************************************************/
/*
* Question: #213 House Robber
* Note: This is an extension of House Robber.
* After robbing those houses on that street, the thief has found himself a new place for his thievery 
* so that he will not get too much attention. 
* This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
* Meanwhile, the security system for these houses remain the same as for those in the previous street.
* Given a list of non-negative integers representing the amount of money of each house, 
* determine the maximum amount of money you can rob tonight without alerting the police.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int robII(vector<int>& nums)
{
	int len = nums.size();
	if (len == 0) return 0;
	int maxSum = 0;
	vector<int> dp(len, 0);
	// if we rob the first house
	dp[0] = nums[0];
	dp[1] = nums[0];
	for (int i = 2; i < len; i++)
	{
		if (i == len - 1) dp[i] = dp[i - 1];
		else dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	maxSum = dp[len - 1];
	// if we do not rob the first house
	dp[0] = 0;
	dp[1] = nums[1];
	for (int i = 2; i < len; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	maxSum = max(maxSum, dp[len - 1]);

	return maxSum;
}

// another solution - same idea
int robII_helpser(vector<int> & nums, int start, int end)
{
	int pn_2 = 0, pn_1 = 0;
	for (int i = start; i <= end; i++)
	{
		int tmp = max(pn_1, pn_2 + nums[i]);
		pn_2 = pn_1;
		pn_1 = tmp;
	}
	return pn_1;
}

int robII_spaceSaver(vector<int> nums)
{
	int len = nums.size();
	if (len == 0) return 0;
	if (len == 1) return nums[0];
	return max(robII_helpser(nums, 0, len - 2), robII_helpser(nums, 1, len - 1));
}