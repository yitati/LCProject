/********************************************************************************
 * Question #498 Diagonal Traverse
 * Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix
 * in diagonal order as shown in the below image.
Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]

 * Note:
 * The total number of elements of the given matrix will no exceed 10,000.
 **********************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& matrix)
{
	if(matrix.empty() || matrix[0].empty()) return {};
	// directions of the diagonal
	int dirs[2][2] = {{-1, 1}, {1, -1}};
	vector<int> dOrder;
	int row = matrix.size(), col = matrix[0].size(), i = 0, j = 0, k = 0;
	while(dOrder.size() < row * col)
	{
		dOrder.push_back(matrix[i][j]);
		i += dirs[k][0];
		j += dirs[k][1];
		if(i >= 0 && i < row && j >= 0 && j < col) continue;
		k = 1-k; //turn around
		if(i >= row)
		{
			i = row-1;
			j += 2;
		}
		else if(j >= col)
		{
			j = col-1;
			i += 2;
		}
		else if(i < 0) i = 0;
		else if(j < 0) j = 0;
	}
	return dOrder;
}

/*
int main(int argc, char ** argv)
{
	int n = 3;
	vector<vector<int>> matrix(n, vector<int>(n));
	int val = 1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			matrix[i][j] = val;
			val++;
		}
	}

	vector<int> dOrder = findDiagonalOrder(matrix);

	for(int i=0; i<dOrder.size(); i++)
	{
		cout << dOrder[i] << "  ";
	}
	cout << endl;
}
*/




