/*
***** Basic question is longest consecutive 1 **************
Given a matrix that contains only 1s and 0s, find the largest cross which contains only 1s, 
with the same arm lengths and the four arms joining at the central point.
Return the arm length of the largest cross.

Assumptions
The given matrix is not null, has size of N * M, N >= 0 and M >= 0.

Examples

{ {0, 0, 0, 0},

{1, 1, 1, 1},

{0, 1, 1, 1},

{1, 0, 1, 1} }

the largest cross of 1s has arm length 2.
*/

#include <algorithm>
#include <vector>

using namespace std;

class DirLength
{
public:
	int left;
	int right;
	int up;
	int down;
	DirLength() : left(0), right(0), up(0), down(0) {};
	int minlen() { return min(min(up, down), min(left, right)); }
};

int largestCross(vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	int row = matrix.size(), col = matrix[0].size();
	vector<vector<DirLength>> dp(row, vector<DirLength>(col));
	int maxCross = 0;
	// first we calculate up and left
	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			if (i == 0) dp[i][j].up = matrix[i][j];
			if (j == 0) dp[i][j].left = matrix[i][j];
			if (i > 0) dp[i][j].up = (matrix[i][j] == 1 ? dp[i - 1][j].up + 1 : 0);
			if (j > 0) dp[i][j].left = (matrix[i][j] == 1 ? dp[i][j - 1].left + 1 : 0);
		}
	}
	// then calculate the down and right
	for (int i = row - 1; i >= 0; i--)
	{
		for (int j = col - 1; j >= 0; j--)
		{
			if (i == row - 1) dp[i][j].down = matrix[i][j];
			if (j == col - 1) dp[i][j].right = matrix[i][j];
			if (i < row - 1) dp[i][j].down = (matrix[i][j] == 1 ? dp[i + 1][j].down + 1 : 0);
			if (j < col - 1) dp[i][j].right = (matrix[i][j] == 1 ? dp[i][j + 1].right + 1 : 0);
			maxCross = max(dp[i][j].minlen(), maxCross);
		}
	}

	return maxCross;

}