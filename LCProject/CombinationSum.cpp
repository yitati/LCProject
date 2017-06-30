/******************************************************************************/
/*
* Question: #39 Combination Sum
* Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
* find all unique combinations in C where the candidate numbers sums to T.
* The same repeated number may be chosen from C unlimited number of times.
* Note:
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]

*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void combSum_dfs(vector<vector<int>> & results, vector<int> & result, vector<int> & nums, int level, int sum, int target)
{
	if (sum > target) return;
	if (sum == target)
	{
		results.push_back(result);
		return;
	}
	for (int i = level; i<nums.size(); i++)
	{
		result.push_back(nums[i]);
		combSum_dfs(results, result, nums, i, sum + nums[i], target);
		result.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> results;
	vector<int> result;
	combSum_dfs(results, result, candidates, 0, 0, target);
	return results;
}