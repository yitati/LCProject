/*
Maximum Size Subarray Sum Equals k
Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
If there isn't one, return 0 instead.
只用返回boolen
 */

#include <vector>
#include <unordered_map>

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k)
{
	int nlen = nums.size();
	unordered_map<int, int> presum;
	presum[0] = -1;
	int maxLen = 0;

	int sum = 0;
	for(int i = 0; i < nlen; i++)
	{
		sum += nums[i];
		int comp = sum - k;
		if(presum.count(comp))
		{
			maxLen = max(maxLen, i - presum[comp]);
			// we can return true here if need to return boolean
		}
		if(!presum.count(sum))
		{
			presum[sum] = i;
		}
	}

	return maxLen;

}




