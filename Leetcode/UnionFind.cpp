/*
A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into 
a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two 
useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements 
are in the same subset.

Union: Join two subsets into a single subset.

In this post, we will discuss an application of Disjoint Set Data Structure. The application is to check 
whether a given graph contains a cycle or not.

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that we 
have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes 
that graph doesn�t contain any self-loops.
*/

// a union-find algorithm to detect cycle in a graph

#include <string>

// a structure to represent a graph
class Graph
{
private:
	// a structure to represent an edge in a graph
	class Edge
	{
	private:
		int src;
		int dest;
	};
	// V -> number of vertices, E -> number of edges
	int V, E;
	// graph is represented as an array of edges
	struct Edge * edge;
};

