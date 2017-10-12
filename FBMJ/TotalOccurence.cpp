/*
 * MianJing: Total Occurrence of Target
 * company tag: Facebook, eBay
 * Given a target number and an integer array sorted in ascending order. Find the total number of
 * occurrence of target in the array.

Example
Given [1, 3, 3, 4, 5] and target = 3, return 2.+

Given [2, 2, 3, 4, 6] and target = 4, return 1.
Given [1, 2, 3, 4, 5] and target = 6, return 0.

 */

// one idea is to find one occurrence of the number and scan to left and right.

// But since the worst case of scan can be O(n) so it is better to do two binary search.
// Find the first occurrence and the last occurrence and then return the length.
#include <iostream>
#include <vector>

using namespace std;

// binary search for the first occurrence of the target
int binarySearchFindFirstOccurrence(vector<int>& nums, int lhs, int rhs, int target)
{
	if(lhs >= rhs) return -1;
	while(lhs + 1 < rhs) // termination condition is lhs neibors rhs
	{
		int mid = lhs + (rhs-lhs)/2;
		if(nums[mid] == target) rhs = mid;
		else if(nums[mid] > target) rhs = mid;
		else lhs = mid;
	}
	if(nums[lhs] == target) return lhs;
	if(nums[rhs] == target) return rhs;
	return -1;
}

// binary search for the last occurrence of the target
int binarySearchFindLastOccurrence(vector<int>& nums, int lhs, int rhs, int target)
{
	if(lhs >= rhs) return -1;
	while(lhs + 1 < rhs)  // termination condition is lhs neibors rhs
	{
		int mid = lhs + (rhs - lhs)/2;
		if(nums[mid] == target) lhs = mid;
		else if(nums[mid] < target) lhs = mid;
		else rhs = mid;
	}
	if(nums[rhs] == target) return rhs;
	if(nums[lhs] == target) return lhs;
	return -1;
}

// if we don't find the element at all, then return 0
int getTotalOccurrence(vector<int> input, int target)
{
	int start = binarySearchFindFirstOccurrence(input, 0, input.size()-1, target);
	if(start == -1) return 0;
	int end = binarySearchFindLastOccurrence(input, 0, input.size()-1, target);
	if(end == -1) return 0;
	return end-start+1;
}

/*
int main(int argc, char ** argv)
{
	vector<int> input = {2, 3, 4, 5, 5, 5, 7};
	cout << getTotalOccurrence(input, 5) << endl;
}
*/






