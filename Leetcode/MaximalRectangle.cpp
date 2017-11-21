/******************************************************************************
* Question: #84 Largest Rectangle In Histogram
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's 
* and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// be familiar with 84 largest rectangle in histogram

int largestRectangleInHistogram(vector<int>& heights)
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

int maximalRectangle(vector<vector<char>>& matrix)
{
	int maxArea = 0;
	int row = matrix.size();
	if (row == 0) return 0;
	int col = matrix[0].size();
	if (col == 0) return 0;
	vector<int> histogram(col, 0);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == '0') histogram[j] = 0;
			else histogram[j] += 1;
		}

		int tmp = largestRectangleInHistogram(histogram);
		maxArea = max(maxArea, tmp);
	}
	return maxArea;
}
