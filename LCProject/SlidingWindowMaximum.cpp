/***************************************************************************************************
 * Question 239 Sliding Window Maximum
 * company tag: Amazon, Facebook, Google,
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the
 * array to the very right. You can only see the k numbers in the window. Each time the sliding window
 * moves right by one position.
 * Note:
 * You may assume k is always valid, ie: 1 <= k <= input array's size for non-empty array.
 Example:
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
	Window position                Max
	---------------               -----
	[1  3  -1] -3  5  3  6  7       3
	 1 [3  -1  -3] 5  3  6  7       3
	 1  3 [-1  -3  5] 3  6  7       5
	 1  3  -1 [-3  5  3] 6  7       5
	 1  3  -1  -3 [5  3  6] 7       6
	 1  3  -1  -3  5 [3  6  7]      7
 ***************************************************************************************************/

#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    if(nums.empty()) return result;
    deque<pair<int, int>> maxQueue;  // this is the deque to put the maximum value-key pair
    for(int i=0; i<k; i++)  // initialize the window
    {
        while(!maxQueue.empty() && nums[i] >= maxQueue.back().first) maxQueue.pop_back(); // keep poping until max updated
        maxQueue.emplace_back(nums[i], i);
    }
    for(int i=k; i<nums.size(); i++) // update the deque
    {
        result.push_back(maxQueue.front().first);
        if(!maxQueue.empty() && maxQueue.front().second <= i-k) maxQueue.pop_front();
        while(!maxQueue.empty() && maxQueue.back().first <= nums[i]) maxQueue.pop_back();  // same vallue update index
        maxQueue.emplace_back(nums[i], i);
    }
    result.push_back(maxQueue.front().first);
    return result;
}

vector<int> maxSlidingWindow_improveCodeConvention(vector<int>& nums, int k)
{
    vector<int> result;
    if(nums.empty()) return result;
    deque<pair<int, int>> maxQueue;  // this is the deque to put the maximum value-key pair
    for(int i=0; i<nums.size(); i++)
    {
        if(!maxQueue.empty() && maxQueue.front().second <= i-k) maxQueue.pop_front();
        while(!maxQueue.empty() && maxQueue.back().first <= nums[i]) maxQueue.pop_back();  // same vallue update index
        maxQueue.emplace_back(nums[i], i);
        if(i >= k-1 && !maxQueue.empty()) result.push_back(maxQueue.front().first);
    }

    return result;
}

// O(Nlgk) solution - use a multiset which has capacity of k
