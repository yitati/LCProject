/*
 * NumberOfIsland.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: JoanneY1
 */

#include <vector>

using namespace std;

// in dfs, change each searched land to 2
void numIslands_dfs(vector<vector<char>> & grid, int r, int c)
{
	grid[r][c] = '2';
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	for (int k = 0; k < 4; k++)
	{
		int x = r + dx[k];
		int y = c + dy[k];
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
		{
			if (grid[x][y] == '1') numIslands_dfs(grid, x, y);
		}
	}
}

int numIslands(vector<vector<char>>& grid)
{
	int count = 0;
	if (grid.size() == 0 || grid[0].size() == 0) return count;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == '1')
			{
				numIslands_dfs(grid, i, j);
				count++;
			}
		}
	}
	return count;
}

