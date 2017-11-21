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
	int top = 0, bottom = n-1, left = 0, right = n-1;
	int idx = 0;
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	while(idx < n*n)
	{
		// fill top
		for(int j=left; j<=right; j++, idx++) matrix[top][j] = idx+1;
		top++;
		if(top > bottom) break;
		// fill right
		for(int i=top; i<=bottom; i++, idx++) matrix[i][right] = idx+1;
		right--;
		if(right < left) break;
		// fill bottom
		for(int j=right; j >= left; j--, idx++) matrix[bottom][j] = idx+1;
		bottom--;
		if(bottom < top) break;
		// fill left
		for(int i=bottom; i >= top; i--, idx++) matrix[i][left] = idx+1;
		left++;
		if(left > right) break;
	}
	return matrix;
}
