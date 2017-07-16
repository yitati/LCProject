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

// TODO - discuss with BAOBAO about better solution

/*
 *  Solution 1 :  sort and find
 *  The most straightforward solution is to sort the array, and then access the element
 *  by its index. Time complexity is O(nlogn) and space complexity is O(1)
 */
/*
 *  Solution 2 : use min heap (the kth element is the smallest among largest k elements)
 *  To find the kth largest, we push every number to the min heap, keep its capacity with k.
 *  Everytime size > k we pop the top.
 *  At last we return the top.
 */

// this is a solution that is using max heap
// time complexity O(N log N) and space complexity is O(N)
int findKthLargest_maxHeap(vector<int>& nums, int k)
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

// to improve above solution, we can use min heap which has capacity of k
// time complexity is O(nlogk) and space complexity is O(k)
int findKthLargest_minHeap(vector<int>& nums, int k)
{
	int result;
	priority_queue<int> minHeap;
	for(int num : nums)
	{
		minHeap.push(-num);
		if(minHeap.size() > k) minHeap.pop();
	}
	return -minHeap.top();
}


