/*************************************************************
 * Question #373 Find K Pairs with Smallest Sums
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
 * Define a pair (u, v) which consists of one element from the first array and one element from
 * the second array.
 * Find the k pairs (u1, v1), (u2, v2)....(uk, vk) with the smallest sum

Example 1:

Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]


Example 2:

Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]


Example 3:

Given nums1 = [1,2], nums2 = [3],  k = 3

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

*************************************************************/

#include <vector>
#include <queue>

using namespace std;



// TODO
// Review the usage of auto decltype
// Review the usage of emplace_back
// Review the usage of emplace...

// [1, 1, 2]
// [1, 2, 3]

// if we take this two input array as a matrix, with one being the row and the other being col
// then dp[i][j] indicate the sum of num1[i] and num2[j], everytime we can choose either go right
// or go down - similar to LC 378 Kth Smallest Element in Sorted Matrix
// using a min heap to solve this problem
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	vector<pair<int, int>> result;
	if(nums1.empty() || nums2.empty() || k == 0) return result;
	auto comp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b)  // comp for min heap
	{
		return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);
	minHeap.emplace(0, 0);
	while(k-- && minHeap.size())
	{
		auto idxPair = minHeap.top();
		minHeap.pop();
		result.emplace_back(nums1[idxPair.first], nums2[idxPair.second]);
		if(idxPair.first + 1 < num s1.size())
		{
			minHeap.emplace(idxPair.first+1, idxPair.second);
		}
		if(idxPair.first == 0 && idxPair.second + 1 < nums2.size())  // to avoid of duplicates
		{
			minHeap.emplace(idxPair.first, idxPair.second+1);
		}
	}
	return result;
}

