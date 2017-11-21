/******************************************************************************
* Question: #305 Number of Islands II
* A 2d grid map of m rows and n columns is initially filled with water.
* We may perform an addLand operation which turns the water at position (row, col) into a land.
* Given a list of positions to operate, count the number of islands after each addLand operation.
* An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
* You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0


Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0


Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0


Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0


Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0


We return the result as an array: [1, 1, 2, 3]

* Can you do it in time complexity O(k log mn), where k is the length of the positions?
*********************************************************************************/

#include <vector>

using namespace std;

static int dx[4] = {-1, 1, 0, 0};
static int dy[4] = {0, 0, -1, 1};

int findRoots(vector<int>& roots, int id)
{
	while(roots[id] != id) id = roots[id];
	return id;
}

// a union find problem
vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions)
{
	// initial union-find roots
	vector<int> roots(m*n, -1);
	vector<int> island;
	int count = 0;

	for(auto& pos : positions)
	{
		int r = pos.first;
		int c = pos.second;
		int root = r*n + c;
		roots[root] = root;
		count++;

		for(int k=0; k<4; k++)
		{
			int x = r + dx[k];
			int y = c + dy[k];
			int nbid = x*n + y;
			if(x < 0 || x >= m || y < 0 || y >= n || roots[nbid] == -1) continue;
			int nbroot = findRoots(roots, nbid);  // find root for current neighbor, time complexity O(logMN) ?
			if(nbroot != root)  // union - change current root to be joint root
			{
				roots[root] = nbroot;
				root = nbroot;  // !!!!! if other neighbor has different root, this can lead to another joint
				count--;
			}
		}
		island.push_back(count);
	}
	return island;
}


