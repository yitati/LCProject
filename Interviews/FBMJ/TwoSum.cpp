/******************************************************************************
* Question: #1 Two Sum
* company tag: Amazon, LinkedIn
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.

* Example:
* Given nums = [2, 7, 11, 15], target = 9,
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
* UPDATE (2016/2/13):
* The return format had been changed to zero-based indices. Please read the above updated description carefully.
*****************************************************************************/

#include <unordered_map>
#include <vector>

using namespace std;

// build the map ON THE FLY !!
// be careful with case [0, 3, 4, 0] target = 0 case !
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result(2);
	unordered_map<int, int> table;
	unsigned int i;
	for (i = 0; i < nums.size(); i++)
	{
		if (table.find(target - nums[i]) != table.end())
		{
			result[1] = i;
			result[0] = table[target - nums[i]];
		}
		else
		{
			table[nums[i]] = i;
		}
	}
	return result;
}
