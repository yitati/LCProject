/*
 * Laicode_KthSmallestInTwoSortedArrays.cpp
 *

Given two sorted arrays of integers, find the Kth smallest number.

Assumptions

The two given arrays are not null and at least one of them is not empty

K >= 1, K <= total lengths of the two sorted arrays

Examples

A = {1, 4, 6}, B = {2, 3}, the 3rd smallest number is 3.

A = {1, 2, 3, 4}, B = {}, the 2nd smallest number is 2.

 */

#include <vector>
#include <climits>

using namespace std;

int findKthInTwoSortedArray(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
{
	if(start1 >= nums1.size()) return nums2[start2+k-1];
	if(start2 >= nums2.size()) return nums1[start1+k-1];

	if(k == 1) return min(nums1[start1], nums2[start2]);

	int mid1 = start1 + k/2 - 1 < nums1.size() ? nums1[start1 + k/2 -1] : INT_MAX;
	int mid2 = start2 + k/2 - 1 < nums2.size() ? nums2[start2 + k/2 -1] : INT_MAX;

	// be careful with the k-k/2
	if(mid1 < mid2)
	{
		return findKthInTwoSortedArray(nums1, start1 + k/2, nums2, start2, k - k/2);
	}
	else
	{
		return findKthInTwoSortedArray(nums1, start1, nums2, start2 + k/2, k - k/2);
	}
}


int kth(vector<int> a, vector<int> b, int k)
{
	return findKthInTwoSortedArray(a, 0, b, 0, k);
}

