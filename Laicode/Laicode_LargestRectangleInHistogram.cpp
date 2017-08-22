/*
 * Laicode_LargestRectangleInHistogram.cpp
 *

Given a non-negative integer array representing the heights of a list of adjacent bars.
Suppose each bar has a width of 1. Find the largest rectangular area that can be formed in the histogram.

Assumptions

The given array is not null or empty
Examples

{ 2, 1, 3, 3, 4 }, the largest rectangle area is 3 * 3 = 9(starting from index 2 and ending at index 4)

 */

#include <vector>
#include <stack>

using namespace std;

// LC 84 Largest Rectangle In Histogram
int largestRecInHistogram(vector<int> array)
{
	stack<int> indexStack;
	int maxArea = 0;

	for(int i=0; i <= array.size(); i++)
	{
		int currH = (i == array.size()) ? 0 : array[i];

		if(indexStack.empty() || currH >= array[indexStack.top()])
		{
			indexStack.push(i);
		}
		else
		{
			int topH = array[indexStack.top()];
			indexStack.pop();
			int lhs = indexStack.empty() ? -1 : indexStack.top();
			int rhs = i;
			int currRec = topH*(rhs-lhs-1);
			maxArea = max(maxArea, currRec);
			i--;
		}
	}
	return maxArea;
}



