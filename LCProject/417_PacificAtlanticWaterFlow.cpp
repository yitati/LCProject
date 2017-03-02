/******************************************************************************/
/*
* Question: #417 Pacific Atlantic Water Flow
* Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
* the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the 
* right and bottom edges.
* Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
* Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

* Note:
* The order of returned grid coordinates does not matter.
* Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/
/*****************************************************************************/

#include <vector>
#include <queue>

using namespace std;

void waterPropagate(queue<pair<int, int>> & bfs, vector<vector<int>> & matrix, vector<vector<int>> & visited)
{
	const static int dx[4] = { -1, 1, 0, 0 };
	const static int dy[4] = { 0, 0, -1, 1 };
	int row = matrix.size(), col = matrix[0].size();
	while (!bfs.empty())
	{
		pair<int, int> point = bfs.front();
		bfs.pop();
		int current = matrix[point.first][point.second];
		for (int k = 0; k < 4; k++) {
			int r = point.first + dx[k];
			int c = point.second + dy[k];
			if (r >= 0 && r < row && c >= 0 && c < col && matrix[r][c] >= current && !visited[r][c]) {
				visited[r][c] = 1;
				bfs.push(pair<int, int>(r, c));
			}
		}
	}
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
{
	vector<pair<int, int>> result;
	if (matrix.size() == 0 || matrix[0].size() == 0) return result;
	int row = matrix.size(), col = matrix[0].size();

	queue<pair<int, int>> bfs_pacific;
	queue<pair<int, int>> bfs_atlantic;

	vector<vector<int>> visited_pacific(row, vector<int>(col, 0));
	vector<vector<int>> visited_atlantic(row, vector<int>(col, 0));

	for (int i = 0; i < row; i++)
	{
		bfs_pacific.push(pair<int, int>(i, 0));
		bfs_atlantic.push(pair<int, int>(i, col - 1));
		visited_pacific[i][0] = 1;
		visited_atlantic[i][col - 1] = 1;
	}
	for (int j = 0; j < col; j++)
	{
		if (!visited_pacific[0][j]) {
			bfs_pacific.push(pair<int, int>(0, j));
			visited_pacific[0][j] = 1;
		}
		if (!visited_atlantic[row - 1][j]) {
			bfs_atlantic.push(pair<int, int>(row - 1, j));
			visited_atlantic[row - 1][j] = 1;
		}
	}

	waterPropagate(bfs_pacific, matrix, visited_pacific);
	waterPropagate(bfs_atlantic, matrix, visited_atlantic);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (visited_pacific[i][j] == 1 && visited_atlantic[i][j] == 1) result.push_back(pair<int, int>(i, j));
		}
	}
	
	return result;
}