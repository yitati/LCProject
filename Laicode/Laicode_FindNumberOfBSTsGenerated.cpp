/*
 * Laicode_FindNumberOfBSTsGenerated.cpp
 *
Find the number of different Binary Search Trees generated from 1-n.

Example:

Input: 3, Return: 5
 */

#include <iostream>
#include <vector>

using namespace std;

// dp solution
int numOfTrees(int n)
{
	vector<int> dp(n+1, 0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j < i; j++)
		{
			dp[i] += dp[j] * dp[i-j-1];
		}
	}
	return dp[n];
}

/*
int main(int argc, char ** argv)
{
	cout << numOfTrees(3) << endl;
}
*/
