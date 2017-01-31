/******************************************************************************/
/*
* Question: #90 Subsets II
* Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]

*/
/*****************************************************************************/

#include <vector>

using namespace std;

// back tracking using K tree
void subsetWithDup_dfs(vector<vector<int>> & results, vector<int > & result, int level, vector<int> & nums)
{
	if (level == nums.size())
	{
		return;
	}
	for (int i = level; i < nums.size(); i++)
	{
		if (i>level && nums[i] == nums[i - 1]) continue;
		result.push_back(nums[i]);
		results.push_back(result);
		subsetWithDup_dfs(results, result, i + 1, nums);
		result.pop_back();
	}

}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> results;
	vector<int> result;
	results.push_back({});
	subsetWithDup_dfs(results, result, 0, nums);
	return results;
}