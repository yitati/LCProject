/******************************************************************************
* Question: #74 Search a 2D Matrix
* company tag: LinkedIn
* Write an efficient algorithm that searches for a value in an m x n matrix.
* This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

*****************************************************************************/

#include <vector>

using namespace std;

bool searchMatrixI(vector<vector<int>>& matrix, int target) 
{
	int n = matrix.size(), m = matrix[0].size();
	int len = m*n;
	int lhs = 0, rhs = len - 1;

	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		int r = mid / m, c = mid % m;
		if (target == matrix[r][c])
		{
			return true;
		}
		else if (target < matrix[r][c])
		{
			rhs = r*m + c - 1;
		}
		else
		{
			lhs = r*m + c + 1;
		}
	}

	return false;

}
