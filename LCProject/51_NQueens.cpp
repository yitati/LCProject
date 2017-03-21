/******************************************************************************/
/*
* Question: #51 N Queens
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate 
* a queen and an empty space respectively.

For example,
 There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void solveNQueens_dfs1(vector<vector<string>> & results, vector<string>& result, int row, int n)
{
	if (row == n)
	{
		results.push_back(result);
		return;
	}

	for (int j = 0; j < n; j++)
	{
		bool colOk = true;
		for (int i = 0; i < row; i++)
		{
			if (result[i][j] == 'Q' || (i + j - row >= 0 && result[i][i + j - row] == 'Q') || (j - i + row < n && result[i][j - i + row] == 'Q'))
			{
				colOk = false;
				break;
			}
		}
		if (colOk == false)
		{
			colOk = true;
			continue;
		}

		result[row][j] = 'Q';
		solveNQueens_dfs1(results, result, row + 1, n);
		result[row][j] = '.';
	}
}

// improved solution - use unordered map to optimize the search for col
void solveNQueens_dfs2(vector<vector<string>> & results, vector<string>& result, int row, int n, unordered_set<int> & column,
	unordered_set<int> & diag1, unordered_set<int> & diag2)
{
	if (row == n)
	{
		results.push_back(result);
		return;
	}

	for (int j = 0; j < n; j++)
	{
		bool colOk = true;
		if (column.count(j) || diag1.count(row + j) || diag2.count(row - j)) continue;
		result[row][j] = 'Q';
		column.insert(j);
		diag1.insert(row + j);
		diag2.insert(row - j);
		solveNQueens_dfs2(results, result, row + 1, n, column, diag1, diag2);
		result[row][j] = '.';
		column.erase(j);
		diag1.erase(row + j);
		diag2.erase(row - j);
	}
}

vector<vector<string>> solveNQueens(int n)
{
	vector<vector<string>> results;
	string line(n, '.');
	vector<string> result(n, line);
	unordered_set<int> column;
	unordered_set<int> diag1;
	unordered_set<int> diag2;
	solveNQueens_dfs2(results, result, 0, n, column, diag1, diag2);
	return results;
}