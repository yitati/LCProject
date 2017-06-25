/******************************************************************************/
/**
* Question: #313 Super Ugly Number
* Write a program to find the nth super ugly number. 
* Super ugly numbers are positive numbers whose all prime factors are 
* in the given prime list primes of size k. 
* For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence 
* of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4. 

* Note:
* (1) 1 is a super ugly number for any given primes.
* (2) The given numbers in primes are in ascending order.
* (3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
* (4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer. 

/*****************************************************************************/

#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>

using namespace std;

int nthSuperUglyNumber_etl(int n, vector<int>& primes) 
{
	priority_queue<long, vector<long>, greater<long long>> minHeap;
	unordered_set<long> visited;
	
	visited.insert(1);
	minHeap.push(1);
	int x = 1;
	for (int i = 0; i < n; i++)
	{
		x = minHeap.top();
		minHeap.pop();
		for (int k = 0; k < primes.size(); k++)
		{
			int num = x * primes[k];
			if (!visited.count(num))
			{
				visited.insert(num);
				minHeap.push(num);
			}
		}
	}
	return x;
}

int nthSuperUglyNumber(int n, vector<int>& primes)
{
	int k = primes.size();
	vector<int> index(k, 0);
	vector<int> ugly(n, INT_MAX);
	ugly[0] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < k; j++) ugly[i] = min(ugly[i], primes[j] * ugly[index[j]]);
		for (int j = 0; j < k; j++)
		{
			if (ugly[i] == ugly[index[j]] * primes[j]) index[j]++;
		}
	}

	return ugly[n - 1];
}
