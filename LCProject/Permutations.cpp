/******************************************************************************
* Question: #46 Permutations
* company tag: LinkedIn
* Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*****************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

void permute_recursion(vector<int> & nums, vector<vector<int>> & results, int level)
{
	if (level == nums.size())
	{
		results.push_back(nums);
		return;
	}
	for (int i = level; i < nums.size(); i++)
	{
		swap(nums[level], nums[i]);
		permute_recursion(nums, results, level + 1);
		swap(nums[level], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) 
{
	vector<vector<int>> results;
	if (nums.empty()) return results;
	permute_recursion(nums, results, 0);
	return results;
}

/*
int main(int argc, char ** argv)
{
	int input[] = { 1, 2, 3 };
	vector<int> nums(input, input + sizeof(input) / sizeof(int));
	vector<vector<int>> results = permute(nums);
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
