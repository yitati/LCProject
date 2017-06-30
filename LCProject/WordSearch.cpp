/******************************************************************************/
/*
* Question: #79 Word Search
* Given a 2D board and a word, find if the word exists in the grid.

* The word can be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/
/*****************************************************************************/

#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool existChar(vector<vector<char>> & board, string word, int level, int r, int c, vector<vector<int>> & visited)
{
	if (level == word.size() - 1 && board[r][c] == word[level]) return true;

	if (board[r][c] != word[level]) return false;

	for (int k = 0; k < 4; k++)
	{
		int x = r + dx[k];
		int y = c + dy[k];
		if (x < 0 || x >= board.size()) continue;
		if (y < 0 || y >= board[0].size()) continue;
		if (visited[x][y] == 1) continue;
		visited[x][y] = 1;
		if (existChar(board, word, level + 1, x, y, visited)) return true;
		visited[x][y] = 0;
	}

	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	if (board.size() == 0 || board[0].size() == 0) return false;

	vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == word[0])
			{
				visited[i][j] = 1;
				if (existChar(board, word, 0, i, j, visited)) return true;
				visited[i][j] = 0;
			}
		}
	}
	return false;
}
