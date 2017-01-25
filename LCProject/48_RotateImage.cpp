/******************************************************************************/
/*
* Question: #48 Rotate Image
* You are given an n x n 2D matrix representing an image.

* Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/
/*****************************************************************************/

#include <vector>
#include <iostream>

using namespace std;


void rotate(vector<vector<int>>& matrix) 
{
	int n = matrix.size();
	for (int layer = 0; layer < n / 2; layer++)
	{
		int begin = layer;
		int end = n - 1 - layer;
		int len = n - 2 * layer;
		// BE VERY CAREFUL WITH THIS LEN-1
		for (int i = 0; i < len - 1; i++)
		{
			// store the right
			int right = matrix[begin + i][end];
			// put top to the right
			matrix[begin + i][end] = matrix[begin][begin + i];
			// put left to top
			matrix[begin][begin + i] = matrix[end - i][begin];
			// put bottom to left
			matrix[end - i][begin] = matrix[end][end - i];
			// put right to bottom
			matrix[end][end - i] = right;
		}
	}
}