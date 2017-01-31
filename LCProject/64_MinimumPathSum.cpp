/******************************************************************************/
/*
* Question: #64 Minimum Path Sum
* Given a m x n grid filled with non-negative numbers, 
* find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
	int n = grid.size(), m = grid[0].size();
	if (m == 0 || n == 0) return 0;
	vector<vector<int>> result(n, vector<int>(m, 0));
	result[0][0] = grid[0][0];
	for (int i = 1; i < n; i++)
	{
		result[i][0] += result[i - 1][0] + grid[i][0];
	}
	for (int j = 1; j < m; j++)
	{
		result[0][j] += result[0][j - 1] + grid[0][j];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			result[i][j] += min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
		}
	}
	return result[n - 1][m - 1];
}