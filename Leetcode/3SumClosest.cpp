/******************************************************************************/
/*
* Question: #16 3 Sum Closest
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
* Return the sum of the three integers. You may assume that each input would have exactly one solution.

* For example, given array S = {-1 2 1 -4}, and target = 1.

* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) 
{
	int n = nums.size();
	if (n < 3) return{};
	int globalSum = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int index = 0; index < n - 2; index++)
	{
		if (index > 0 && nums[index - 1] == nums[index]) continue;
		int i = index + 1, j = n - 1;
		while (i < j)
		{
			int sum = nums[i] + nums[j] + nums[index];
			if (sum == target)
			{
				return target;
			}
			else if (sum < target) i++;
			else j--;
			globalSum = abs(globalSum - target) > abs(sum - target) ? sum : globalSum;
		}
	}
	return globalSum;
}
