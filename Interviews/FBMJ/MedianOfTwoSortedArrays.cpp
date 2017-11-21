/*
 * MedianOfTwoSortedArrays.cpp
 *
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

#include <vector>
#include <climits>

using namespace std;

int findKthElementInTwoSortedArray(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
{
  if(start1 >= nums1.size()) return nums2[start2 + k - 1];
  else if(start2 >= nums2.size()) return nums1[start1 + k - 1];
  else if(k == 1)  // k/2 = 0
  {
    return min(nums1[start1], nums2[start2]);
  }

//  if(start1 + k/2 - 1 >= nums1.size())
//  {
//    return findKthElementInTwoSortedArray(nums1, start1, nums2, start2 + k/2, k - k/2);
//  }
//  else if(start2 + k/2 - 1 >= nums2.size())
//  {
//    return findKthElementInTwoSortedArray(nums1, start1 + k/2, nums2, start2, k- k/2);
//  }
//  else if(nums1[start1 + k/2 -1] > nums2[start2 + k/2 - 1])
//  {
//    return findKthElementInTwoSortedArray(nums1, start1, nums2, start2 + k/2, k - k/2);
//  }
//  else{
//    return findKthElementInTwoSortedArray(nums1, start1 + k/2, nums2, start2, k- k/2);
//  }

  int mid1 = start1 + k/2 - 1 < nums1.size() ? nums1[start1 + k/2 - 1] : INT_MAX;
  int mid2 = start2 + k/2 - 1 < nums2.size() ? nums1[start2 + k/2 - 1] : INT_MAX;

  if(mid1 <= mid2)
  {
    return findKthElementInTwoSortedArray(nums1, start1 + k/2, nums2, start2, k-k/2);
  }
  else
  {
    return findKthElementInTwoSortedArray(nums1, start1, nums2, start2 + k/2, k-k/2);
  }

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
  int totolLen = nums1.size() + nums2.size();
  int mid1 = findKthElementInTwoSortedArray(nums1, 0, nums2, 0, totolLen/2);
  if(totolLen % 2 == 1)
  {
    return (double) mid1;
  }
  else
  {
    int mid2 = findKthElementInTwoSortedArray(nums1, 0, nums2, 0, totolLen/2 + 1);
    return 0.5 * (mid1 + mid2);
  }
}

/*
 * follow-up what about the median of k sorted array?
 * 题目是给定一个list of sorted integer arrays，要求找所有的数的median
 *
 */
