/******************************************************************************/
/*
* Question: #11 Container With Most Water
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
* which together with x-axis forms a container, such that the container contains the most water.

* Note: You may not slant the container and n is at least 2.
*/
/*****************************************************************************/
#include <vector>
#include <algorithm>

using namespace std;

// if these 2 values are i and j then we have  maxArea = (j-i) * min(nums[i], nums[j])
// this needs O(n^2) complexity
int maxArea1(vector<int>& height) {
	int maxArea = 0;
	int localMax = 0;
	int i, j;
	for (i = 0; i < height.size()-1; i++)
	{
		for (j = i + 1; j < height.size(); j++)
		{
			localMax = max(localMax, (j - i)*min(height[i], height[j]));
		}
		maxArea = max(maxArea, localMax);
	}
	return maxArea;
}

// another idea - set lhs to be 0 and rhs to be end
// each time try to move the shorter one and try to find the Max value
int maxArea2(vector<int>& height)
{
	int lhs = 0, rhs = height.size() - 1;
	int water = 0;
	while (lhs < rhs)
	{
		water = max(water, (rhs - lhs) * min(height[lhs], height[rhs]));
		if (height[lhs] < height[rhs]) lhs++;
		else rhs--;
	}
	return water;
}