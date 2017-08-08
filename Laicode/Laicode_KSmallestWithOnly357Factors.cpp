/*
 * Laicode_KSmallestWithOnly357Factors.cpp
 *
Find the Kth smallest number s such that s = 3 ^ x * 5 ^ y * 7 ^ z, x > 0 and y > 0 and z > 0,
x, y, z are all integers.

Assumptions

K >= 1
Examples

the smallest is 3 * 5 * 7 = 105
the 2nd smallest is 3 ^ 2 * 5 * 7 = 315
the 3rd smallest is 3 * 5 ^ 2 * 7 = 525
the 5th smallest is 3 ^ 3 * 5 * 7 = 945

 */

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
#include <queue>

using namespace std;

// same as LC 313 Super ugly number
// Solution 1 - use index table
long kthNumWith357Factors(int k)
{
	vector<long> ugly(k, INT_MAX);
	vector<int> index(3, 0);
	vector<int> primes = {3, 5, 7};
	ugly[0] = 3*5*7;
	for(int i=1; i<k; i++)
	{
		for(int j=0; j<3; j++) ugly[i] = min(ugly[i], primes[j] * ugly[index[j]]);
		for(int j=0; j<3; j++) {
			if(ugly[i] == ugly[index[j]] * primes[j]) index[j]++;
		}
	}
	return ugly[k-1];
}

// Solution 2 - use min heap
long kthNumWith357Factors_minHeap(int k)
{
	priority_queue<long, vector<long>, greater<long>> minHeap;
	unordered_set<long> visited;
	vector<int> primes = {3, 5, 7};
	minHeap.push(105);
	visited.insert(105);


	for(int i=1; i<k; i++)
	{
		int curr = minHeap.top();
		minHeap.pop();
		for(int j = 0; j < primes.size(); j++)
		{
			int next = curr*primes[j];
			if(!visited.count(next))
			{
				minHeap.push(next);
				visited.insert(next);
			}
		}
	}
	return minHeap.top();
}



