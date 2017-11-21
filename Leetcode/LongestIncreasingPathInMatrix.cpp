/******************************************************************************/
/*
* Question: #329 Longest Increasing Path In a Matrix
* Given an integer matrix, find the length of the longest increasing path.
* From each cell, you can either move to four directions: left, right, up or down. 
* You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1: 
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2: 
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// memDFS to find largest steps in each cell
int calcMaxLen(vector<vector<int>> & matrix, int i, int j, vector<vector<int>> & dp);

// we calculate each point and memorize the value
int longestIncreasingPath(vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	int row = matrix.size(), col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col, 1));
	int globalMax = 0;
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			int currMax = 0;
			// calculate the max number of steps from (i, j)
			int len = calcMaxLen(matrix, i, j, dp);
			globalMax = max(globalMax, len);
		}
	}
	return globalMax;
}

int calcMaxLen(vector<vector<int>> & matrix, int i, int j, vector<vector<int>> & dp)
{
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int localMax = 0, len = 0;
	for (int k = 0; k<4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j])
		{
			if (dp[x][y] != 1)
			{
				len = dp[x][y] + 1;
			}
			else
			{
				len = calcMaxLen(matrix, x, y, dp) + 1;
			}
		}
		else len = 1;
		localMax = max(localMax, len);
	}
	// memorization !!!!
	dp[i][j] = localMax;
	return localMax;
}