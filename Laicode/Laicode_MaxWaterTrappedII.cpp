/*
 * Laicode_MaxWaterTrappedII.cpp

Given a non-negative integer 2D array representing the heights of bars in a matrix.
Suppose each bar has length and width of 1. Find the largest amount of water that
can be trapped in the matrix. The water can flow into a neighboring bar if the
neighboring bar's height is smaller than the water's height. Each bar has 4 neighboring
bars to the left, right, up and down side.

Assumptions

The given matrix is not null and has size of M * N, where M > 0 and N > 0,
all the values are non-negative integers in the matrix.
Examples

{ { 2, 3, 4, 2 },

  { 3, 1, 2, 3 },

  { 4, 3, 5, 4 } }

the amount of water can be trapped is 3,

at position (1, 1) there is 2 units of water trapped,

at position (1, 2) there is 1 unit of water trapped.

 */

#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

/*
 * use a BFS solution to choose everytime the min boundary point and calculate the water accumulated
 */
int maxTrappedII(vector<vector<int>> matrix) {
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	if(matrix.empty() || matrix[0].empty()) return 0;
	int row = matrix.size(), col = matrix[0].size();
	// create visited matrix
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	// comparator for the min heap
	auto comp = [&](const pair<int, int>& lhs, const pair<int, int> & rhs) -> bool{
		return matrix[lhs.first][lhs.second] > matrix[rhs.first][rhs.second];
		};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
	// push the boundary points
	for(int i=0; i<row; i++)
	{
		minHeap.emplace(i, 0);
		minHeap.emplace(i, col-1);
		visited[i][0] = true;
		visited[i][col-1] = true;
	}
	for(int j=1; j<col-1; j++)
	{
		minHeap.emplace(0, j);
		minHeap.emplace(row-1, j);
		visited[0][j] = true;
		visited[row-1][j] = true;
	}
	// start bfs
	int maxHeight = INT_MIN;
	int water = 0;
	while(!minHeap.empty())
	{
		int r = minHeap.top().first;
		int c = minHeap.top().second;
		minHeap.pop();
		maxHeight = max(maxHeight, matrix[r][c]);
		water += max(0, maxHeight-matrix[r][c]);
		for(int k=0; k<4; k++)
		{
			int x = r + dx[k];
			int y = c + dy[k];
			if(x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) continue;
			visited[x][y] = true;
			minHeap.emplace(x, y);
		}
	}
	return water;
}
