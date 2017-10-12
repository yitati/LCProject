/******************************************************************************
* Question: #215 Kth Largest Element in an Array
* company tag: Facebook
* Find the kth largest element in an unsorted array. Note that it is the kth largest element 
* in the sorted order, not the kth distinct element. 

For example,
Given [3,2,1,5,6,4] and k = 2, return 5. 

* Note: 
* You may assume k is always valid, 1 ≤ k ≤ array's length.
*****************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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

/*
 * rainbow sort - average O(n) time, worst case O(n^2)
 */

int findKth_quickSelection(vector<int>& nums, int k, int lhs, int rhs)
{
	if(lhs > rhs) return -1;
	int mid = lhs + (rhs-lhs)/2;
	int target = nums[mid];
	// then the nums can be divided into three part
	int i = lhs, j = rhs, m = lhs;
	while(m <= j)
	{
		if(nums[m] < target)
		{
			swap(nums[i++], nums[m++]);
		}
		else if(nums[m] > target)
		{
			swap(nums[m], nums[j--]);
		}
		else m++;
	}

	if(k >= i+1 && k <= j+1) return nums[k-1];
	else if(k < i+1)
	{
		return findKth_quickSelection(nums, k, lhs, i-1);
	}
	else
	{
		return findKth_quickSelection(nums, k, j+1, rhs);
	}
}

int findKthLargest_QuickSelection(vector<int>& nums, int k)
{
	return findKth_quickSelection(nums, k, 0, nums.size()-1);
}

/*
int main(int argc, char ** argv)
{
	vector<int> nums = {2, 3, 6, 7, 3, 5, 1, 7, 2, 8};
	cout << findKthLargest_QuickSelection(nums, 100) << endl;
}
*/
