/*
* Question: #361 Bomb Enemy
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), 
return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits 
the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)
*/

#include <vector>
#include <algorithm>

using namespace std;

// straight forward dp solution
// first scan from top-left to bottom-right
// second scan from bottom-right to top-bottom
int maxKilledEnemies(vector<vector<char>>& grid)
{
	if (grid.empty() || grid[0].empty()) return 0;
	int row = grid.size(), col = grid[0].size();

	vector<vector<int>> lookrow(row, vector<int>(col, 0));
	vector<vector<int>> lookcol(row, vector<int>(col, 0));
	vector<vector<int>> sum(row, vector<int>(col, 0));
	int maxKill = 0;

	// first scan from top left to bottom right
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if (grid[i][j] == 'W') continue;
			lookrow[i][j] = (i == 0 ? 0 : lookrow[i - 1][j]) + (grid[i][j] == 'E' ? 1 : 0);
			lookcol[i][j] = (j == 0 ? 0 : lookcol[i][j - 1]) + (grid[i][j] == 'E' ? 1 : 0);
			sum[i][j] = lookrow[i][j] + lookcol[i][j];
		}
	}

	// clear the buffer !! can not user clear
	for (int i = 0; i<row; i++) {
		for (int j = 0; j<col; j++) {
			lookrow[i][j] = lookcol[i][j] = 0;
		}
	}

	// then scan from bottom right to top left
	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = col - 1; j >= 0; j--)
		{
			if (grid[i][j] == 'W') continue;
			lookrow[i][j] = (i == row - 1 ? 0 : lookrow[i + 1][j]) + (grid[i][j] == 'E' ? 1 : 0);
			lookcol[i][j] = (j == col - 1 ? 0 : lookcol[i][j + 1]) + (grid[i][j] == 'E' ? 1 : 0);
			sum[i][j] += lookrow[i][j] + lookcol[i][j];

			if (grid[i][j] == '0')
			{
				maxKill = max(maxKill, sum[i][j]);
			}

		}
	}

	return maxKill;
}