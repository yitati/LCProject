/******************************************************************************
* Question: #78 Subsets
* company tag: Facebook
* Given a set of distinct integers, nums, return all possible subsets.
* Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

*****************************************************************************/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;
// TODO - do the problem and time complexity

// solution 1: back tracking
void subset_dfs(vector<vector<int>> & results, vector<int> & result, int level, vector<int> & nums)
{
	if (level == nums.size())
	{
		results.push_back(result);
		return;
	}
	// 1 - we do not push in nums[i]
	subset_dfs(results, result, level + 1, nums);
	// 2 - we push nums[i]
	result.push_back(nums[level]);
	subset_dfs(results, result, level + 1, nums);
	result.pop_back();
}

vector<vector<int>> subsets1(vector<int>& nums)
{
	vector<vector<int>> results;
	vector<int> result;
	subset_dfs(results, result, 0, nums);
	return results;

}

// solution 2: bit manipulation
vector<vector<int>> subsets2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	int n = pow(2, nums.size());
	vector<vector<int>> results(n, vector<int>());
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((j >> i) & 1) results[j].push_back(nums[i]);
		}
	}
	return results;

}

