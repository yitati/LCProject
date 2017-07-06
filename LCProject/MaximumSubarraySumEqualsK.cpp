/***********************************************************************************************************
 * Question #325 Maximum Size Subarray Sum Equals k
 * Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
 * If there isn't one, return 0 instead.
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Given nums = [1, -1, 5, -2, 3], k = 3,
 return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:

Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

 *********************************************************************************************************/

// Similar to question #560 Subarray Sum Equals k, here we need to store only the first index of prefix sum

#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k)
{
	int n = nums.size(), maxLen = 0;
	vector<int> prefix(n, 0);
	for(int i=0; i<n; i++) prefix[i] = nums[i] + i==0 ? 0 : prefix[i-1];
	unordered_map<int, int> sum;
	sum[0] = -1;
	for(int i=0; i<n; i++)
	{
		if(sum.count(prefix[i]-k)) maxLen = max(maxLen, i-sum[prefix[i]-k]);
		if(!sum.count(prefix[i])) sum[prefix[i]] = i;
	}
	return maxLen;
}
