/******************************************************************************/
/*
* Question: #134 Gas Station
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i]. 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
* You begin the journey with an empty tank at one of the gas stations. 

* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 

* Note:
* The solution is guaranteed to be unique. 
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// normally we need O(n^2) for the brutal force solution, but here is how to reduce the time complexity
// If start from i and stop before x, then no station k from i+1 to x-1 can reach x
// Bcoz if so, i can reach k and k can reach x then i can reach x, controdiction.
// Thus i can jump directly to x instead of i+1, bring complexity from O(n^2) to O(n)

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int i = 0, j = 0, n = gas.size();
	for (i = 0; i < n; i+=j)
	{
		int left = 0;
		for (j = 1; j <= n; j++)
		{
			int k = (i + j - 1) % n;
			left += gas[k] - cost[k];
			if (left < 0) break;
 		}
		if (j > n)
		{
			return i;
		}
	}
	return -1;
}