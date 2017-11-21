/******************************************************************************
* Question: #368 Largest Divisible Subsets
* Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of 
* elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0. 

* If there are multiple solutions, return any subset is fine. 

Example 1: 
nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)



Example 2: 
nums: [1,2,4,8]

Result: [1,2,4,8]

*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) 
{
	if (nums.empty()) return{};
	sort(nums.begin(), nums.end());
	vector<vector<int>> dp(nums.size());
	int maxLen=0, maxIndex = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		dp[i].push_back(nums[i]);
		for (int j = 0; j < i; j++)
		{
			if (nums[i] % nums[j] == 0)
			{
				if (dp[j].size() + 1 > dp[i].size())
				{
					dp[i] = dp[j];
					dp[i].push_back(nums[i]);
				}
			}
		}
		if (dp[i].size() > maxLen)
		{
			maxLen = dp[i].size();
			maxIndex = i;
		}
	}

	return dp[maxIndex];
}
