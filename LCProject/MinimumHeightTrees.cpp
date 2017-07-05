/******************************************************************************
* Question: #310 Minimum Height Tree
* For a undirected graph with tree characteristics, we can choose any node as the root.
* The result graph is then a rooted tree. Among all possible rooted trees, those with
* minimum height are called minimum height trees (MHTs). Given such a graph, write a
* function to find all the MHTs and return a list of their root labels.
* Format
* The graph contains n nodes which are labeled from 0 to n - 1. You will be given the
* number n and a list of undirected edges (each edge is a pair of labels).
* You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
* [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*
Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3
return  [1]

Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
     0  1  2
      \ | /
        3
        |
        4
        |
        5
return  [3, 4]

* Note:
* (1) According to the definition of tree on Wikipedia: "a tree is an undirected graph in which
* any two vertices are connected by exactly one path. In other words, any connected graph without
* simple cycles is a tree".
* (2) The height of a rooted tree is the number of edges on the longest downward path between the
* root and a leaf.
*
*****************************************************************************/

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

// brutal force solution is to find the height of each tree rooted by all the nodes
// and find the min height and compare
// But a better idea - O(N) solution here is to remove the leaf nodes every time
// until we have one or two nodes left in the graph
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges)
{
	vector<int> roots;
	unordered_map<int, unordered_set<int>> graph(n); // since vertice always from 0 to n-1
	vector<pair<int, int>> todelete;
	if(n == 1) return {0};
	// first put all edges into the graph
	for(auto& it : edges)
	{
		graph[it.first].insert(it.second);
		graph[it.second].insert(it.first);
	}

	// find all leaves
	while(graph.size() > 2)
	{
		auto it = graph.begin();
		while (it != graph.end()) {
			if (it->second.size() == 1) {
				todelete.push_back(make_pair(*it->second.begin(), it->first));
				it = graph.erase(it);
			} else {
				it++;
			}
		}
		// then remove elements from next set
		while(!todelete.empty())
		{
			int index = todelete.back().first;
            int val = todelete.back().second;
			graph[index].erase(val);
            todelete.pop_back();
		}
	}

	for(auto& it : graph) roots.push_back(it.first);
	return roots;
}

/*
int main(int argc, char ** argv)
{
	vector<pair<int, int>> edges;
	edges.push_back(make_pair(0, 3));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(4, 3));
	edges.push_back(make_pair(5, 4));

	vector<int> roots = findMinHeightTrees(6, edges);

	for(unsigned int i=0; i<roots.size(); i++)
	{
		cout << roots[i] << "   ";
	}
	cout << endl;
}
*/




