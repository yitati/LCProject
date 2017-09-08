/*
 * EBMJ_MinStepsTo1.cpp
 *

givin number N, get the minumun steps to reduce N to 1,
有效的operation是subtract by 1, div by 2, div by 3，能被2或3整除时才能用除法.

 */

#include <vector>
#include <climits>

using namespace std;
/*
 * this is a dp problem
 */
int minStepTo1(int num)
{
	vector<int> dp(num+1, INT_MAX);
	dp[0] = 0;
	dp[1] = 0;
	for(int i=2; i<=num; i++)
	{
		dp[i] = 1 + dp[i-1];
		if(i%2 == 0)
		{
			dp[i] = min(dp[i], dp[i/2]+1);
		}
		if(i%3 == 0)
		{
			dp[i] = min(dp[i], dp[i/3]+1);
		}
	}
	return dp[num];
}


