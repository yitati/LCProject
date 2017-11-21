/******************************************************************************
* Question: #542 01 Matrix
* Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
* The distance between two adjacent cells is 1.
*
Example 1:
Input:
0 0 0
0 1 0
0 0 0

Output:
0 0 0
0 1 0
0 0 0

Example 2:
Input:
0 0 0
0 1 0
1 1 1

Output:
0 0 0
0 1 0
1 2 1

* Note:
* 1.The number of elements of the given matrix will not exceed 10,000.
* 2.There are at least one 0 in the given matrix.
* 3.The cells are adjacent in only four directions: up, down, left and right.
*
*****************************************************************************/
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// it is not hard to get the conclusion that
// 1. if matrix[i][j] = 0 dist[i][j] = 0
// 2. if matrix[i][j] = 1 dist[i][j] = min(dist[4 neighburs]) + 1
// but to update the whole matrix we need to use BFS and to save space we use flat index
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
	const int dx[4] = {-1, 1, 0, 0};
	const int dy[4] = {0, 0, -1, 1};

	if(matrix.empty() || matrix[0].empty()) return {};
	int row = matrix.size(), col = matrix[0].size();
	queue<pair<int, int>> layer;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
		{
			if(matrix[i][j] == 0)
			{
				layer.push(make_pair(i, j));
			}
            else matrix[i][j] = INT_MAX;
		}
	}
	// BFS emplace the value
	while(!layer.empty())
	{
		int layerSize = layer.size();
		for(int k=0; k<layerSize; k++)
		{
			int r = layer.front().first;
            int c = layer.front().second;
			layer.pop();
			for(int t = 0; t < 4; t++)
			{
				int x = r + dx[t];
				int y = c + dy[t];
				if(x < 0 || x >= row || y < 0 || y >= col) continue;
				if(matrix[x][y] > matrix[r][c] + 1)
                {
                    matrix[x][y] = matrix[r][c]+1;
                    layer.push(make_pair(x, y));
                }
			}
		}
	}
	return matrix;
}



