/******************************************************************************/
/*
* Question: #289 Game Of Life
* According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
* is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

* Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
* Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

* Any live cell with fewer than two live neighbors dies, as if caused by under-population.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by over-population..
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
* Write a function to compute the next state (after one update) of the board given its current state.

* Follow up:
* Could you solve it in-place? Remember that the board needs to be updated at the same time: 
* You cannot update some cells first and then use their updated values to update other cells.
* In this question, we represent the board using a 2D array. 
* In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. 
* How would you address these problems?
*/
/*****************************************************************************/

#include <vector>

using namespace std;

// state: 0   current state is 0 and next state is 0
// state: 1   current state is 1 and next state is 1
// state: -1  current state is 1 and next state is 0
// state: 2   current state is 0 and next state is 2

int getStat(vector<vector<int>> & board, int r, int c)
{
	int count = 0;
	// up
	if (r > 0 && (board[r - 1][c] == 1 || board[r - 1][c] == -1)) count++;
	// up left
	if (r > 0 && c > 0 && (board[r - 1][c - 1] == 1 || board[r - 1][c - 1] == -1)) count++;
	// up right
	if (r > 0 && c < board[0].size() - 1 && (board[r - 1][c + 1] == 1 || board[r - 1][c + 1] == -1)) count++;
	// left
	if (c > 0 && (board[r][c - 1] == 1 || board[r][c - 1] == -1)) count++;
	// right
	if (c < board[0].size() - 1 && (board[r][c + 1] == 1 || board[r][c + 1] == -1)) count++;
	// left bottom
	if (c > 0 && r < board.size() - 1 && (board[r + 1][c - 1] == 1 || board[r + 1][c - 1] == -1)) count++;
	// bottom
	if (r < board.size() - 1 && (board[r + 1][c] == 1 || board[r + 1][c] == -1)) count++;
	// right bottom
	if (c < board[0].size()-1 && r < board.size() - 1 && (board[r + 1][c + 1] == 1 || board[r + 1][c + 1] == -1)) count++;

	return count;
}

void gameOfLife(vector<vector<int>>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			int count = getStat(board, i, j);
			if (board[i][j] == 1)
			{
				if (count < 2 || count > 3) board[i][j] = -1;
			}
			if (board[i][j] == 0)
			{
				if (count == 3) board[i][j] = 2;
			}
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 2) board[i][j] = 1;
			if (board[i][j] == -1) board[i][j] = 0;
		}
	}
}