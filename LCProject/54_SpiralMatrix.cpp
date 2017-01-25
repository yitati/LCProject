/******************************************************************************/
/*
* Question: #54 Spiral Matrix
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/
/*****************************************************************************/

#include <vector>
#include <iostream>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> result;
	if (matrix.size() == 0 || matrix[0].size() == 0) return result;

	int left = 0, right = matrix[0].size() - 1;
	int top = 0, bottom = matrix.size() - 1;
	int i;

	while (left <= right && top <= bottom)
	{
		for (i = left; i <= right; i++)result.push_back(matrix[top][i]);
		top++;
		if (top > bottom) break;

		for (i = top; i <= bottom; i++)result.push_back(matrix[i][right]);
		right--;
		if (right < left) break;

		for (i = right; i >= left; i--)result.push_back(matrix[bottom][i]);
		bottom--;
		if (bottom < top) break;

		for (i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
		left++;
		if (left > right) break;
	}
	return result;
}