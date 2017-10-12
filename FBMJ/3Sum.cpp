/*
 * 3Sum.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <algorithm>

using namespace std;

/*
 * 3SUM，不能sort。刚开始用brute force做了个n^3的。
 * 后来在小哥的提示下，先把数组转换成set，然后最后一遍扫的时候直接看在不在set里。这样降到n^2
 * TODO with BAOBAO
 */

// normal 3 sum, sort and calculate
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
