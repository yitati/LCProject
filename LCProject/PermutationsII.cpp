/******************************************************************************
* Question: #47 Permutations II
* company tag: Facebook, LinkedIn
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]
*****************************************************************************/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;

void permuteUnique_recursion(vector<int> & nums, vector<vector<int>> & results, int level)
{
	if (level == nums.size())
	{
		results.push_back(nums);
		return;
	}
	unordered_set<int> visited;
	for (int i = level; i < nums.size(); i++)
	{
		if (visited.count(nums[i])) continue;
		visited.insert(nums[i]);
		swap(nums[level], nums[i]);
		permuteUnique_recursion(nums, results, level + 1);
		swap(nums[level], nums[i]);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
	vector<vector<int>> results;
	if (nums.empty()) return results;
	permuteUnique_recursion(nums, results, 0);
	return results;
}

/*
int main(int argc, char ** argv)
{
	int input[] = { 1, 2, 1 };
	vector<int> nums(input, input + sizeof(input) / sizeof(int));
	vector<vector<int>> results = permuteUnique(nums);
	for (int i = 0; i < results.size(); i++)
	{
		for (int j = 0; j < results[i].size(); j++)
		{
			cout << results[i][j] << "   ";
		}
		cout << endl;
	}

	system("pause");
}
*/
