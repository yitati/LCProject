/******************************************************************************/
/**
* Question: #207 Course Schedule
* There are a total of n courses you have to take, labeled from 0 to n-1.
* Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expresed as 
* a pair: [0, 1]
* Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
* For example:
* 2, [[1, 0]]
* There are total of 2 coursees to take. To take course 1 you should have finished course 0. So it is possible.
* 2, [[1, 0], [0,1]]
* There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you
* should have finished course 1. So it is impossible.
* Note:
* The input prerequisites is a grap represented by a list of edges, not adjacency matrices. 
* 
* Question: 210 Course Schedule II
* Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to 
* finish all courses.
* 
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// There are three states needed for each of the vertices - not visited (0), visited (1) and done exploring (2).
// 0 - marks not visited vertice
// 1 - marks visited vertice, as long as it has at least one decending vertice that is not explored, then the vertice
// will be marked as visited.
// 2 - marks done state. All decending vertices have been explored and there is no cycle exiting.
enum state { NOT_VISITED, VISITED, DONE };

// graph node structure
struct graphNode 
{
	int val;
	int state;
	vector<int> children;
	graphNode(int x) : val(x) {};
	graphNode() {};
};


bool dfsHelper(vector<graphNode> & vertices, int index)
{
	vertices[index].state = VISITED;
	for (int i = 0; i < vertices[index].children.size(); i++)
	{
		int curr = vertices[index].children[i];
		if (vertices[curr].state == DONE) continue; // if all decending vertices has been done
		if (vertices[curr].state == VISITED) return false;
		if (dfsHelper(vertices, curr) == false) return false;
	}
	vertices[index].state = DONE;
	return true;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	vector<graphNode> vertices(numCourses);
	// build the graph
	for (int i = 0; i < numCourses; i++) 
	{
		vertices[i].val = i;
		vertices[i].state = NOT_VISITED;
	}
	for (int i = 0; i < prerequisites.size(); i++)
	{
		int first = prerequisites[i].first;
		int second = prerequisites[i].second;
		vertices[first].children.push_back(second);
	}
	for (int i = 0; i < numCourses; i++) 
	{
		if (vertices[i].state == NOT_VISITED) 
		{
			if (dfsHelper(vertices, i) == false) return false;
		}
	}

	return true;
}

// prepare two stack visited and done to store the vertices
bool dfsSort(vector<graphNode> & vertices, int index, vector<int> & order)
{
	vertices[index].state = VISITED;
	for (int i = 0; i < vertices[index].children.size(); i++)
	{
		int curr = vertices[index].children[i];
		if (vertices[curr].state == DONE) continue; // if all decending vertices has been done
		if (vertices[curr].state == VISITED) return false;
		if (dfsSort(vertices, curr, order) == false) return false;
	}
	vertices[index].state = DONE;
	order.push_back(vertices[index].val);
	return true;
}

// question course schedule II is actually doing the topological sort
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
{
	vector<graphNode> vertices(numCourses);
	vector<int> order;

	// build the graph
	for (int i = 0; i < numCourses; i++)
	{
		vertices[i].val = i;
		vertices[i].state = NOT_VISITED;
	}
	for (int i = 0; i < prerequisites.size(); i++)
	{
		int first = prerequisites[i].first;
		int second = prerequisites[i].second;
		vertices[first].children.push_back(second);
	}
	for (int i = 0; i < numCourses; i++)
	{
		if (vertices[i].state == NOT_VISITED)
		{
			if (dfsSort(vertices, i, order) == false)
			{
				return {};
			}
		}
	}

	std::reverse(order.begin(), order.end());

	return order;

}

/*
int main(int argc, char * argv)
{
	vector<int> order;

	vector<pair<int, int>> prerequisites;
	std::pair<int,int> pair1(0, 1);
	prerequisites.push_back(pair1);

	std::pair<int, int> pair2(1, 2);
	prerequisites.push_back(pair2);

	std::pair<int, int> pair3(2, 3);
	prerequisites.push_back(pair3);

	cout << canFinish(4, prerequisites) << endl;

	order = findOrder(4, prerequisites);

	for (int i = 0; i < order.size(); i++)
	{
		cout << order[i] << "   ";
	}

	cout << endl;

	std::pair<int, int> pair4(3, 1);
	prerequisites.push_back(pair4);

	order.clear();

	cout << canFinish(4, prerequisites) << endl;

	order = findOrder(4, prerequisites);

	for (int i = 0; i < order.size(); i++)
	{
		cout << order[i] << "    ";
	}

	cout << endl;

	system("pause");

}

*/