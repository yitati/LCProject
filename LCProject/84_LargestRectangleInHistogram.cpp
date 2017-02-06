/******************************************************************************/
/**
* Question: #84 Largest Rectangle In Histogram
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
* find the area of largest rectangle in the histogram.
*
*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// to find the largest rectangle we need to find corresponding height and weight.
// the idea is to find a range (lhs, rhs) so that width = (rhs-1)-(lhs+1)+1 = rhs-lhs-1
// normally we can use O(n^2) time to find the lhs and rhs, but by using stack we can get O(n) solution
int largestRectangleArea(vector<int>& heights) 
{
	// create a stack to put index with acending order of height
	vector<int> indStack;
	int maxArea = 0;
	for (int i = 0; i <= heights.size(); i++)
	{
		int heightToCalc = i == heights.size() ? 0 : heights[i];
		if (indStack.empty() || heights[indStack.back()] <= heightToCalc)
		{
			indStack.push_back(i);
		}
		else
		{
			int height = heights[indStack.back()];
			indStack.pop_back();
			int lhs = indStack.empty() ? -1 : indStack.back();
			int rhs = i;
			maxArea = max(maxArea, height*(rhs - lhs - 1));
			i--;
		}

	}

	return maxArea;
}