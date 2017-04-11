/******************************************************************************/
/*
* Question: #300 Longest Increasing Subsequence
* Given an unsorted array of integers, find the length of longest increasing subsequence. 

* For example,
* Given [10, 9, 2, 5, 3, 7, 101, 18],
* The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
* Note that there may be more than one LIS combination, it is only necessary for you to return the length. 

* Your algorithm should run in O(n2) complexity. 
* Follow up: Could you improve it to O(n log n) time complexity? 
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;
// O(n^2) solution
int lengthOfLIS(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int len = nums.size(), maxLen = 1;
	vector<int> dp(len, 1);
	for (int i = 1; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
		}
		maxLen = max(maxLen, dp[i]);
	}

	return maxLen;
}

// O(nlogn) solution
int lengthOfLIS_binarySearch(vector<int> & nums)
{
	vector<int> table;
	for (int i = 0; i < nums.size(); i++)
	{
		auto it = lower_bound(table.begin(), table.end(), nums[i]);
		if (it == table.end()) table.push_back(nums[i]);
		*it = nums[i];
	}

	return table.size();
}