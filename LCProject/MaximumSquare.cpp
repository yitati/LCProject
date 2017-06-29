/******************************************************************************/
/*
* Question: #221 Maximum Square
* Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// use dp solution - use dp[i][j] to indicate the length of the side of the square supposing 
// matrix[i][j] being the right-bottom corner of the square
int maximalSquare(vector<vector<char>>& matrix) 
{
	if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
	int maxSquare = 0;
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (i == 0 || j == 0) dp[i][j] = matrix[i][j] - '0';
			else if (matrix[i][j] == '0') dp[i][j] = 0;
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			maxSquare = max(maxSquare, dp[i][j] * dp[i][j]);
		}
	}
	return maxSquare;
}