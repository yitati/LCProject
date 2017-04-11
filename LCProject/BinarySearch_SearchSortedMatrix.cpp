/*
Given a 2D matrix that contains integers only, which each row is sorted in an ascending order. 
The first element of next row is larger than (or equal to) the lastd element of previous row.
Given a target number, returning the position that the target locates within the matrix. 
If the target number does not exist in the matrix, return {-1, -1}.

Assumption:
- The given matrix is not null, and has size of N*M, where N >= 0 and M >= 0.

Examples:
- matrix = {{1, 2, 3}, {4, 5, 7}, {8, 9, 10}}
- target = 7, return {1, 2}
- target = 6, return {-1, -1} to represent the target number does not exist in the matrix.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchSortedMatrix(vector<vector<int>> & matrix, int target)
{
	vector<int> result(2, -1);
	int n = matrix.size(), m = matrix[0].size();
	int len = m*n;
	int lhs = 0, rhs = len-1;

	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		int r = mid / m, c = mid % m;
		if (target == matrix[r][c])
		{
			result[0] = r;
			result[1] = c;
			return result;
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

	return result;

}

/*
int main(int argc, char ** argv)
{
	// init a matrix
	int input[3][5] = { {1, 3, 5, 7, 9}, {11, 13, 15, 17, 19}, {21, 23, 25, 27, 29} };
	int m = 5, n = 3;
	vector<vector<int>> matrix(n, vector<int>(m));
	int r, c;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < m; c++)
		{
			matrix[r][c] = input[r][c];
		}
	}

	vector<int> search;
	search = searchSortedMatrix(matrix, 1);
	cout << search[0] << "   " << search[1] << endl;

	search = searchSortedMatrix(matrix, 29);
	cout << search[0] << "   " << search[1] << endl;

	search = searchSortedMatrix(matrix, 13);
	cout << search[0] << "   " << search[1] << endl;

	search = searchSortedMatrix(matrix, 26);
	cout << search[0] << "   " << search[1] << endl;

	system("pause");
}
*/