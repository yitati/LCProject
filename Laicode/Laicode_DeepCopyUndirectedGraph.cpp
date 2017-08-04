/*
 * Laicode_DeepCopyUndirectedGraph.cpp

Make a deep copy of an undirected graph, there could be cycles in the original graph.

Assumptions

The given graph is not null

*/

#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

class GraphNode{
public:
	int value;
	vector<GraphNode*> neighbors;
	GraphNode(int v): value(v){}
};

// BFS solution
GraphNode* DeepCopyUndirectedGraph_BFS(GraphNode* startNode){
	if(!startNode) return NULL;

}

// DFS solution
static unordered_map<GraphNode*, GraphNode*> lookup;
GraphNode * DeepCopyUndirectedGraph_DFS(GraphNode* startNode)
{
	// check startNode
	if(!startNode) return NULL;
	if(!lookup.count(startNode)){
		lookup[startNode] = new GraphNode(startNode->value);
		for(auto neigh : startNode->neighbors){
			lookup[startNode]->neighbors.push_back(DeepCopyUndirectedGraph_DFS(neigh));
		}
	}
	return lookup[startNode];
}




