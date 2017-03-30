/******************************************************************************/
/*
* Question: #130 Surrounded Regions
* Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
* A region is captured by flipping all 'O's into 'X's in that surrounded region. 
For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be: 
X X X X
X X X X
X X X X
X O X X
*/
/*****************************************************************************/

#include <vector>
#include <queue>

using namespace std;

// BFS solution


// DFS solution - abunduned
// mark 'Y' for all 'O's that can be changed to 'X'
// mark 'N' for all 'O's that cannot be changed to 'X'
void surround_dfs(vector<vector<char>> & board, int i, int j)
{
	if (board[i][j] == 'O')
	{
		board[i][j] = 'N';
		if (i>1) surround_dfs(board, i - 1, j);
		if (i + 1 < board.size()) surround_dfs(board, i + 1, j);
		if (j>1) surround_dfs(board, i, j - 1);
		if (j + 1 < board[0].size()) surround_dfs(board, i, j + 1);
	}
}

void solve(vector<vector<char>>& board)
{
	if (board.size() == 0 || board[0].size() == 0) return;
	int row = board.size(), col = board[0].size();
	// from four edges start looking for those 'O's that cannot be marked as 'X'
	// the first row and last row
	for (int j = 0; j < col; j++)
	{
		surround_dfs(board, 0, j);
		if (row > 1) surround_dfs(board, row - 1, j);
	}

	// the first col and last col
	for (int i = 1; i < row - 1; i++)
	{
		surround_dfs(board, i, 0);
		if (col > 1) surround_dfs(board, i, col - 1);
	}
	// change all the remaining 'O' to 'X'
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'O') board[i][j] = 'X';
			else if (board[i][j] == 'N') board[i][j] = 'O';
		}
	}
}