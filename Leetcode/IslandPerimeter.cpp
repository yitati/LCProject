/******************************************************************************/
/*
* Question: #463 Island Perimeter
* You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
* Grid cells are connected horizontally/vertically (not diagonally). 
* The grid is completely surrounded by water, and there is exactly one island 
* (i.e., one or more connected land cells). The island doesn't have "lakes" 
* (water inside that isn't connected to the water around the island). 
* One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
* Determine the perimeter of the island.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) 
{
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int perimeter = 0;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			if (grid[i][j] == 0) continue;
			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];
				if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
				{
					perimeter++;
					continue;
				}
				else
				{
					if (grid[x][y] == 0) perimeter++;
				}
			}
		}
	}

	return perimeter;
}