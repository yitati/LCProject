/******************************************************************************/
/*
* Question: #63 Unique Path II
* Follow up for "Unique Paths":

* Now consider if some obstacles are added to the grids. How many unique paths would there be?

* An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
	int n = obstacleGrid.size();
	int m = obstacleGrid[0].size();
	if (m == 0 || n == 0) return 0;
	if (obstacleGrid[0][0] == 1) return 0;
 	vector<vector<int>> step(n, vector<int>(m, 1));
	for (int i = 0; i < n; i++)
	{
		if (obstacleGrid[i][0] == 1) step[i][0] = 0;
	}
	for (int j = 0; j < m; j++)
	{
		if (obstacleGrid[0][j] == 1) step[0][j] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (obstacleGrid[i][j] == 1) step[i][j] = 0;
			else
			{
				step[i][j] = step[i][j - 1] + step[i - 1][j];
			}
		}
	}
	return step[n - 1][m - 1];
}