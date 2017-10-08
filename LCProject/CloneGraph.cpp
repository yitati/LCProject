/******************************************************************************
* Question: #133 Clone Graph
* company tag: Facebook
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
*
* company tag: Facebook
* compare adgencency list and adgencency matrix
*****************************************************************************/

// TODO - discuss with BAOBAO about the DFS solution

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

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
