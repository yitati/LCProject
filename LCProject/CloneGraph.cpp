/******************************************************************************
* Question: #133 Clone Graph
* company tag: Facebook
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*
* company tag: Facebook
* compare adgencency list and adgencency matrix
*****************************************************************************/


#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

/*
what data structres are used to describe a graph?
- adjacency matrix (1 means there is one edge between these two vertice, and 0 means no edge)
    0  1  2  3  4
0   1  0  1  1  1
1   0  0  0  0  1
2   1  0  0  0  1
3   1  0  0  0  0
4   1  0  1  1  0

- adjacency list
0 - [1, 2, 3]
1 - [2, 4]

which one is better?
It depenes, when the edge is quite sparse in this graph, we wan to use adgencency list.
If the graph is very dence or our traversal happens a lot on edges instead of nodes, then
we want to use adjencency matrix.

*/

// clone graph
struct GraphNode {
	int id;
	vector<GraphNode*> neigh;
	GraphNode(int i) : id(i) {}
};

/*************** DFS solution ******************/
GraphNode* cloneGraphDfs(GraphNode* node, unordered_map<GraphNode*, GraphNode*>& table) {
	if (!node) return NULL;
	if (!table.count(node)) {
		GraphNode* nodeCopy = new GraphNode(node->id);

		for (auto nei : node->neigh) nodeCopy->neigh.push_back(cloneGraphDfs(nei, table));

		table[node] = nodeCopy;
	}
	return table[node];
}

GraphNode* cloneGraph(GraphNode* node) {
	unordered_map<GraphNode*, GraphNode*> table;
	return cloneGraphDfs(node, table);
}

/************* BFS solution ********************/
GraphNode* cloneGraphBfs(GraphNode* node) {
	if (!node) return NULL;
	queue<GraphNode*> level;
	level.push(node);

	unordered_map<GraphNode*, GraphNode*> table;
	table[node] = new GraphNode(node->id);

	while (!level.empty()) {
		auto curr = level.front();
		level.pop();

		for (auto nei : curr->neigh) {
			// copy current neighbor
			if (!table.count(nei)) {
				level.push(nei);
				table[nei] = new GraphNode(nei->id);
			}
			table[curr]->neigh.push_back(table[nei]);
		}
	}

	return table[node];
}

///////////////////////////////////////////  LEETCODE /////////////////////////////////////////

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	
};


/*
 * Solution 1 - BFS
 * - use queue<UndirectedGraphNode*> to keep the node to visit
 * - use unordered_map<int, UndirectedGraphNode*> to record the visited ones and to link the Node
 */
UndirectedGraphNode* cloneGraph_bfs(UndirectedGraphNode* node)
{
    if(!node) return NULL;
    unordered_map<int, UndirectedGraphNode*> visited;
    queue<UndirectedGraphNode*> nodeQueue;
    UndirectedGraphNode* copyNode = new UndirectedGraphNode(node->label);
    visited[node->label] = copyNode;
    nodeQueue.push(node);

    while(!nodeQueue.empty())
    {
        UndirectedGraphNode* curr = nodeQueue.front();
        nodeQueue.pop();
        for(auto neigh : curr->neighbors)  // loop through all its neighbors
        {
            if(!visited.count(neigh->label))
            {
                UndirectedGraphNode* copyNeigh = new UndirectedGraphNode(neigh->label);
                visited[neigh->label] = copyNeigh;
                nodeQueue.push(neigh);
            }
            visited[curr->label]->neighbors.push_back(visited[neigh->label]);
        }
    }

    return copyNode;
}

/*
 * Solution 2 - DFS
 * simply map the
 */
static unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> graphMap;
UndirectedGraphNode* cloneGraph_dfs(UndirectedGraphNode* node)
{
    if(!node) return NULL;
    if(!graphMap.count(node))
    {
        // first copy this node
        graphMap[node] = new UndirectedGraphNode(node->label);
        for(auto neigh : node->neighbors)
        {
            graphMap[node]->neighbors.push_back(cloneGraph_dfs(neigh));
        }
    }
    return graphMap[node];
}
