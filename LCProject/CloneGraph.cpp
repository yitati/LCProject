/******************************************************************************
* Question: #133 Clone Graph
* company tag: Facebook
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*****************************************************************************/

// TODO - redo this problem

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
{
	if (node == NULL) return NULL;
	UndirectedGraphNode * newNode = new UndirectedGraphNode(node->label);
	unordered_map<int, UndirectedGraphNode *> visited;
	visited[node->label] = newNode;
	queue<UndirectedGraphNode *> table;
	table.push(node);

	while (!table.empty())
	{
		UndirectedGraphNode * currNode = table.front();
		table.pop();
		for (auto neighbor : currNode->neighbors)
		{
			if (!visited.count(neighbor->label))
			{
				UndirectedGraphNode * copyNeighbor = new UndirectedGraphNode(neighbor->label);
				visited[neighbor->label] = copyNeighbor;
				table.push(neighbor);
			}
			visited[currNode->label]->neighbors.push_back(visited[neighbor->label]);
		}
	}
	return newNode;
}
