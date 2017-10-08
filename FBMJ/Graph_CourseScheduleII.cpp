/****************************************************************************************

* There are a total of n courses you have to take, labeled from 0 to n - 1.
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
* which is expressed as a pair: [0,1]
* Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you
* should take to finish all courses.
* There may be multiple correct orders, you just need to return one of them. If it is impossible to finish
* all courses, return an empty array.

* Note:
* 1.The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
* Read more about how a graph is represented.
* 2.You may assume that there are no duplicate edges in the input prerequisites.
* 具体上到某节指定的课的时候，目前总共已经上了多少节了 - same, just return how many already in the list
*****************************************************************************/

#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;


/*
 * this is a topological sort problem.
 */
typedef enum
{
	NOT_VISITED,   // not visited node
	VISITING,      // node on path
	VISITED        // visited node
} status;

//struct GraphNode
//{
//	int val;  // since all values are from 0 - n-1, so we can simply use a vector vector to represent graph
//	vector<int> neighbors;  // adgencency list
//};


bool dfsOrder(vector<vector<int>>& graph, int id, vector<int>& state, vector<int>& order)
{
	state[id] = VISITING;

	// go through all the neighbors
	for(auto neigh : graph[id])
	{
		if(state[neigh] == VISITED)
		{
			continue;
		}
		else if(state[neigh] == VISITING) return false; // we find cycle here
		else
		{
			if(dfsOrder(graph, neigh, state, order) == false) return false;
		}
	}
	state[id] = VISITED;
	order.push_back(id);  // we can check the order size here to know how many courses are done

	return true;
}

vector<pair<int, int>> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	// make graph
	vector<vector<int>> graph(numCourses);
	for(auto it : prerequisites)
	{
		graph[it.second].push_back(it.first);
	}

	vector<int> state(numCourses, NOT_VISITED);
	vector<int> order;

	for(int id = 0; id < numCourses; id++)
	{
		if(state[id] == NOT_VISITED)
		{
			if(!dfsOrder(graph, id, state, order))
			{
				return {};
			}
		}
	}

	reverse(order.begin(), order.end());

	return order;
}
