/******************************************************************************/
/**
* Question: #209 Minimum Size Subarray Sum
* Given an array of n positive integers and a positive integer s, 
* find the minimal length of a contiguous subarray of which the sum ≥ s. 
* If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.
*
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// O(n) solution
int minSubArrayLength(int s, vector<int>& nums) 
{
	int n = nums.size(), minLen = INT_MAX;
	int lhs = 0, rhs = 0, sum = 0;
	while (rhs < n)
	{
		sum += nums[rhs];
		while (sum >= s)
		{
			minLen = min(minLen, rhs - lhs + 1);
			sum -= nums[lhs++];
		}
		rhs++;
	}
	return minLen == INT_MAX ? 0 : minLen;
}


// O(nlogn) solution

int findEnd(vector<int> & preSum, int start, int target)
{
	int lhs = start, rhs = preSum.size() - 1;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (preSum[mid] >= target) rhs = mid - 1;
		else lhs = mid + 1;
	}
	if (preSum[lhs] >= target) return lhs;
	return preSum.size() + 1;
}

int minSubArrayLen_BinarySearch(int s, vector<int>& nums)
{
	if (nums.empty()) return 0;
	int len = nums.size(), minLen = len + 1;
	vector<int> preSum(len);
	// construct the prefix sum array
	for (int i = 0; i<nums.size(); i++)
	{
		preSum[i] += nums[i];
		if (i > 0) preSum[i] += preSum[i - 1];
	}
	// find proper index
	for (int i = 0; i<nums.size(); i++)
	{
		int target = i == 0 ? s : s + preSum[i - 1];
		int idx = findEnd(preSum, i, target);
		if (idx >= nums.size()) continue;
		minLen = min(minLen, idx - i + 1);
	}
	return minLen <= len ? minLen : 0;
}
