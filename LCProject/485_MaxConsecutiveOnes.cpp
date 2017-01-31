/******************************************************************************/
/*
* Question: #485 Max Consecutive Ones
* Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
Note:
The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int maxOnes = nums[0];
	vector<int> dp(nums.size(), 0);

	dp[0] = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == 1)
		{
			dp[i] = dp[i - 1] + 1;
			maxOnes = max(maxOnes, dp[i]);
		}
		else dp[i] = 0;
	}

	return maxOnes;
}