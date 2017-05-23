/******************************************************************************/
/*
* Question: #554 Brick Wall
* There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
* The bricks have the same height but different width. You want to draw a vertical line from the 
* top to the bottom and cross the least bricks. 
* The brick wall is represented by a list of rows. Each row is a list of integers representing 
* the width of each brick in this row from left to right. 
* If your line go through the edge of a brick, then the brick is not considered as crossed. 
* You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks. 
* You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will 
* obviously cross no bricks. 
*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int leastBricks(vector<vector<int>>& wall)
{
	if (wall.empty()) return 0;
	int row = wall.size(), width = 0, minCut = 0;
	// first we need to know the width of each row
	for (int brickLen : wall[0]) width += brickLen;
	unordered_map<int, int> cut;
	for (int i = 0; i<row; i++)
	{
		int rowWidth = 0;
		for (int j = 0; j<wall[i].size() - 1; j++)
		{
			rowWidth += wall[i][j];
			cut[rowWidth]--;
			minCut = min(minCut, cut[rowWidth]);
		}
	}
	return row + minCut;
}