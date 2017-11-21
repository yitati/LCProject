/******************************************************************************/
/*
* Question: #343 Integer Break
* Given a positive integer n, break it into the sum of at least two positive integers and 
* maximize the product of those integers. Return the maximum product you can get. 
* For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4). 
* Note: You may assume that n is not less than 2 and not larger than 58. 
* Hint:
* 1.There is a simple O(n) solution to this problem.
* 2.You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int integerBreak(int n)
{
	vector<int> dp(n + 1, 1);
	dp[0] = 0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j<i; j++)
		{
			dp[i] = max(dp[i], max(j, dp[j]) * (i - j));
		}
	}
	return dp[n];
}