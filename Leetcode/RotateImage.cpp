/******************************************************************************
* Question: #48 Rotate Image
* company tag: Amazon
* You are given an n x n 2D matrix representing an image.

* Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

 *****************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

void rotateImage(vector<vector<int>> & matrix)
{
	int n = matrix.size();
	for(int layer = 0; layer < n/2; layer++)
	{
		int start = layer, end = n - 1 - layer, len = end - start + 1;
		for(int i = 0; i < len-1; i++)
		{
			// save the right
			int right = matrix[start+i][end];
			// move top to right
			matrix[start+i][end] = matrix[start][start + i];
			// move left to top
			matrix[start][start+i] = matrix[end-i][start];
			// move bottom to left
			matrix[end-i][start] = matrix[end][end-i];
			// move right to bottom
			matrix[end][end-i] = right;
		}
	}
}
