/******************************************************************************
* Question: #15 3 Sum
* company tag: Facebook
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* Note: The solution set must not contain duplicate triplets.

* For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]

Follow-up:
company tag: Facebook
with duplicate ?
TODO
*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// O(n^2) solution
// TODO - know this approach https://arxiv.org/abs/1404.0799
vector<vector<int>> threeSum(vector<int>& nums) 
{
	int n = nums.size();
	if (n < 3) return{};
	vector<vector<int>> results;
	sort(nums.begin(), nums.end());
	for (int index = 0; index < n - 2; index++)
	{
		if (index > 0 && nums[index] == nums[index - 1]) continue;
		int target = 0 - nums[index];
		int i = index + 1, j = n - 1;
		while (i < j)
		{
			if (nums[i] + nums[j] == target)
			{
				vector<int> result(3);
				result[0] = nums[index];
				result[1] = nums[i];
				result[2] = nums[j];
				results.push_back(result);
				i++;
				j--;
				while (i<j && nums[i] == nums[i - 1]) i++;
				while (i<j && nums[j] == nums[j + 1]) j--;
			}
			else if (nums[i] + nums[j] < target) i++;
			else j--;
		}
	}
	return results;
}

