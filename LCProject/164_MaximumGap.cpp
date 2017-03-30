/******************************************************************************/
/*
* Question: #164 Maximum Gap
* Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
* Try to solve it in linear time/space.
* Return 0 if the array contains less than 2 elements.
* You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int> & nums)
{
	sort(nums.begin(), nums.end());
	int maxDiff = INT_MIN;
	for (int i = 0; i < nums.size(); i++)
	{
		if(i>0) maxDiff = max(maxDiff, nums[i] - nums[i - 1]);
	}
	return maxDiff;
}
