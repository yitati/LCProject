/******************************************************************************
* Question: #264 Ugly Number II
* company tag: eBay
* Write a program to find the n-th ugly number.
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
* For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
* Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

* Hint:
* The naive approach is to call isUgly for every number until you reach the nth one. 
* Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
* An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
* The key is how to maintain the order of the ugly numbers. Try a similar approach of merging 
* from three sorted lists: L1, L2, and L3.
* Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
*****************************************************************************/

#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

int nthUglyNumber(int n) 
{
	unordered_set<long long> visited;
	priority_queue<long long, vector<long long>, greater<long long>> minHeap;
	if (n <= 6) return n;
	int factor[3] = { 2, 3, 5 };
	minHeap.push(1);
	visited.insert(1);
	long long x = 1;
	for (int i = 0; i<n; i++)
	{
		x = minHeap.top();
		minHeap.pop();
		for (int k = 0; k < 3; k++)
		{
			long long num = x * factor[k];
			if (!visited.count(num))
			{
				minHeap.push(num);
				visited.insert(num);
			}
		}
	}

	return x;
}
