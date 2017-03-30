/*
* Question: #210 Course Schedule II
* There are a total of n courses you have to take, labeled from 0 to n - 1.
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
* which is expressed as a pair: [0,1]
* Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you 
* should take to finish all courses.
* There may be multiple correct orders, you just need to return one of them. If it is impossible to finish 
* all courses, return an empty array. 

For example:
2, [[1,0]]

There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
4, [[1,0],[2,0],[3,1],[3,2]]

There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. 
Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
Another correct ordering is[0,2,1,3].

* Note:
* 1.The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
* Read more about how a graph is represented.
* 2.You may assume that there are no duplicate edges in the input prerequisites.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// Solution 1 - using DFS, similar with I
vector<unordered_set<int>> makeGraph2(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<unordered_set<int>> graph(numCourses);
	for (auto curr : prerequisites)
	{
		graph[curr.second].insert(curr.first);
	}
	return graph;
}

bool hasCycle(vector<unordered_set<int>>& graph, int level, vector<bool> & visited, vector<bool> & onPath, vector<int> & toposort)
{
	if (visited[level]) return false;
	onPath[level] = true;
	for (int neigh : graph[level])
	{
		if (visited[neigh]) continue;
		if (onPath[neigh]) return true;
		if (hasCycle(graph, neigh, visited, onPath, toposort)) return true;
	}
	onPath[level] = false;
	visited[level] = true;
	// DFS the last node is the first to push to result
	toposort.push_back(level);
	return false;
}


vector<int> findOrderDFS(int numCourses, vector<pair<int, int>>& prerequisites) 
{
	vector<unordered_set<int>> graph = makeGraph2(numCourses, prerequisites);
	vector<bool> onPath(numCourses, false), visited(numCourses, false);
	vector<int> toposort;
	// search for each of the vertex
	for (int i = 0; i < numCourses; i++)
	{
		if (visited[i]) continue;
		if (hasCycle(graph, i, visited, onPath, toposort)) return{};
	}
	reverse(toposort.begin(), toposort.end());
	return toposort;
}


// Solution 2 - BFS
vector<int> computeDegree2(vector<unordered_set<int>> & graph)
{
	vector<int> degree;
	for (auto curr : graph)
	{
		for (int neigh : curr)
		{
			degree[neigh]++;
		}
	}
	return degree;
}


vector<int> findOrderBFS(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<unordered_set<int>> graph = makeGraph2(numCourses, prerequisites);
	vector<int> degree = computeDegree2(graph);
	vector<int> toposort;
	queue<int> zeros;
	for (int i = 0; i < numCourses; i++)
	{
		if (!degree[i]) zeros.push(i);
	}

	for (int i = 0; i < numCourses; i++)
	{
		if (zeros.empty()) return{};
		int zero = zeros.front();
		zeros.pop();
		toposort.push_back(zero);
		for (int neigh : graph[zero])
		{
			if (!--degree[neigh])
			{
				zeros.push(neigh);
			}
		}
	}

	return toposort;

}

