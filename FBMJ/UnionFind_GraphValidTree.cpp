/*************************************************************/
/*
* Question: #261 Graph Valid Tree
* Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
* write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.

*/
/***********************************************************/

#include <vector>

using namespace std;

// helper function
static int unionfind(vector<int>& nums, int i)
{
	if(nums[i] == -1) return i;
	return unionfind(nums, nums[i]);
}

//
bool validTree(int n, vector<pair<int, int>>& edges)
{
	// initialize n isolated islands
	vector<int> nums(n, -1);
	// perform unit find
	for(auto i=0; i<edges.size(); i++)
	{
		int x = unionfind(nums, edges[i].first);
		int y = unionfind(nums, edges[i].second);
		// if two vertices happen to be in the same set then there is a cycle
		if(x == y) return false;
		// union
		nums[y] = x;
	}
	return edges.size() == n-1;
}
