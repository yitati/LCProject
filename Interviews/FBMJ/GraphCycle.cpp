/*
 * Given an adjacency matrix of a directed graph, find the number of cycles in the graph.
 */

/*
 * using adjacency matrix to represent a directed graph, we have 1 to represent there is an edge
 * from row i to col j, so matrix[i][j] = 1
 * so to detect how many cycles in the graph, at each node we go through all its possible branches
 * and if we see a node appear on the visiting path, we find a cycle
 */
#include <vector>

using namespace std;

typedef enum
{
	NOT_VISITED,
	VISITING,   // on current visiting path
	VISITED     // visited on previous loop
} eStatus;

void findCycleDfs(vector<vector<int>>& matrix, int curr, vector<eStatus>& visit, int& cycle)
{
	visit[curr] = VISITING;

	for(int i=0; i<matrix[curr].size(); i++)
	{
		if(matrix[curr][i] == 1) // there is an edge here
		{
			if(visit[i] == VISITED) continue;
			else if(visit[i] == VISITING)
			{
				cycle++;
			}
			else
			{
				findCycleDfs(matrix, i, visit, cycle);
			}
		}
	}

	visit[curr] = VISITED;
}

int findCycleInDirectedGraph(vector<vector<int>>& matrix)
{
	int size = matrix.size();
	vector<eStatus> visit(size, NOT_VISITED);
	int cycle = 0;
	for(int curr = 0; curr < matrix.size(); curr++)
	{
		if(visit[curr] != VISITED)
		{
			findCycleDfs(matrix, curr, visit, cycle);
		}
	}
	return cycle;
}
