/**************************************************************************
 * Question 311. Sparse Matrix Multiplication
 * company tag: Facebook
 * Given two sparse matrics A and B, return the result of AB.
 * You may assume that A's column number is equal to B's row number.

Example:
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

 **************************************************************************/

#include <vector>

using namespace std;

// the brutal force idea may TLE
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B)
{
	int m = A.size(), n = B.size(), p = B[0].size();
	vector<vector<int>> result(m, vector<int>(p, 0));

	for(int r=0; r < m; r++)
	{
		for(int k=0; k<n; k++)
		{
			if(A[r][k] == 0) continue;  // sparse matrix, skip 0
			for(int c = 0; c < p; c++)
			{
				if(B[k][c] == 0) continue;
				result[r][c] += A[r][k] * B[k][c]; // sparse matrix, skip 0
			}
		}
	}
	return result;
}
