/******************************************************************************/
/**
* Question: #229 Majority Element II
* Given an integer array of size n, find all elements that appear more than n/3 times. The algorithm
* should run in linear time and in O(1) space.
*
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// there are at most two majority elements
vector<int> majorityElementII(vector<int>& nums)
{
	vector<int> champions;
	if (nums.size() == 0) return champions;
	int champion1 = nums[0], champion2 = nums[0];
	int count1 = 0, count2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != champion1 && nums[i] != champion2)
		{
			if (count1 == 0) { champion1 = nums[i]; count1++; }
			if (count2 == 0) { champion2 = nums[i]; count2++; }
			else { count1--; count2--; }
		}
		if (nums[i] == champion1) { count1++; continue; }
		if (nums[i] == champion2) { count2++; continue; }
	}

	count1 = 0;
	count2 = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == champion1) count1++;
		if (nums[i] == champion2) count2++;
	}

	if (count1 > nums.size() / 3) champions.push_back(champion1);
	if (count2 > nums.size() / 3) champions.push_back(champion2);

	return champions;
}