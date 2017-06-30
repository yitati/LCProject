/******************************************************************************/
/*
* Question: #347 Top K Frequent Elements
* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2]. 

* Note: 
* You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
* Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
/*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// We can use max heap to store n element, O(nlgn)
// Or we can use min heap to store k elemnt, O(nlgk)
// Return TRUE means lhs has LOWER priority
class FreqComp
{
public:
	bool operator() (const pair<int, int> & lhs, const pair<int, int> & rhs) const
	{
		return (lhs.second > rhs.second);
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) 
{
	unordered_map<int, int> table;
	for (size_t i = 0; i < nums.size(); i++)
	{
		table[nums[i]]++;
	}
	FreqComp comp;
	priority_queue<pair<int, int>, vector<pair<int, int>>, FreqComp> minHeap(comp);
	for (pair<int, int>curr : table)
	{
		minHeap.push(curr);
		if (minHeap.size() > k) minHeap.pop();
	}

	vector<int> result;
	while (!minHeap.empty())
	{
		pair<int, int> curr = minHeap.top();
		minHeap.pop();
		result.push_back(curr.first);
	}

	reverse(result.begin(), result.end());
	return result;
}