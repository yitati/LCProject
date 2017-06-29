/******************************************************************************/
/**
* Question: #215 Kth Largest Element in an Array
* Find the kth largest element in an unsorted array. Note that it is the kth largest element 
* in the sorted order, not the kth distinct element. 

For example,
Given [3,2,1,5,6,4] and k = 2, return 5. 

* Note: 
* You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
/*****************************************************************************/

#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) 
{
	int result;
	priority_queue<int> maxHeap;
	for (int i = 0; i < nums.size(); i++)
	{
		maxHeap.push(nums[i]);
	}
	while (k--)
	{
		result = maxHeap.top();
		maxHeap.pop();
	}
	return result;
}