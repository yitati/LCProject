/******************************************************************************/
/**
* Question: #200 Number of Islands
* Given a 2d grid map of '1's(land) and '0's(water), count the number of islands. An
* island is surrounded by water and is formed by connecting adjacent lands horizontally
* or vertically. You may assume all four edges of the grid are all surrounded by water.
*
*
/*****************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

class NumIslands {
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		int i, j;
		int count = 0;

		int n = grid.size();
		int m = grid[0].size();
		if (n == 0 || m == 0) return 0;

		for (i=0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (grid[i][j] == '1')
				{
					dfs_check(grid, i, j);
					count++;
				}
			}

		}
		return count;
	}

	// depth first search, when there is one land, change the mark and search surrounding
	void dfs_check(vector<vector<char>> & grid, int i, int j)
	{
		// mark visited to 2
		grid[i][j] = '2';

		int n = grid.size();
		int m = grid[0].size();

		if (i > 0 && grid[i - 1][j] == '1') dfs_check(grid, i - 1, j);
		if (i < n - 1 && grid[i + 1][j] == '1') dfs_check(grid, i + 1, j);
		if (j > 0 && grid[i][j-1] == '1') dfs_check(grid, i, j - 1);
		if (j < m - 1 && grid[i][j + 1] == '1') dfs_check(grid, i, j + 1);
	}
};

/*
int main(int argc, char * argv[])
{
	cout << "Main starts" << endl;
	NumIslands island;
	vector<vector<char>> grid1 = { {'1', '1', '1', '1', '0'} , { '1', '1', '0', '1', '0' } , { '1', '1', '0', '0', '0' } , { '0', '0', '0', '0', '0' } };
	cout << "grid 1 is ok" << endl;
	vector<vector<char>> grid2 = { {'1', '1', '0', '0', '0'} , { '1', '1', '0', '0', '0' } , { '0', '0', '1', '0', '0' } , { '0', '0', '0', '1', '1' } };
	cout << "grid 2 is ok" << endl;
	cout << island.numIslands(grid1) << endl;
	cout << island.numIslands(grid2) << endl;
	system("pause");

}
*/