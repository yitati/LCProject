/********************************************************************************************
 * Question # 368 Largest Divisible Subset
 * Given a set of distinct positive integers, find the largest subset such that every pair
 * (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 * If there are multiple solutions, return any subset is fine.
 * Example 1:
 * nums: [1,2,3]
 * Result: [1,2] (of course, [1,3] will also be ok)
 * Example 2:
 * nums: [1,2,4,8]
 * Result: [1,2,4,8]
 *
 ********************************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

/*
 * Solution: DP + Union Find
 * Very similari to LC 300 - longest increasing subsequence DP solution
 */
vector<int> largestDivisibleSubset(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), maxIdx = 0, maxLen = 0;
    vector<int> dp(n, 0);
    vector<int> parent(n, 0);
    for(int i=0; i<n; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(nums[i]%nums[j] == 0 && dp[j]+1 > dp[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
                parent[i] = j;
                if(dp[i] > maxLen)
                {
                    maxLen = dp[i];
                    maxIdx = i;
                }
            }
        }
    }
    vector<int> result;
    for(int i=0; i<maxLen; i++)
    {
        result.push_back(nums[maxIdx]);
        maxIdx = parent[maxIdx];
    }

    sort(result.begin(), result.end());
    return result;
}


