/******************************************************************************/
/*
* Question: #52 N Queens II
* Follow up for N-Queens problem.
* Now, instead outputting board configurations, return the total number of distinct solutions.

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// improved solution - use unordered map to optimize the search for col
void totalNQueens_dfs(vector<string>& result, int row, int n, int & count,
	unordered_set<int> & column, unordered_set<int> & diag1, unordered_set<int> & diag2)
{
	if (row == n)
	{
		count++;
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
		totalNQueens_dfs(result, row + 1, n, count, column, diag1, diag2);
		result[row][j] = '.';
		column.erase(j);
		diag1.erase(row + j);
		diag2.erase(row - j);
	}
}

int totalNQueens(int n)
{
	string line(n, '.');
	vector<string> result(n, line);
	unordered_set<int> column;
	unordered_set<int> diag1;
	unordered_set<int> diag2;
	int count = 0;
	totalNQueens_dfs(result, 0, n, count, column, diag1, diag2);
	return count;
}