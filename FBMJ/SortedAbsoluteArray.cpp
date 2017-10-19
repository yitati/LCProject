/*
 * SortedAbsoluteArray.cpp
给一个有正有负的递增数列，返回一个按绝对值大小排列的数列

since the original array is ordered, so we want to find the number that is closest to 0, and use two pointers to
get the array ordered with absolute values
 */

#include <vector>
#include <climits>

using namespace std;

int findClosestTo0(vector<int>& nums)
{
	int lhs = 0, rhs = nums.size()-1, closest = INT_MAX, res = -1;
	while(lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs)/2;
		if(nums[mid] == 0) return mid;
		else
		{
			int diff = abs(nums[mid]);
			if(diff < closest)
			{
				closest = diff;
				res = mid;
			}
			if(nums[mid] > 0) rhs = mid-1;
			else lhs = mid+1;
		}
	}
	return res;
}

vector<int> getAbsSorted(vector<int> nums)
{
	int start = findClosestTo0(nums);
	int i = start-1, j = start+1;
	vector<int> absolute;
	absolute.push_back(nums[start]);
	while(i >=0 || j < nums.size())
	{
		if(i < 0) absolute.push_back(nums[j++]);
		else if(j >= nums.size()) absolute.push_back(nums[i--]);
		else
		{
			if(abs(nums[i]) < abs(nums[j]))
			{
				absolute.push_back(nums[i--]);   // if we need to push absolute value, then need to add abs to nums[i--]
			}
			else absolute.push_back(nums[j++]);
		}
	}

	return absolute;
}




