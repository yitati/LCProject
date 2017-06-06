/******************************************************************************/
/*
* Question: #407 Trapping Rain Water
* Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, 
* compute the volume of water it is able to trap after raining. 

* Note:
* Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000. 

Example: 
Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.

*/
/*****************************************************************************/

/*
The amount of rain water one point can trap is determined by the min value of its surrounding.
Similar to trapping rain water I, we need to first target the min value of its boundaries and 
then calculate the rain it trap.
But the boundaries of a 2D histogram can be simply lmax and rmax, but for 3D matrix, we need to 
keep track of all point that lays in the boundaries (first row, first col, last row, last col).
*/

#include <queue>

using namespace std;

// we create a class to store the triplet row, col and height

class Cell
{
public:
	Cell(int r, int c, int h) : row(r), col(c), height(h) {};
	bool operator<(const Cell& other) const
	{
		return this->height > other.height;
	}
	int row;
	int col;
	int height;
};

priority_queue<Cell> minHeap;

int trapRainWater(vector<vector<int>>& heightMap)
{
	if (heightMap.empty() || heightMap[0].empty()) return 0;
	int row = heightMap.size(), col = heightMap[0].size();
	int sum = 0, maxHeight = 0;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	// push the first and last row
	for (int j = 0; j<col; j++)
	{
		Cell cell1(0, j, heightMap[0][j]);
		Cell cell2(row - 1, j, heightMap[row - 1][j]);
		minHeap.push(cell1);
		minHeap.push(cell2);
		visited[0][j] = true;
		visited[row - 1][j] = true;
	}
	// push the first and last col
	for (int i = 1; i<row - 1; i++)
	{
		Cell cell1(i, 0, heightMap[i][0]);
		Cell cell2(i, col - 1, heightMap[i][col - 1]);
		minHeap.push(cell1);
		minHeap.push(cell2);
		visited[i][0] = true;
		visited[i][col - 1] = true;
	}
	// start checking the min values
	while (!minHeap.empty())
	{
		Cell curr = minHeap.top();
		minHeap.pop();
		maxHeight = max(maxHeight, curr.height);
		sum += max(0, maxHeight - curr.height);
		for (int k = 0; k<4; k++)
		{
			int x = curr.row + dx[k];
			int y = curr.col + dy[k];
			if (x >= 0 && x < row && y >= 0 && y < col && !visited[x][y])
			{
				Cell cell(x, y, heightMap[x][y]);
				visited[x][y] = true;
				minHeap.push(cell);
			}
		}
	}
	return sum;
}

