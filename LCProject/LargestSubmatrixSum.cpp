/*
***** Basic question is longest consecutive 1 **************
Given a matrix that contains integers, find the submatrix with the largest sum.
Return the sum of the submatrix.

Assumptions
The given matrix is not null and has size of M * N, where M >= 1 and N >= 1

Examples

{ {1, -2, -1, 4},

{1, -1,  1, 1},

{0, -1, -1, 1},

{0,  0,  1, 1} }

the largest submatrix sum is (-1) + 4 + 1 + 1 + (-1) + 1 + 1 + 1 = 7.
*/

// LC 304 Range Sum Query 2D - Immutable

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Solution 1 - best solution using max subarray sum
step 1 : Preprocessing - use for for loop to calculate the prefix-sum for each column - O(n^2)
step 2 : for for loop to take one upper row and one bottom row
		step 2.1 calculate the 1D - sum array by using prefix sum stored in matrix in step 1
		SUM[] = {S0, S1, S2 ...... S19} -> O(n)  
		step 2.2 use SUM[] as the input, and pass it to the helper function of "calculate max subarray sum" - O(n)
Time complexity :  Total time complexity is O(n^3)
*/

// helper function that calculates max subarray sum in O(N) time
// also a dp problem dp[i+1] = max(dp[i]+nums[i+1], num[i+1]) - can use two global to replace dp array
int maxSubarraySum(vector<int>& nums)
{
	if (nums.empty()) return 0;
	int maxCurr = nums[0], maxSum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		maxCurr = max(nums[i], maxCurr + nums[i]);
		maxSum = max(maxCurr, maxSum);
	}
	return maxSum;
}

int largest_subArraySumSolution(vector<vector<int>> matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;

	int maxSum = INT_MIN;
	for (int upper = 0; upper < matrix.size(); upper++)
	{
		vector<int> columnPrefix(matrix[0].size(), 0);
		for (int lower = upper; lower < matrix.size(); lower++)  // adding from upper to lower 
		{
			for (int col = 0; col < matrix[0].size(); col++)
			{
				columnPrefix[col] += matrix[lower][col];
			}
			maxSum = max(maxSum, maxSubarraySum(columnPrefix));
		}
	}
	return maxSum;
}

/*
Solution 2 - Use top left corner and bottom right corner
step 1: Preporcessing to calculate the square sum of each square ending at [i][j] to be the bottom right corner
		(this step calculate prefix sum of each row, and square sum [i][j] = prefixSum[i][j] + prefixSum[i-1][j])
step 2: for for for for loop to find top left corner and bottom right corner, then calculate the square
		M[r1][c1] - [r2][c2] = M[r2][c2] - M[r1-1][c2] - M[r2][c2-1] + M[r1-1][c1-1]
Time complexity : O(n^4)
*/

int largest_2CornerSolution(vector<vector<int>> matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	// preprocess the matrix - O(n^2)
	int row = matrix.size(), col = matrix[0].size();
	vector<vector<int>> squareSum(row+1, vector<int>(col+1, 0));
	int maxSquare = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			squareSum[i + 1][j + 1] = squareSum[i + 1][j] + squareSum[i][j + 1] - squareSum[i][j] +  matrix[i][j];
		}
	}
	// then choose two corners and calculate the max square sum
	for (int r1 = 0; r1 < row; r1++)
	{
		for (int c1= 0; c1 < col; c1++)
		{
			// [i][j] will be the top left corner
			for (int r2 = r1; r2 < row; r2++)
			{
				for (int c2 = c1; c2 < col; c2++)
				{
					int subsquare = squareSum[r2 + 1][c2 + 1] - squareSum[r1][c2 + 1] - squareSum[r2 + 1][c1] + squareSum[r1][c1];
					maxSquare = max(maxSquare, subsquare);
				}
			}
		}
	}
	return maxSquare;
}

