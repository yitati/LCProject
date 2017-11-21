/******************************************************************************
* Question: #219 Contains Duplicate II
* Given an array of integers and an integer k, find out whether there are two distinct 
* indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
 *****************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
	unordered_map<int, vector<int>> table;
	for (int i = 0; i < nums.size(); i++)
	{
		table[nums[i]].push_back(i);
	}
	for (auto it = table.begin(); it != table.end(); it++)
	{
		if (it->second.size() == 1) continue;
		for(int i = 1; i < it->second.size(); i++)
		{
			if (it->second[i] - it->second[i - 1] <= k) return true;
		}
	}

	return false;

}
