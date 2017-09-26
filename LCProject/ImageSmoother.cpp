/******************************************************************************
* Question: #661 Image Smoother
* Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother
* to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8
* surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0

 * Note:
 * The value in the given matrix is in the range of [0, 255].
 * The length and width of the given matrix are in the range of [1, 150].
*****************************************************************************/

#include <vector>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
	// since the value in the given matrix is in range [0, 255] so 8 bits will be enough to hold it
	if (M.empty() || M[0].empty())
		return M;
	int row = M.size(), col = M[0].size();
	int dir[9][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 },
			          { 0, -1 }, { 0, 0 }, { 0, 1 },
					  { 1, -1 }, { 1, 0 }, { 1, 1 } };

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int sum = 0, count = 0;
			for (int k = 0; k < 9; k++) {
				int x = i + dir[k][0];
				int y = j + dir[k][1];
				if (x < 0 || x >= row || y < 0 || y >= col)
					continue;
				sum += (M[x][y] & 0xFF); // lowest 8 bit
				count++;
			}
			int avg = sum / count;
			M[i][j] |= (avg << 8);
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			M[i][j] >>= 8;
		}
	}

	return M;
}

