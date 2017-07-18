/*
 * Even Tree
 * company tag: Facebook
 * You are given a tree(a simple connected graph with no cycle). The tree has N nodes numbered from 1 to N
 * and is rooted at node 1.
 * Find the maximum number of edges you can remove from the tree to get a forest such that each connected
 * component of the forest contains an even number of nodes.
 * https://www.hackerrank.com/challenges/even-tree
 * http://www.geeksforgeeks.org/convert-tree-forest-even-nodes/
 *
 */

/*
 *  Counting number of children for each tree, if subtree has even number of children then we can remove the
 *  edge leading to this subtree. Otherwise we should keep the edge.
 */

#include <vector>

using namespace std;

// return number of children including this node to its parent
int decomposeTree_dfs(vector<vector<int>>& tree, vector<bool>& visit, int& maxNum, int curr)
{
	int num = 0, subtree = 0;
	// mark this node as visited
	visit[curr] = true;
	for(int i=0; i<tree[curr].size(); i++)
	{
		if(visit[tree[curr][i]] == true) continue;
		// find number of children in one of its subtree
		subtree = decomposeTree_dfs(tree, visit, maxNum, tree[curr][i]);
		if(subtree%2 == 0) maxNum += 1;
		else num += subtree;
	}
	return num;
}

int maxEdge(vector<vector<int>> tree, int n)
{
	vector<bool> visit(n+1, false);
	int maxNum = 0;
	decomposeTree_dfs(tree, visit, maxNum, 1);
	return maxNum;
}

/*
 * we can also use a vector of pair to store all the edges - just replace maxNum increasement to
 * push one edge to the final result.
 */

