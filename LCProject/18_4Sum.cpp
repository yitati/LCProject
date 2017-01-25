/******************************************************************************/
/*
* Question: #18 4 Sum
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
* Find all unique quadruplets in the array which gives the sum of target.

* Note: The solution set must not contain duplicate quadruplets.

* For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> fourSum(vector<int>& nums, int target) 
{
	if (nums.size() < 4) return{};
	vector<vector<int>> results;
	sort(nums.begin(), nums.end());
	for (int i = 0; i<nums.size() - 3; i++)
	{
		//if(nums[i] * 4 > target) break;
		int target1 = target - nums[i];
		for (int j = i + 1; j<nums.size() - 2; j++)
		{
			//if(nums[j] * 3 > target1) break;
			int target2 = target1 - nums[j];
			int lhs = j + 1;
			int rhs = nums.size() - 1;
			while (lhs < rhs)
			{
				int sum = nums[lhs] + nums[rhs];
				if (sum == target2)
				{
					vector<int> result(4);
					result[0] = nums[i];
					result[1] = nums[j];
					result[2] = nums[lhs];
					result[3] = nums[rhs];
					while (lhs + 1 < nums.size() && nums[lhs] == result[2]) lhs++;
					while (rhs - 1 >= 0 && nums[rhs] == result[3]) rhs--;
					results.push_back(result);
				}
				else if (sum < target2) lhs++;
				else rhs--;
			}
			while (j<nums.size() - 1 && nums[j + 1] == nums[j]) j++;
		}
		while (i<nums.size() - 1 && nums[i + 1] == nums[i]) i++;
	}
	return results;



}