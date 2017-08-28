/******************************************************************************
* Question: #63 Unique Path II
* company tag: Facebook
* Follow up for "Unique Paths":

* Now consider if some obstacles are added to the grids. How many unique paths would there be?

* An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*****************************************************************************/

#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (m == 0 || n == 0) return 0;
    if (obstacleGrid[0][0] == 1) return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int j=1; j<m; j++)
    {
        if(obstacleGrid[0][j] == 1) break;
        else dp[0][j] = dp[0][j-1];
    }
    for(int i=1; i<n; i++)
    {
        if(obstacleGrid[i][0] == 1) break;
        else dp[i][0] = dp[i-1][0];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}
