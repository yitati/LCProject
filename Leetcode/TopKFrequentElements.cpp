/******************************************************************************
* Question: #347 Top K Frequent Elements
* company tag: eBay
* Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2]. 

* Note: 
* You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
* Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// use size k min heap to solve this issue
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    // stat the frequence
    unordered_map<int, int> freq;
    for(int num : nums)
    {
        freq[num]++;
    }
    auto comp = [&](const pair<int, int> & lhs, const pair<int, int> & rhs)->bool{
        return lhs.second > rhs.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

    // find the top k frequent number
    vector<int> topk;
    for(auto it = freq.begin(); it != freq.end(); it++)
    {
        minHeap.push(make_pair(it->first, it->second));
        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    while(!minHeap.empty())
    {
        topk.push_back(minHeap.top().first);
        minHeap.pop();
    }

    return topk;
}
