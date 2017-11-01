/*
 * ShortestPathBetweenUndirectedGraphNodes.cpp
 *
Find the length of shortest path between two nodes in a non-directed graph.
 */

#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode
{
	int id;
	vector<UndirectedGraphNode*> neighbors;
};

int shortestPath(UndirectedGraphNode* a, UndirectedGraphNode* b)
{
	if(!a || !b) return INT_MAX;

	queue<UndirectedGraphNode*> level;
	unordered_set<int> visited;

	int step = 0;
	level.push(a);
	visited.insert(a->id);

	while(!level.empty())
	{
		int size = level.size();
		for(int i=0; i<size; i++)
		{
			auto curr = level.front();
			level.pop();
			if(curr == b) return step;
			for(auto neigh : curr->neighbors)
			{
				if(visited.count(neigh->id)) continue;
				level.push(neigh);
				visited.insert(neigh->id);
			}
			step++;
		}
	}
	return INT_MAX;  // b maybe not existing in the graph
}




