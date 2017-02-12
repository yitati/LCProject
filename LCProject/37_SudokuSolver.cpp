/******************************************************************************/
/*
* Question: #37 Soduku Solver
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* Empty cells are indicated by the character '.'.
* You may assume that there will be only one unique solution.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

//dfs and back tracking - try to fill a number, check if it is valid

// a helper function to judge if board[i][j] = x is valid in current situation
bool isValid(vector<vector<char>> & board, char x, int r, int c)
{
	for (int i = 0; i < board.size(); i++)
	{
		if ((board[r][i] == x) || (board[i][c] == x) || (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == x))return false;
	}
	return true;
}


bool solveSudoku_dfs(vector<vector<char>> & board, int idx)
{
	int len = board.size();
	if (idx == len * len) return true;
	int r = idx / len, c = idx % len;
	if (board[r][c] == '.')
	{
		for (char x = '1'; x <= '9'; x++)
		{
			if (!isValid(board, x, r, c)) continue;
			board[r][c] = x;
			if (solveSudoku_dfs(board, idx + 1)) return true;
			else board[r][c] = '.';
		}
		return false;
	}
	return solveSudoku_dfs(board, idx + 1);
}


void solveSudoku(vector<vector<char>>& board)
{
	if (board.size() == 0 || board[0].size() == 0) return;
	int len = board.size();
	solveSudoku_dfs(board, 0);
}