/******************************************************************************/
/*
* Question: #118 Pascal's Triangle
* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/
/*****************************************************************************/

#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> results(numRows);
	for (int i = 0; i<numRows; i++)
	{
		results[i].resize(i + 1);
		results[i][0] = results[i][i] = 1;
		for (int j = 1; j<i; j++)
		{
			results[i][j] = results[i - 1][j - 1] + results[i - 1][j];
		}
	}
	return results;
}