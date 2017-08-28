/*
 * Laicode_KthSmallestSumInTwoSortedArray.cpp
 *

Given two sorted arrays A and B, of sizes m and n respectively. Define s = a + b,
where a is one element from A and b is one element from B. Find the Kth smallest s out of all possible s'.

Assumptions

A is not null and A is not of zero length, so as B
K > 0 and K <= m * n
Examples

A = {1, 3, 5}, B = {4, 8}

1st smallest s is 1 + 4 = 5
2nd smallest s is 3 + 4 = 7
3rd, 4th smallest s are 9 (1 + 8, 4 + 5)
5th smallest s is 3 + 8 = 11

 */

#include <queue>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * There are totally m*n possiblilities and we need to consider all of them.
 * Best First Search, suppose we have a heap, every time when the top (min value)
 * is poped, we need to push both (i+1, j) and (i, j+1)
 * Important note : do dedup!
 */
int kthSum(vector<int> a, vector<int> b, int k)
{
	int i = 0, j = 0, sum = 0;
	int m = a.size(), n = b.size();
	auto comp = [&](const pair<int, int>& lhs, const pair<int, int>& rhs)->bool{
		return a[lhs.first] + b[lhs.second] > a[rhs.first] + b[rhs.second];
	};

	vector<bool> visit(m*n, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

	minHeap.push(make_pair(0, 0));
	visit[0] = true;

	while(k > 0)
	{
		auto curr = minHeap.top();
		minHeap.pop();
		k--;
		sum = a[curr.first] + b[curr.second];
		int flatidx1 = (curr.first+1)*n + curr.second;
		int flatidx2 = curr.first*n + (curr.second+1);
		if(curr.first+1 < a.size() && !visit[flatidx1])
		{
			visit[flatidx1] = true;
			minHeap.push(make_pair(curr.first+1, curr.second));
		}
		if(curr.second+1 < b.size() && !visit[flatidx2])
		{
			visit[flatidx2] = true;
			minHeap.push(make_pair(curr.first, curr.second+1));
		}
	}

	return sum;
}

/*
int main(int argc, char ** argv)
{
	vector<int> a = {1, 3, 5, 8, 9};
	vector<int> b = {2, 3, 4, 7};

	cout << kthSum(a, b, 6)<< endl;

}
*/


