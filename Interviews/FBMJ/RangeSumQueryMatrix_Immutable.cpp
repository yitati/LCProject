/******************************************************************************
* Question: #304 Range Sum Query 2D - Immutable
* company tag: Facebook
* Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) 
* and lower right corner (row2, col2).
* The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:

Given matrix = [
[3, 0, 1, 4, 2],
[5, 6, 3, 2, 1],
[1, 2, 0, 1, 5],
[4, 1, 0, 1, 7],
[1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12


* Note:
* 1.You may assume that the matrix does not change.
* 2.There are many calls to sumRegion function.
* 3.You may assume that row1 ≤ row2 and col1 ≤ col2.
*****************************************************************************/

#include <vector>

using namespace std;

class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix)
	{
		if (matrix.empty() || matrix[0].empty()) return;
		m_sumTable = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

		for (int i = 1; i <= matrix.size(); i++)
		{
			for (int j = 1; j <= matrix[0].size(); j++)
			{
				m_sumTable[i][j] = m_sumTable[i - 1][j] + m_sumTable[i][j - 1] - m_sumTable[i - 1][j - 1] + matrix[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return m_sumTable[row2 + 1][col2 + 1] - m_sumTable[row1][col2 + 1] - m_sumTable[row2 + 1][col1] + m_sumTable[row1][col1];
	}

	vector<vector<int>> m_sumTable;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
