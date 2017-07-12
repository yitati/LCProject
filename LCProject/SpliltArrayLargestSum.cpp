/*****************************************************************************************
 * Question #410 Split Array Largest Sum
 * Given an array which consists of non-negative integers and in integer m, you can split the array
 * into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum amoung these
 * m subarrays.
 * Note:
 * If n is the length of array, assume the following constrains are satisfied:
 * 1 <= n <= 1000
 * 1 <= m <= min(50, n)

Examples:
Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

 *****************************************************************************************/

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// this is a 2D dp problem, suppose dp[i][k] is the minimum subarray sum of cutting nums[0, i] into k pieces
// then we can get
// dp[j][k] = min(dp[j][k], max(dp[i][k-1], sum_of_range(i+1, j)))
// in which k~[0, m] and i~[0, j]
int splitArray(vector<int>& nums, int m)
{
	// since we always need to get range sum, so we use a vector of to store prefix sum
	int n = nums.size();
	vector<int> prefixSum(n);
	for(int i=0; i<n; i++) prefixSum[i] = (i == 0 ? 0 : prefixSum[i-1]) + nums[i];
	vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = nums[0];
	for(int j=1; j<n; j++)
	{
		dp[j][0] = prefixSum[j];
		for(int i=0; i<j; i++)
		{
			for(int k=1; k < m; k++)   // divide into k pieces, so upper bound should be m or j-1
			{
                if(dp[i][k-1] == INT_MAX) break;  // this means [0, i] cannot be divided into k-1 group
				dp[j][k] = min(dp[j][k], max(dp[i][k-1], prefixSum[j] - prefixSum[i]));
			}
		}
	}
	return dp[n-1][m-1];
}

