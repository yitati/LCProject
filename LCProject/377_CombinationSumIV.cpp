/******************************************************************************/
/*
* Question: #377 Combination Sum IV
* Given an integer array with all positive numbers and no duplicates, 
* find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

* Note that different sequences are counted as different combinations.

* Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
*/
/*****************************************************************************/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp solution - samilar to fibonacci
int combinationSum4(vector<int>& nums, int target)
{
	vector<int> dp(target + 1);
	dp[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		for (int j = 0; j<nums.size(); j++)
		{
			if (i - nums[j] >= 0)
			{
				dp[i] += dp[i - nums[j]];
			}
		}
	}
	return dp[target];
}


// dfs solution - time limit exceed
void combSum_dfs4(int & count, vector<int> & result, vector<int> & nums, int target)
{
	if (target < 0) return;
	if (target == 0)
	{
		count++;
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(nums[i]);
		combSum_dfs4(count, result, nums, target - nums[i]);
		result.pop_back();
	}
}

int combinationSum_4_NotWorking(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	vector<int> result;
	int count = 0;
	combSum_dfs4(count, result, nums, target);
	return count;
}