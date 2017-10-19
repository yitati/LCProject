/******************************************************************************
* Question: #200 Number Of Islands
* company tag: Amazon, Facebook
* Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
* An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
* You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000

Answer: 1

Example 2:
11000
11000
00100
00011

Answer: 3
 * follow-up: print out the set of all island (with their coordinates)
 * company tag: eBay

*****************************************************************************/

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
