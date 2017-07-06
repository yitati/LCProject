/***********************************************************************************
 * Question #560 Subarray Sum Equals K
 * Given an array of integers and an integer k, you need to find the total number of continuous
 * subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2

 * Note:
 * 1. The length of the array is in range [1, 20,000].
 * 2. The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7]
 ***********************************************************************************/

#include <vector>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k)
{
	int count = 0;
	int n = nums.size();
	vector<int> prefix(n, 0);
	for (int i = 0; i < n; i++) prefix[i] += nums[i] + (i == 0 ? 0 : prefix[i - 1]);
	unordered_map<int, int> sum; // map prefix sum with count of subarray
	sum[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (sum.count(prefix[i] - k)) count += sum[prefix[i] - k];
		sum[prefix[i]]++;
	}
	return count;
}



