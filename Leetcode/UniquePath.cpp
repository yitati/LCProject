/******************************************************************************/
/*
* Question: #62 Unique Path
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

* The robot can only move either down or right at any point in time. 
* The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
Note: m and n will be at most 100.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int uniquePaths(int m, int n) 
{
	if (m == 0 || n == 0) return 0;
	vector<vector<int>> step(n, vector<int>(m, 1));
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			step[i][j] = step[i][j - 1] + step[i - 1][j];
		}
	}
	return step[n - 1][m - 1];

}