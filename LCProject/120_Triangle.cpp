/******************************************************************************/
/*
* Question: #120 Triangle
* Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

* Note:
* Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
/*****************************************************************************/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle)
{
	int n = triangle.size();
	int minSum = INT_MAX;
	vector<int> dp(n, 0);
	dp[0] = 0;
	for (int i = 0; i<n; i++)
	{
		int prev;
		for (int j = 0; j <= i; j++)
		{
			int tmp = dp[j];
			if (j == 0) dp[j] += triangle[i][j];
			else if (j == i) dp[j] = prev + triangle[i][j];
			else dp[j] = min(dp[j], prev) + triangle[i][j];
			prev = tmp;
		}
	}

	for (int i = 0; i<n; i++)
	{
		minSum = min(minSum, dp[i]);
	}

	return minSum;
}
