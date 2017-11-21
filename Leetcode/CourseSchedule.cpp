/******************************************************************************
* Question: #207 Course Schedule
* company tag: Facebook
* There are a total of n courses you have to take, labeled from 0 to n - 1.
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
* which is expressed as a pair: [0,1]
* Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 

For example:
2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 
you should also have finished course 1. So it is impossible.

* Note:
* 1.The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
* Read more about how a graph is represented.
* 2.You may assume that there are no duplicate edges in the input prerequisites.
*****************************************************************************/


#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Solution 1 - Use DFS and back-tracking, we need two marks, one for global(visited) and one for current path(onPath)
bool canFinish_dfs(vector<unordered_set<int>> & graph, int level, vector<bool>& onPath, vector<bool> & visited)
{
	onPath[level] = true;
	for (int neigh : graph[level])
	{
		if (onPath[neigh]) return false;
		if (visited[neigh]) continue;
		if (!canFinish_dfs(graph, neigh, onPath, visited)) return false;
	}
	onPath[level] = false;
	visited[level] = true;
	return true;
}

vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>> & prerequisites)
{
	vector<unordered_set<int>> graph(numCourses);
	for (auto pre : prerequisites)
	{
		graph[pre.second].insert(pre.first);
	}
	return graph;
}

bool canFinishDFS(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
	vector<bool> visited(numCourses, false), onPath(numCourses, false);
	for (int i = 0; i<numCourses; i++)
	{
		if (visited[i] == 2) continue;
		if (!canFinish_dfs(graph, i, onPath, visited)) return false;
	}

	return true;
}

// Solution 2 - Use BFS solution, assign degree for each node and see if degree 0 node always exists.

vector<int>computeDegree(vector<unordered_set<int>> & graph)
{
	vector<int> degree(graph.size(), 0);
	for (auto curr : graph)
	{
		for (int neigh : curr)
		{
			degree[neigh]++;
		}
	}
	return degree;
}

bool canFinishBFS(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
	vector<int> degree = computeDegree(graph);
	for(int i=0; i<numCourses; i++)
	{
		int j = 0; 
		for (; j < numCourses; j++)
		{
			if (degree[j] == 0) break;
		}
		// if there is no degree == 0, then there is an cycle
		if (j == numCourses) return false;
		degree[j] = -1;
		for (auto neigh : graph[j])
		{
			degree[neigh]--;
		}
	}
	return true;
}
