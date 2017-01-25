/******************************************************************************/
/*
* Question: #59 Spiral MatrixII
* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

*/
/*****************************************************************************/

#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
	if (n == 0) return {};
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int left = 0, right = n-1;
	int top = 0, bottom = n-1;
	int i;
	int count = 1;

	while (count <= n*n)
	{
		for (i = left; i <= right; i++, count++) matrix[top][i] = count;
		top++;

		for (i = top; i <= bottom; i++, count++) matrix[i][right] = count;
		right--;

		for (i = right; i >= left; i--, count++) matrix[bottom][i]= count;
		bottom--;

		for (i = bottom; i >= top; i--, count++) matrix[i][left] = count;
		left++;
	}
	return matrix;
}