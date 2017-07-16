/******************************************************************************/
/*
* Question: #40 Combination Sum II
* company tag: Facebook
* Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C 
* where the candidate numbers sums to T.

* Each number in C may only be used once in the combination.

* Note:
* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combSum_dfs2(vector<vector<int>> & results, vector<int> & result, vector<int> & nums, int level, int sum, int target)
{
	if (sum > target) return;
	if (sum == target)
	{
		results.push_back(result);
		return;
	}
	for (int i = level; i < nums.size(); i++)
	{
		if (i > level && nums[i] == nums[i - 1]) continue;
		result.push_back(nums[i]);
		combSum_dfs2(results, result, nums, i + 1, sum + nums[i], target);
		result.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> results;
	vector<int> result;
	combSum_dfs2(results, result, candidates, 0, 0, target);
	return results;
}
